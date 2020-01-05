#include "SineEquation.h"
#include <math.h>

SineEquation::SineEquation() {}
SineEquation::~SineEquation() {}

double SineEquation::Evaluate() const {
	float temp = GetTime();

	switch(this->ease) {
	case EasingType::IN:
		return -cos(temp * (M_PI/2)) + 1.0f;
	case EasingType::OUT:
		return sin(temp * (M_PI/2));
	case EasingType::IN_OUT:
		return -0.5f * (cos(M_PI*temp) - 1.0f);
	default:
		return 0;
	}
}