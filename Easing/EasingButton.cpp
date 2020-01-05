#include "EasingButton.h"

EasingButton::EasingButton(EasingType ease, ButtonParams params) : MyButton(params), ease(ease) {}
EasingButton::~EasingButton() {}

EasingType EasingButton::GetEase() const {
	return ease;
}
