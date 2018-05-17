#ifndef MIXERENGINE_INCLUDE_SPEC_PROCESS_FORECAST_H_
#define MIXERENGINE_INCLUDE_SPEC_PROCESS_FORECAST_H_

#include "process.h"
#include "sprout_math.pb.h"

class ProcessForecastTick {
 public:
	 ProcessForecastTick(const double tick_time, const Process& example, const unsigned int upper_limit);

	 double probability(unsigned int component, unsigned int count) const {
		 return count_probability_[component][count];
	 }

	 size_t row(void) const { return count_probability_.size(); }
	 size_t column(void) const { return count_probability_[0].size(); }
	 double probability(const Process& ensemble, unsigned int count) const;

	 static std::vector<Process> make_components(const Process& example);

 private:
	 std::vector< std::vector<double> > count_probability_;
};

class ProcessForecastInterval {
 public:
  ProcessForecastInterval(const double tick_time,
			   const Process& example,
				 const unsigned int tick_upper_limit,
				 const unsigned int num_ticks);
	Sprout::ProcessForecastInterval to_protobuf(void) const;
	 size_t row(void) const { return count_probability_.size(); }
	 size_t column(void) const { return count_probability_[0].size(); }
	double probability(const Process& ensemble, unsigned int count) const;
  unsigned int lower_quantile(const Process& ensemble, const double x) const;
 private:
	static std::vector<double> convolve(
      const std::vector<double>& old_count_probabilities,
      const std::vector<double>& this_tick);

	std::vector< std::vector<double> > count_probability_;
};
#endif  // MIXERENGINE_INCLUDE_SPEC_PROCESS_FORECAST_H_
