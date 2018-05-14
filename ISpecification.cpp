#include "Product.cpp"

template <typename T> struct ISpecification {
	virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct And : ISpecification<T> {
	ISpecification<T>& first;
	ISpecification<T>& second;

	And(ISpecification<T>& first, ISpecification<T>& second) : first{ first }, second{ second } {

	}

	bool is_satisfied(T* item) override {
		return first.is_satisfied(item) && second.is_satisfied(item);
	}
};

struct ValueSpecification : ISpecification<Product> {
	Value value;

	explicit ValueSpecification(const Value value) : value{ value } {

	}

	bool is_satisfied(Product* item) override {
		return item->value == value;
	}
};

struct FragilitySpecification : ISpecification<Product> {
	Fragility fragility;

	explicit FragilitySpecification(const Fragility fragility) : fragility{ fragility } {

	}

	bool is_satisfied(Product* item) override {
		return item->fragility == fragility;
	}
};