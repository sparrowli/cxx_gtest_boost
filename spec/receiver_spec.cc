#include "timestamp.h"
#include "receiver.h"
#include "gtest/gtest.h"

namespace {

class QuickTest : public testing::Test {
 protected:
  virtual void SetUp() {
		start_time_ = time(NULL);
	}
  virtual void TearDown() {
		const time_t end_time = time(NULL);
		
		EXPECT_TRUE(end_time - start_time_ <= 1) << "The test took too long.";
	}

	// The UTC time in seconds when the test starts
	time_t start_time_;
};

class ReceiverSpec : public QuickTest {
 protected:

  virtual void SetUp() {
    forecastr_initialized_ = false;
  }
  uint64_t timestamp( void ) {
    return frozen_timestamp();
  }

  Receiver forecastr_;

  bool forecastr_initialized_;

  Sprout::DeliveryForecast forecast( void ) { 
    forecastr_.advance_to( timestamp() ); 
    return forecastr_.forecast(); 
  }

};

TEST_F(ReceiverSpec, RecvPacket2UpdateSprout) {

  if ( !forecastr_initialized_ ) {
    forecastr_.wrap_to( timestamp() );
    forecastr_initialized_  = true;
  }

  const uint64_t seq = 0;
  const uint16_t throwaway_window = 1;
  const uint16_t time_to_next = 1;
  const size_t len = 1400;
  forecastr_.advance_to( timestamp() );
  forecastr_.recv(seq, throwaway_window, time_to_next, len);
}
}  // namespace
