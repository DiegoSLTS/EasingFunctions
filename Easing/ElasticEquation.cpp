#include "ElasticEquation.h"
#include <math.h>

ElasticEquation::ElasticEquation() {}
ElasticEquation::~ElasticEquation() {}

double ElasticEquation::Evaluate() const {
	float temp = GetTime();
	const float s = 1.70158f;
	const float s2 = s * 1.525f;

	switch(this->ease) {
	case EasingType::IN: {
		if (currentTime == 0)
			return 0;

		if (temp == 1)
			return 1;

		float p = duration*.3f;
		float s = p/4;
		temp--;
		float postFix = (float)pow(2,10*temp); // this is a fix, again, with post-increment operators

		return -(postFix * sin((temp*duration-s)*(2*M_PI)/p ));
	}
	case EasingType::OUT: {
		if (currentTime == 0)
			return 0;

		if (temp == 1)
			return 1;

		float p = duration*.3f;
		float s = p/4;
		return (pow(2,-10*temp) * sin((temp*duration-s)*(2*M_PI)/p ) + 1);
	}
	case EasingType::IN_OUT: {
		if (currentTime == 0)
			return 0;

		if (temp == 1)
			return 1;

		temp *= 2;

		float p = duration*(.3f*1.5f);
		float s = p/4;

		if (temp < 1) {
			temp--;
			return -0.5*(pow(2,10*temp)* sin( (temp*duration-s)*(2*M_PI)/p ));
		}
		temp--;
		return pow(2,-10*temp) * sin( (temp*duration-s)*(2*M_PI)/p )*0.5 + 1;
	}
	default:
		return 0;
	}
}
