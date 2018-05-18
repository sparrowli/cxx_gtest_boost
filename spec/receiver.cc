#include "receiver.h"

#include <fcntl.h>
#include <unistd.h>

Receiver::Receiver()
  : process_(MAX_ARRIVAL_RATE,
       BROWNIAN_MOTION_RATE,
			 OUTAGE_ESCAPE_RATE, 
			 NUM_BINS), 
    forecastr_(),
		time_(0),
		score_time_(-1),
		count_this_tick_(0),
		cached_forecast_(),
		recv_queue_() {

  char *filename_in = getenv( "SPROUT_MODEL_IN" );
  if ( filename_in ) {
    /* try to open */
    int fd = open( filename_in, O_RDONLY );
    if ( fd < 0 ) {
      fprintf( stderr, "Could not open %s.\n", filename_in );
      perror( "open" );
      exit( 1 );
    }

    fprintf( stderr, "Reading model from %s...", filename_in );

    Sprout::SproutModel model;
    if ( !model.ParseFromFileDescriptor( fd ) ) {
      fprintf( stderr, "Could not parse %s.\n", filename_in );
      exit( 1 );
    }

    assert( model.intervals_size() == NUM_TICKS );

    for ( int i = 0; i < NUM_TICKS; i++ ) {
      fprintf( stderr, "[tick %d", i );
      ProcessForecastInterval one_forecast( model.intervals( i ) );
      forecastr_.push_back( one_forecast );
      fprintf( stderr, "] " );
    }
    fprintf( stderr, " done.\n" );

    if ( close( fd ) < 0 ) {
      perror( "close" );
      exit( 1 );
    }
  } else {
    fprintf( stderr, "Starting statistical calculations..." );
    for ( int i = 0; i < NUM_TICKS; i++ ) {
      fprintf( stderr, "[tick %d", i );
      ProcessForecastInterval one_forecast( .001 * TICK_LENGTH,
					    process_,
					    MAX_ARRIVALS_PER_TICK,
					    i + 1 );
      forecastr_.push_back( one_forecast );
      fprintf( stderr, "] " );
    }
    fprintf( stderr, " done.\n" );
  }

  char *filename_out = getenv( "SPROUT_MODEL_OUT" );
  if ( filename_out ) {
    /* try to open */
    int fd = open( filename_out, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR );
    if ( fd < 0 ) {
      fprintf( stderr, "Could not open %s.\n", filename_out );
      perror( "open" );
      exit( 1 );
    }

    fprintf( stderr, "Writing model to %s...", filename_out );
  
    Sprout::SproutModel model;
    for ( int i = 0; i < NUM_TICKS; i++ ) {
      auto *x = model.add_intervals();
      *x = forecastr_.at( i ).to_protobuf();
    }
    
    if ( !model.SerializeToFileDescriptor( fd ) ) {
      fprintf( stderr, "Could not serialize model.\n" );
      exit( 1 );
    }

    if ( close( fd ) < 0 ) {
      perror( "close" );
      exit( 1 );
    }

    fprintf( stderr, "done.\n" );
  }
}

void Receiver::advance_to(const uint64_t time) {
  assert(time >= time_);

  while ( time_ + TICK_LENGTH < time ) {
    process_.evolve(.001 * TICK_LENGTH); 
    if ( (time_ >= score_time_) || (count_this_tick_ > 0) ) {
      int discrete_observe = int( count_this_tick_ + 0.5);
      if (count_this_tick_ > 0 && count_this_tick_ < 1) {
        discrete_observe = 1;
      }
      
      process_.observe(.001 * TICK_LENGTH, discrete_observe);
      // fprintf( stderr, "tick(%f) ", count_this_tick_ );
      count_this_tick_ = 0;
    } else {
      // fprintf( stderr, "-SKIP-" );
    }
    time_ += TICK_LENGTH;
  }
}

void Receiver::recv(const uint64_t seq, const uint16_t throwaway_window,
                    const uint16_t time_to_next, const size_t len) {
  count_this_tick_ += len / 1400.0;
  recv_queue_.recv(seq, throwaway_window, len);
  score_time_ = std::max( time_ + time_to_next, score_time_ );
}

Sprout::DeliveryForecast Receiver::forecast(void) {
  if (cached_forecast_.time() == time_) {
    return cached_forecast_;
  } else {
    std::vector<int> counts;
    process_.normalize();
    cached_forecast_.set_received_or_lost_count(recv_queue_.packet_count());
    cached_forecast_.set_time(time_);
    cached_forecast_.clear_counts();

    for (auto it = forecastr_.begin(); it != forecastr_.end(); ++it) {
      cached_forecast_.add_counts( it->lower_quantile(process_, 0.05));
    }

    return cached_forecast_;
  }
}

void Receiver::RecvQueue::recv(const uint64_t seq,
                               const uint16_t throwaway_window,
                               int len) {
  received_sequence_numbers_.push( PacketLen(seq, len) );
  throwaway_before_ = std::max(throwaway_before_, seq - throwaway_window);
}


uint64_t Receiver::RecvQueue::packet_count(void) {
  // returns cumulative count of bytes received or lost
  while ( !received_sequence_numbers_.empty() ) {
    if ( received_sequence_numbers_.top().seq_ < throwaway_before_) {
      received_sequence_numbers_.pop();
    } else {
      break;
    } 
  }

  std::priority_queue<PacketLen, std::deque<PacketLen>, PacketLen> copy(received_sequence_numbers_);

  int buffer_sum = 0;
  while ( !copy.empty() ) {
    buffer_sum += copy.top().len_;
    copy.pop();
  }

  return throwaway_before_ + buffer_sum;
}
