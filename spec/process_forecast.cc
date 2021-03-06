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
std::vector<double> ProcessForecastInterval::convolve(
      const std::vector<double>& old_count_probabilities,
			const std::vector<double>& this_tick) {
  std::vector<double> ret(old_count_probabilities.size()
                          + this_tick.size() - 1);

	for (size_t old_count = 0; old_count < old_count_probabilities.size(); ++old_count) {
    for (size_t new_count = 0; new_count < this_tick.size();++new_count) {
			ret[old_count + new_count] += old_count_probabilities[old_count] * this_tick[new_count];
		}
	}

	return ret;
}

ProcessForecastInterval::ProcessForecastInterval(const double tick_time,
              const Process& example,
							const unsigned int tick_upper_limit,
							const unsigned int num_ticks)
	: count_probability_() {

  // step 1: make the component processes
  std::vector<Process> components( ProcessForecastTick::make_components(example) ); 

	// step 2: make the tick forecast
	ProcessForecastTick tick_forecast(tick_time, example, tick_upper_limit);

	// step 3: for each component, integrate and evolve forward
	for (auto it = components.begin(); it != components.end(); ++it) {
    std::vector<double> this_component_count_probability(1, 1.0);

		for (size_t tick = 0; tick < num_ticks; ++tick) {
			// collect tick forecast
			std::vector<double> this_tick;

			for (size_t i = 0; i < tick_upper_limit; ++i) {
				it->normalize();
				this_tick.push_back( tick_forecast.probability(*it, i) );
			}

			// add to previous forecast
			this_component_count_probability = convolve(this_component_count_probability,
               this_tick); 

			// evolve forward
			it->evolve(tick_time);
		}

		count_probability_.push_back(this_component_count_probability); 

	}
}

ProcessForecastInterval::ProcessForecastInterval(
            const Sprout::ProcessForecastInterval& stored_model)
  : count_probability_() {
  for (int i = 0; i < stored_model.count_probabilities_size(); ++i) {
		std::vector<double> this_component_count_probability;
		for (int j = 0; j < stored_model.count_probabilities(i).count_probability_size(); ++j) {
			this_component_count_probability.push_back(
            stored_model.count_probabilities(i).count_probability(j));
		}
		count_probability_.push_back(this_component_count_probability);
	}
}

// exact same routine as for ProcessForecastTick!
double ProcessForecastInterval::probability(const Process& ensemble,
            unsigned int count) const {
	assert( ensemble.is_normalized() );
	assert( ensemble.pmf().size() == count_probability_.size() );
	assert( count_probability_.size() > 0 );

	assert( count < count_probability_[0].size() );

	double ret = ensemble.pmf().summation( count_probability_, count );

	if (ret > 1.0) {
		fprintf(stderr, "Error, prob = %f\n", ret);
		ret = 1.0;
	}

	return ret;
}


unsigned int ProcessForecastInterval::lower_quantile(const Process& ensemble, const double x) const {
  double sum = 0.0;

	for (size_t i = 0; i < count_probability_[0].size(); ++i) {
		sum += probability(ensemble, i);
		if (sum >= 1) {
			return i;
		}
	}

	return count_probability_[0].size() + 1;
}


Sprout::ProcessForecastInterval ProcessForecastInterval::to_protobuf() const {
  Sprout::ProcessForecastInterval ret;
  for (size_t i = 0; i < count_probability_.size(); ++i) {
		auto *this_component = ret.add_count_probabilities();
		for (size_t j = 0; j < count_probability_[i].size(); ++j) {
			this_component->add_count_probability( count_probability_[i][j] );
		}
	}	

	return ret;
}
