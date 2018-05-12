#include "process.h"

#include <boost/math/distributions/normal.hpp>
#include "mypoisson.h"

Process::Process(const double maximum_rate, const double brownian_motion_rate,
			 const double outage_escape_rate, const int bins)
  : probability_mass_function_(bins, maximum_rate, 0),
	  gaussian_(maximum_rate, bins * 128),
	  brownian_motion_rate_(brownian_motion_rate),
		outage_escape_rate_(outage_escape_rate),
		normalized_(false) {

  normalize();
}

void Process::evolve(const double time) {
	normalized_ = false;

	// initialize brownian motion
	double stddev = brownian_motion_rate_ * sqrt(time);
	gaussian_.calculate(stddev);

	// initialize new pmf
	SampledFunction new_pmf( probability_mass_function_ );
	new_pmf.for_each( [] (const double, double& value, const unsigned int) {
			  value = 0;
			} );

	const double zero_escape_probability = 1 - poissonpdf( time * outage_escape_rate_, 0);
	assert(zero_escape_probability >= 0);
	assert(zero_escape_probability <= 1.0);

	probability_mass_function_.for_each( [&]
			(const double old_rate, const double& old_prob, const unsigned int old_index) {
			  new_pmf.for_range(old_rate - 5 * stddev,
						              old_rate + 5 * stddev,
						[&]
						(const double new_rate, double& new_prob, const unsigned int new_index) {
						  double zfactor = 1.0;
							if (old_rate == 0) {
							  zfactor = (new_index != 0) ? zero_escape_probability : (1 - zero_escape_probability);
							}	

							double contribution = zfactor * old_prob
							                     * (gaussian_.cdf( new_pmf.sample_ceil(new_rate) - old_rate)
																			- gaussian_.cdf( new_pmf.sample_floor(new_rate) - old_rate) );

							assert( !boost::math::isnan( zfactor ) );
							assert( !boost::math::isnan( old_prob ) );
							assert( !boost::math::isnan( new_rate ) );
							assert( !boost::math::isnan( old_rate ) );
							assert( !boost::math::isnan( gaussian_.cdf(new_pmf.sample_ceil(new_rate) - old_rate)) );
							assert( !boost::math::isnan( gaussian_.cdf(new_pmf.sample_floor(new_rate) - old_rate)) );

							assert( contribution >= 0.0 );
							assert( contribution <= 1.0 );

							new_prob += contribution;
						});
			} );

	probability_mass_function_ = new_pmf;
}

void Process::normalize(void) {
	if (normalized_) {
		return;
	}

	double sum(0);

	// find the total
	probability_mass_function_.for_each([&sum]
			(const double, const double& value, const unsigned int) {
			  sum += value;
			});

	// normalize
	probability_mass_function_.for_each([&sum]
			(const double, double& value, const unsigned int) {
			  value /= sum;
			});

  normalized_ = true;
}

void Process::observe(const double time, const int counts) {
	normalized_ = false;

	// multiply by likelihood function
	probability_mass_function_.for_each( [&]
			( const double midpoint, double& value, 
			  const unsigned int index __attribute((unused)) ) {
			  value *= poissonpdf(midpoint * time, counts);
			} );
}


Process& Process::operator=(const Process& other) {
	probability_mass_function_ = other.probability_mass_function_;
	gaussian_ = other.gaussian_;
	
	normalized_ = other.normalized_;
	*(const_cast<double *>(&brownian_motion_rate_)) = other.brownian_motion_rate_;

	return *this;
}

void Process::set_certain(const double rate) {
	normalized_ = false;

	unsigned int index_to_hit = probability_mass_function_.index(rate);

	probability_mass_function_.for_each( [&] 
			(const double, double& value, const unsigned int index) {
			  if (index == index_to_hit) {
				  value = 1.0;
				} else {
				  value = 0.0;
				}
			} );

	normalize();

	assert( probability_mass_function_[rate] == 1.0 );
}

double Process::count_probability(const double time, const int counts) {
	double ret = 0.0;

	probability_mass_function_.for_each( [&]
			(const double rate, const double& rate_probability, const unsigned int) {
			  ret += rate_probability * poissonpdf(rate * time, counts);
			} );

	return ret;
}

Process::GaussianCache::GaussianCache(const double maximum_rate, 
	 const int bins)
  : cdf_(bins, maximum_rate, -maximum_rate),
	  stddev_(-1) {}	

void Process::GaussianCache::calculate(const double stddev) {
	if (stddev == stddev_) {
		return;
	}

	stddev_ = stddev;

	boost::math::normal diffdist(0, stddev_);

	cdf_.for_each( [&]
			(const double x, double& value, const unsigned int) {
			  value = boost::math::cdf(diffdist, x);
			} );
}	
