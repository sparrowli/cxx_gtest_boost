#ifndef MIXERENGINE_INCLUDE_SPEC_SAMPLED_FUNCTION_H_
#define MIXERENGINE_INCLUDE_SPEC_SAMPLED_FUNCTION_H_
#include <vector>
#include <functional>
static double BIG = 1.e6;

class SampledFunction {
 public:
  SampledFunction(const int num_samples, const double maximum_value, 
                  const double minimum_value);
	size_t size(void) const { return function_.size(); }
	uint32_t index(const double x) const {return to_bin(x); }
	double& operator[](const double x) { return function_[to_bin(x)]; }
	const double& operator[](const double x) const { return function_[to_bin(x)]; }

	double sample_floor(double x) const { return from_bin_floor(to_bin(x)); }
	double sample_ceil(double x) const { return from_bin_ceil(to_bin(x)); }
  void for_each( const std::function<
			       void(const double midpoint,
             double& value,
             const unsigned int index) > f);
  
  void for_each( const std::function<
			       void(const double midpoint,
             const double& value,
             const unsigned int index) > f) const;

	void for_range(const double min, const double max,
			const std::function< void(const double midpoint,
			double& value,
			const unsigned int index)	> f);

	const SampledFunction & operator=( const SampledFunction & other );

	double lower_quantile(const double x) const;
	double summation(const std::vector< std::vector<double> >& count_probability, const int count) const;
 //private:
  const double offset_;
  const double bin_width_;
  std::vector<double> function_;

	unsigned int to_bin(double x) const {
		int ret = (x - offset_) / bin_width_;
		if (ret < 0) {
			return 0;
		} else if (ret >= (int)function_.size()) {
			return function_.size() - 1;
		} else {
			return ret;
		}
	}

	double from_bin_floor(unsigned int bin) const {
		if (bin <= 0) {
			return -BIG;
		} else {
			return bin * bin_width_ + offset_;
		}
	}

	double from_bin_ceil(unsigned int bin) const {
		if (bin >= function_.size() - 1) {
			return BIG;
		} else {
			return (bin + 1) * bin_width_ + offset_;
		}
	}

  double from_bin_mid(unsigned int bin) const {
    if (bin == 0) {
      return offset_;
    }

    return (bin + 0.5) * bin_width_ + offset_;
  }
 private:


};


#endif  // MIXERENGINE_INCLUDE_SPEC_SAMPLED_FUNCTION_H_
