#include "Product.cpp"
#include "ISpecification.cpp"
/*
Better filter that complies to Open-Closed SOLID principle. It is extensible while the class ProductFilter does not need
modification (closed to modification).
*/

template <typename T> struct IFilter {
	virtual vector<T*> filter(vector<T*> items, ISpecification<T>& spec) = 0;
};

struct BetterFilter : IFilter<Product> {
	typedef vector<Product*> Items;

	vector<Product*> filter(vector<Product*> items, ISpecification<Product>& specification) {
		Items result;

		for (auto& p : items) {
			if (specification.is_satisfied(p)) {
				result.push_back(p);
			}
		}

		return result;
	}
};