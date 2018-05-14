
#include "Product.cpp"
struct ProductFilter {
	typedef vector<Product*> Items;

	// This kind of method filter exposes ProductFilter to be open in modification
	static Items by_value(Items items, Value value) {
		Items result;

		for (auto& item : items) {
			if (item->value == value) {
				result.push_back(item);
			}
		}
		return result;
	}
};