#pragma once
#include "EasingEquation.h"

class PolygonEquation : public EasingEquation {
public:
	PolygonEquation(int grade);
	virtual ~PolygonEquation();
	virtual double Evaluate() const;

private:
	int grade;
};
