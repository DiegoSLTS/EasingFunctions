#include "BounceEquation.h"

#include <math.h>

BounceEquation::BounceEquation() {}
BounceEquation::~BounceEquation() {}

double BounceEquation::Evaluate() const {
	float temp = GetTime();
	const float s = 1.70158f;
	const float s2 = s * 1.525f;

	switch(ease) {
	case EasingType::IN:
		return evalEaseIn(temp);
	case EasingType::OUT:
		return evalEaseOut(temp);
	case EasingType::IN_OUT:
		temp *= 2;
		if (temp < 1)
			return evalEaseIn(temp) * 0.5;
		return evalEaseOut(temp - 1) * 0.5 + 0.5f;
	default:
		return 0;
	}
}

double BounceEquation::evalEaseOut(float temp) const {
	if (temp < (1/2.75f)) {
		return (7.5625f * temp * temp);
	} else if (temp < (2/2.75f)) {
		temp -= (1.5f/2.75f);
		return (7.5625f * temp * temp + 0.75f);
	} else if (temp < (2.5/2.75)) {
		temp -= (2.25f/2.75f);
		return (7.5625f * temp * temp + 0.9375f);
	} else {
		temp -= (2.625f/2.75f);
		return (7.5625f * temp * temp + 0.984375f);
	}
}

double BounceEquation::evalEaseIn(float temp) const {
	return 1 - evalEaseOut(1 - temp);
}