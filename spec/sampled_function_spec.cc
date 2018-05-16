#include "sampled_function.h"
#include "gtest/gtest.h"

#include <stdio.h>
namespace {
static const double MAX_ARRIVAL_RATE = 1000;
static const double BROWNIAN_MOTION_RATE = 200;
static const double OUTAGE_ESCAPE_RATE = 1;
static const int NUM_BINS = 256;
static const int TICK_LENGTH = 20;
static const int MAX_ARRIVALS_PER_TICK = 30;
static const int NUM_TICKS = 8;


TEST(SampledFunction, constructor) {
  const SampledFunction probability_mass_function(NUM_BINS, MAX_ARRIVAL_RATE, 0);

  EXPECT_EQ(0, probability_mass_function.index(-1));
  EXPECT_EQ(1, probability_mass_function.index(4));
  EXPECT_EQ(256, probability_mass_function.index(1000));
  EXPECT_EQ(257, probability_mass_function.size());
}


TEST(SampledFunction, DISABLED_from_bin_mid) {
	FILE* poisson_fd = fopen("./poisson.txt", "wt");
  const SampledFunction probability_mass_function(NUM_BINS, MAX_ARRIVAL_RATE, 0);
	for (int i = 0; i < probability_mass_function.size(); ++i) {
		fprintf(poisson_fd, "%d\t%f\t%f\n", i,  
				probability_mass_function.function_[i],
				probability_mass_function.from_bin_mid(i));

		/*
		printf("index=%d|value=%f|mid_point=%f\n", i,
				probability_mass_function.function_[i],
				probability_mass_function.from_bin_mid(i));
				*/
	}
	printf("bin_width=%f\n", probability_mass_function.bin_width_);
	fclose(poisson_fd);
	EXPECT_TRUE(false);
}
TEST(SampledFunction, normalized) {
  SampledFunction probability_mass_function(NUM_BINS, MAX_ARRIVAL_RATE, 0);
	double sum(0);

	auto glambda = [](auto a, auto&& b) { return a < b; };
  bool b = glambda(3, 3.14);

	EXPECT_TRUE(b);

  probability_mass_function.for_each( [&sum](const double, const double& value, const unsigned int) {
											  sum += value;
											} );
	
	EXPECT_EQ(257, sum);
	probability_mass_function.for_each( [&sum](const double, double& value, const unsigned int) {
											  value /= sum;
											} );
	EXPECT_EQ(1.0/257, probability_mass_function.function_[5]);
	/*
	for (int i = 0; i < probability_mass_function.size(); ++i) {

		printf("index=%d|value=%f|mid_point=%f\n", i,
				probability_mass_function.function_[i],
				probability_mass_function.from_bin_mid(i));
	}
	*/
	
	EXPECT_EQ(1000000, BIG);
}

TEST(SampledFunction, iterator) {
	EXPECT_TRUE(1);
}
}  // namespace
