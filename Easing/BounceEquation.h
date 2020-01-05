#pragma once
#include "easingequation.h"

class BounceEquation : public EasingEquation {
public:
	BounceEquation();
	virtual ~BounceEquation();
	virtual double Evaluate() const;

private:
	double evalEaseIn(float temp) const;
	double evalEaseOut(float temp) const;
};
