#include "process_forecast.h"
#include "gtest/gtest.h"

#include <fcntl.h>

namespace {
static const double MAX_ARRIVAL_RATE = 1000;
static const double BROWNIAN_MOTION_RATE = 200;
static const double OUTAGE_ESCAPE_RATE = 1;
static const int NUM_BINS = 256;
static const int TICK_LENGTH = 20;
static const int MAX_ARRIVALS_PER_TICK = 30;
static const int NUM_TICKS = 8;

class ProcessForecastTickSpec : public testing::Test {
 protected:
  virtual void SetUp() {
		process_ = new Process(MAX_ARRIVAL_RATE,
				BROWNIAN_MOTION_RATE,
				OUTAGE_ESCAPE_RATE,
				NUM_BINS);
		tick_forecast_ = new ProcessForecastTick(.001 * TICK_LENGTH,
				*process_,
				MAX_ARRIVALS_PER_TICK);
		one_forecast_ = new ProcessForecastInterval(.001 * TICK_LENGTH,
				*process_,
				MAX_ARRIVALS_PER_TICK,
				1);

	}

	virtual void TearDown() {
		delete process_;
		delete tick_forecast_;
		delete one_forecast_;
	}
	void ReadSproutModelFromFileDescriptor() {
		char* filename_in = getenv("SPROUT_MODEL_IN");
		int fd = open(filename_in, O_RDONLY);
		if (fd < 0) {
			fprintf(stderr, "Could not open %s.\n", filename_in);
			perror("open");
			exit(1);
		}

		fprintf(stderr, "Reading model from %s...", filename_in);
		Sprout::SproutModel model;
		if (!model.ParseFromFileDescriptor(fd)) {
			fprintf(stderr, "Could not parse %s.\n", filename_in);
			exit(1);
		}

    for ( int i = 0; i < NUM_TICKS; i++ ) {
      fprintf( stderr, "[tick %d", i );
      ProcessForecastInterval one_forecast( model.intervals( i ) );
      forecastr_.push_back( one_forecast );
      EXPECT_EQ(NUM_BINS + 1, one_forecast.row());
      EXPECT_EQ(MAX_ARRIVALS_PER_TICK + 1, one_forecast.column());
      fprintf( stderr, "] " );
    }
		ASSERT_EQ(NUM_TICKS, model.intervals_size());
		fprintf( stderr, " done.\n" );

		if (close(fd) < 0) {
			perror("close");
			exit(1);
		}
	}

	void StatisticalCalculations() {
		fprintf(stderr, "Starting statistical calculations...");
		for (int i = 0; i < NUM_TICKS; ++i) {
			fprintf(stderr, "[tick %d", i);
			ProcessForecastInterval one_forecast(.001 * TICK_LENGTH,
					*process_,
					MAX_ARRIVALS_PER_TICK,
					i + 1);
			forecastr_.push_back(one_forecast);
      EXPECT_EQ(NUM_BINS + 1, one_forecast.row());
      EXPECT_EQ(MAX_ARRIVALS_PER_TICK + 1, one_forecast.column());
			fprintf(stderr, "] ");
		}
		fprintf(stderr, " done.\n");

		const char* filename_out = "./sprout_model_out.txt";
		if (filename_out) {
			fprintf( stderr, "Could not open %s.\n", filename_out );
			int fd = open(filename_out, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR );
			if (fd < 0) {

				perror("open");
				exit(1);
			}

			fprintf( stderr, "Writing model to %s...", filename_out );
			Sprout::SproutModel model;
			for (size_t i = 0; i < NUM_TICKS; ++i) {
				auto* x = model.add_intervals();
				*x = forecastr_[i].to_protobuf();
			}

			if ( !model.SerializeToFileDescriptor(fd) ) {
				fprintf(stderr, "Could not serialize model.\n");
				exit(1);
			}

			if ( close(fd) < 0 ) {
				perror("close");
				exit(1);
			}

			fprintf(stderr, " done.\n");
		}
	}

	Process* process_;
	ProcessForecastTick* tick_forecast_;
	std::vector< ProcessForecastInterval > forecastr_;
  ProcessForecastInterval* one_forecast_; 
};

TEST_F(ProcessForecastTickSpec, constructor) {
	EXPECT_EQ(NUM_BINS + 1, tick_forecast_->row());
	EXPECT_EQ(MAX_ARRIVALS_PER_TICK  + 1, tick_forecast_->column());
}

TEST_F(ProcessForecastTickSpec, intervalForecastCor) {
	EXPECT_EQ(NUM_BINS + 1, one_forecast_->row());
	EXPECT_EQ(MAX_ARRIVALS_PER_TICK, one_forecast_->column());
}

TEST_F(ProcessForecastTickSpec, DISABLED_WrittingSproutModel) {
	StatisticalCalculations();
	EXPECT_TRUE(false);
}

TEST_F(ProcessForecastTickSpec, ReadingSproutModel) {
  ReadSproutModelFromFileDescriptor();
}
}  // namespace
