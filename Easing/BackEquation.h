#pragma once
#include "easingequation.h"

class BackEquation : public EasingEquation {
public:
	BackEquation();
	virtual ~BackEquation();
	virtual double Evaluate() const;
};
