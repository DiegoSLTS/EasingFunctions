#include "CircularEquation.h"

#include <math.h>

CircularEquation::CircularEquation() {}
CircularEquation::~CircularEquation() {}

double CircularEquation::Evaluate() const {
	float temp = GetTime();

	switch(this->ease) {
	case EasingType::IN:
		return - (sqrt(1 - temp * temp) - 1);
	case EasingType::OUT:
		temp--;
		return sqrt(1 - temp *temp);
	case EasingType::IN_OUT:
		temp *= 2;
		if (temp < 1)
			return -0.5 * (sqrt(1 - temp * temp) - 1);
		temp -= 2;
		return 0.5 * (sqrt(1 - temp * temp) + 1);
	default:
		return 0;
	}
}