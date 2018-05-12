#include "sampled_function.h"

#include <assert.h>

SampledFunction::SampledFunction(const int num_samples,
                                 const double maximum_value,
                                 const double minimum_value)
    : offset_(minimum_value),
      bin_width_( (maximum_value - minimum_value) / num_samples),
      function_( int((maximum_value - minimum_value) / bin_width_) + 1, 1.0) {}

void SampledFunction::for_each( const std::function<
        void(const double midpoint,
             double& value,
             const unsigned int index) > f) {
  for(uint32_t i = 0; i < function_.size(); ++i) {
    f(from_bin_mid(i), function_[i], i);
  }

}
void SampledFunction::for_each( const std::function<
        void(const double midpoint,
             const double& value,
             const unsigned int index) > f) const {
  for(uint32_t i = 0; i < function_.size(); ++i) {
    f(from_bin_mid(i), function_[i], i);
	}
}

void SampledFunction::for_range(const double min, const double max,
			const std::function< void(const double midpoint,
			double& value,
			const unsigned int index)	> f) {
	const unsigned int limit_high = to_bin(sample_ceil(max));
	for (size_t i = to_bin(sample_floor(min)); i <= limit_high; ++i) {
		f( from_bin_mid(i), function_[i], i);
	}
}

const SampledFunction& SampledFunction::operator=( const SampledFunction& other )
{
  assert( offset_ == other.offset_ );
  assert( bin_width_ == other.bin_width_ );
  function_ = other.function_;

  return *this;
}


double SampledFunction::lower_quantile(const double x) const {
	double sum = 0.0;
	for (size_t i = 0; i < function_.size(); ++i) {
		sum += function_[i];

		if (sum >= x) {
			if (i == 0) {
				return 0;
			} else {
				return from_bin_floor(i);
			}
		}
	}

	return from_bin_floor(function_.size() - 1);
}


double SampledFunction::summation(const std::vector< std::vector<double> >& count_probability, const int count) const {
	double ret = 0.0;
	for (size_t i = 0; i < function_.size(); ++i) {
		ret += function_[i] * count_probability[i][count];
	}
	return ret;
}
