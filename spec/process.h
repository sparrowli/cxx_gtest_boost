#ifndef MIXERENGINE_INCLUDE_SPEC_PROCESS_H_
#define MIXERENGINE_INCLUDE_SPEC_PROCESS_H_
#include "sampled_function.h"

class Process {
 public:
	 Process(const double maximum_rate, const double brownian_motion_rate,
			 const double outage_escape_rate, const int bins);

	 // make probability mass function sum to unity
	 void normalize(void);
	 
	 // apply brownian motion
	 void evolve(const double time);

	 // update from new observation
	 void observe(const double time, const int counts);

	 const SampledFunction& pmf(void) const { return probability_mass_function_; }

	 double lower_quantile(const double x) const { return probability_mass_function_.lower_quantile(x); }

	 bool is_normalized(void) const { return normalized_; }

	 Process& operator=(const Process& other);

	 // set rate to known quantiti
	 void set_certain(const double rate);
	 // count probability assuming no evolution
	 double count_probability(const double time, const int counts);
 private:
	 class GaussianCache {
		public:
		 GaussianCache(const double maximum_rate, const int bins);
		 void calculate(const double stddev);
		 double cdf(const double x) const { return cdf_[x]; }

		private:
		 SampledFunction cdf_;
		 double stddev_;
	 };
	 SampledFunction probability_mass_function_;
	 GaussianCache gaussian_;

	 // std deviation of difference after on second
	 const double brownian_motion_rate_;
	 // arrivals per second
	 const double outage_escape_rate_;;

	 bool normalized_;

};
#endif  // MIXERENGINE_INCLUDE_SPEC_PROCESS_H_
