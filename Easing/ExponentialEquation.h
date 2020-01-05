#pragma once
#include "easingequation.h"

class ExponentialEquation : public EasingEquation {
public:
	ExponentialEquation();
	virtual ~ExponentialEquation();
	virtual double Evaluate() const;
};
