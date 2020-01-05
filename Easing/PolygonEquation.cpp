#include "PolygonEquation.h"
#include <math.h>

PolygonEquation::PolygonEquation(int grade) : grade(grade) {}
PolygonEquation::~PolygonEquation() {}

double PolygonEquation::Evaluate() const {
	float temp = GetTime();

	switch(this->ease) {
	case EasingType::IN:
		return pow(temp, grade);
	case EasingType::OUT:
		return 1 - pow(1 - temp, grade);
	case EasingType::IN_OUT:
		if (temp < 0.5)
			return pow(temp, grade) * (1 << (grade - 1));
		return 1 - pow(1 - temp, grade) * (1 << (grade - 1));
	default:
		return 0;
	}
}
