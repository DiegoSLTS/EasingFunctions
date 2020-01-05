#include "BackEquation.h"
#include <math.h>

BackEquation::BackEquation() {}
BackEquation::~BackEquation() {}

double BackEquation::Evaluate() const {
	float temp = GetTime();
	const float s = 1.70158f;
	const float s2 = s * 1.525f;

	switch(ease) {
	case EasingType::IN:
		return temp * temp * ((s + 1) * temp - s);
	case EasingType::OUT:
		temp--;
		return temp * temp * ((s + 1) * temp + s) + 1;
	case EasingType::IN_OUT:
		temp *= 2;
		if (temp < 1)
			return 0.5 * temp * temp * ((s2 + 1) * temp - s2);
		temp-=2;
		return 0.5 * (temp * temp * ((s2 + 1) * temp + s2) + 2);
	default:
		return 0;
	}
}
