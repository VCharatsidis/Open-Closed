#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
#include <vector>

using std::vector;

enum class Value {very_cheap, cheap, medium, expensive, very_expensive};
enum class Volume {very_small, small, medium, big, very_big};
enum class Size {qubic, orthogonal, pyramid, trapezoid, sphere, random};
enum class Consentrated { not_at_all, little_concentrated, consentrated, very_consentrated};
enum class Fragility {low, medium, high};

struct Product {
	std::string name;

	Value value;
	Volume volume;
	Size size;
	Consentrated consentrated;
	Fragility fragility;
};

#endif







