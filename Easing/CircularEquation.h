#pragma once
#include "easingequation.h"

class CircularEquation : public EasingEquation {
public:
	CircularEquation();
	virtual ~CircularEquation();
	virtual double Evaluate() const;
};
