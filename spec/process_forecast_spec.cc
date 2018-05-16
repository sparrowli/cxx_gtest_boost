#include "process_forecast.h"
#include "gtest/gtest.h"

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


	}

	virtual void TearDown() {
		delete process_;
		delete tick_forecast_;
	}


	Process* process_;
	ProcessForecastTick* tick_forecast_;
};

TEST_F(ProcessForecastTickSpec, constructor) {
	EXPECT_EQ(NUM_BINS + 1, tick_forecast_->row());
	EXPECT_EQ(MAX_ARRIVALS_PER_TICK  + 1, tick_forecast_->column());
}
}  // namespace
