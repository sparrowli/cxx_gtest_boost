#ifndef MIXERENGINE_INCLUDE_SPEC_MY_POISSON_H_
#define MIXERENGINE_INCLUDE_SPEC_MY_POISSON_H_
#include <boost/math/distributions/poisson.hpp>

double poissonpdf(const double rate, int counts) {
	if (rate == 0) {
		return (counts == 0);
	} else {
		return boost::math::pdf( boost::math::poisson(rate), counts);
	}
}
#endif  // MIXERENGINE_INCLUDE_SPEC_MY_POISSON_H_
