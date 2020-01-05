#pragma once
#include "easingequation.h"

class ElasticEquation : public EasingEquation {
public:
	ElasticEquation();
	virtual ~ElasticEquation();
	virtual double Evaluate() const;
};
