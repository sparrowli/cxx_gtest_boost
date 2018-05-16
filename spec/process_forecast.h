#ifndef MIXERENGINE_INCLUDE_SPEC_PROCESS_FORECAST_H_
#define MIXERENGINE_INCLUDE_SPEC_PROCESS_FORECAST_H_

#include "process.h"

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

#endif  // MIXERENGINE_INCLUDE_SPEC_PROCESS_FORECAST_H_
