#ifndef UNITS_H
#define UNITS_H

#include "named_type.h"
#include "unit_operations.h"

namespace Tools {

using Length = NamedType<double, struct LengthParam, Addable>;
using Mass = NamedType<double, struct MassParam>;

class Inch : public Length {
public:
	Inch(double val) : Length(val) {}

}; 
class Meter : public Length {
public:
	Meter(double val) : Length(val) {}

}; 
class Pound : public Mass {
public:
	Pound(double val) : Mass(val) {}

}; 
class Kilo : public Mass {
public:
	Kilo(double val) : Mass(val) {}

}; 

using Weight = NamedType<Mass, struct MassParam>;
using Height = NamedType<Length, struct LengthParam>;

Inch operator "" _inch(long double value) {
	return Inch(value);
}

Meter operator ""_meter(long double value) {
	return Meter(value);
}

Pound operator ""_lb(long double value) {
	return Pound(value);
}

Kilo operator ""_kg(long double value) {
	return Kilo(value);
}
}

#endif 
