#include "ExponentialEquation.h"
#include <math.h>

ExponentialEquation::ExponentialEquation() {}
ExponentialEquation::~ExponentialEquation() {}

double ExponentialEquation::Evaluate() const {
	float temp = GetTime();

	switch(this->ease) {
	case EasingType::IN:
		return pow( 2, 10 * (temp - 1) );
	case EasingType::OUT:
		return 1 - pow( 2, -10 * temp );
	case EasingType::IN_OUT:
		temp *= 2;
		if (temp < 1)
			return 0.5 * pow( 2, 10 * (temp - 1) );
		temp--;
		return 0.5 * ( -pow( 2, -10 * temp*2) + 2 );
	default:
		return 0;
	}
}
