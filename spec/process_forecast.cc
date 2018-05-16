#include "process_forecast.h"

std::vector<Process> ProcessForecastTick::make_components(const Process& example) {
	std::vector<Process> components;

  example.pmf().for_each( [&]
			(const double mid_point, const double&, unsigned int index) {
			  Process component(example);
				component.set_certain(mid_point);
				assert(components.size() == index);
				assert(example.pmf().index(mid_point) == index);
				components.push_back(component);
			} );

	return components;
}

ProcessForecastTick::ProcessForecastTick(const double tick_time,
		const Process& example, const unsigned int upper_limit)
  : count_probability_() {

	std::vector<Process> components(make_components(example));

	for (auto it = components.begin(); it != components.end(); ++it) {
		std::vector<double> this_count_probability;
		double total = 0.0;

		for (size_t i = 0; i < upper_limit; ++i) {
			const double prob = it->count_probability(tick_time, i);
			assert(prob >= 0);
			assert(prob <= 1.0);
			this_count_probability.push_back(prob);
			total += prob;
		}

		assert(total < 1.0 + (1e-10));
		this_count_probability.push_back(1.0 - total);

		// append to cache
		count_probability_.push_back(this_count_probability);
	}

}


double ProcessForecastTick::probability(const Process& ensemble, unsigned int count) const {
	assert( ensemble.is_normalized() );
	assert( ensemble.pmf().size() == count_probability_.size() );
	assert( count_probability_.size() > 0 );
	assert( count < count_probability_[0].size() );

	double ret = ensemble.pmf().summation(count_probability_, count);
	assert( ret <= 1.0 + 1e-10 );

	if (ret > 1.0) {
		ret = 1.0;
	}

	return ret;
}
