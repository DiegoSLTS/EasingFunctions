#pragma once
#include "easingequation.h"

class SineEquation : public EasingEquation {
public:
	SineEquation();
	virtual ~SineEquation();
	virtual double Evaluate() const;
};
