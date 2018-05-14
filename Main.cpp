#include "Product.cpp";
#include "BetterFilter.cpp";

int main() {
	Product car{ "Car", Value::expensive, Volume::big, Size::orthogonal, Consentrated::little_concentrated, Fragility::medium };
	Product watch{ "Watch", Value::expensive, Volume::very_small, Size::sphere, Consentrated::consentrated, Fragility::high };
	Product apple{ "Apple", Value::very_cheap, Volume::very_small, Size::sphere, Consentrated::very_consentrated, Fragility::low };

	vector<Product*> all_products{ &car, &watch, &apple };

	BetterFilter filter;
	ValueSpecification expensive(Value::expensive);

	auto expensive_items = filter.filter(all_products, expensive);

	for (auto& x : expensive_items) {
		std::cout << x->name << " is expensive " << std::endl;
	}

	FragilitySpecification high(Fragility::high);

	And<Product> expensive_and_high_fragility{ expensive, high };

	auto expensive_and_high_fragility_products = filter.filter(all_products, expensive_and_high_fragility);
	for (auto product : expensive_and_high_fragility_products) {
		std::cout << product->name << " is expensive and high fragility" << std::endl;
	}

	/*
	There are many combinations of product features.
	Without implementing it according to Open-Closed we would need every time to modify the ProductFilter.
	Furthermore, we would need many methods to cover every combination.
	*/

	return 0;
}