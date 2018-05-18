#ifndef MIXERENGINE_INCLUDE_SPEC_RECEIVER_H_
#define MIXERENGINE_INCLUDE_SPEC_RECEIVER_H_

#include <queue>

#include "process.h"
#include "process_forecast.h"
#include "delivery_forecast.pb.h"

class Receiver {
 public:
  Receiver();
	void wrap_to(const uint64_t time) { score_time_ = time_ = time; }
	void advance_to(const uint64_t time);
	void recv(const uint64_t seq, const uint16_t throwaway_window,
            const uint16_t time_to_next, const size_t len);

	Sprout::DeliveryForecast forecast(void);

	int get_tick_length(void) const { return TICK_LENGTH; }
 private:
  static constexpr double MAX_ARRIVAL_RATE = 1000;
  static constexpr double BROWNIAN_MOTION_RATE = 200;
  static constexpr double OUTAGE_ESCAPE_RATE = 1;
  static const int NUM_BINS = 256;
  static const int TICK_LENGTH = 20;
  static const int MAX_ARRIVALS_PER_TICK = 30;
  static const int NUM_TICKS = 8;

  class RecvQueue {
   public:
    RecvQueue() : received_sequence_numbers_(), throwaway_before_(0) {}
    void recv(const uint64_t seq, const uint16_t throwaway_window, int len);
		uint64_t packet_count(void);
   private:
		class PacketLen {
     public:
      uint64_t seq_;
			int len_;
			bool operator()(const PacketLen& a, const PacketLen& b) const {
				return a.seq_ > b.seq_;
			}

			PacketLen(const uint64_t seq, const int len)
        : seq_(seq),
          len_(len) {}
			PacketLen(void)
        : seq_(-1),
          len_(0) {}
		};
    std::priority_queue<PacketLen, std::deque<PacketLen>, PacketLen> received_sequence_numbers_;
    uint64_t throwaway_before_;
	};
  Process process_;

  std::vector<ProcessForecastInterval> forecastr_;

	uint64_t time_;
	uint64_t score_time_;
	double count_this_tick_;

	Sprout::DeliveryForecast cached_forecast_;

	RecvQueue recv_queue_;
};

#endif  // MIXERENGINE_INCLUDE_SPEC_RECEIVER_H_
