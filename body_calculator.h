#ifndef BODY_CALCULATOR_H
#define BODY_CALCULATOR_H

#include <iostream>

#include "units.h"

using namespace Tools; 

class Calculator {

public:
	static float calculateIBM(Weight w, Height h);
};

float Calculator::calculateIBM(Weight w, Height h) {
	return w.get().get() * h.get().get(); 
}

#endif 
