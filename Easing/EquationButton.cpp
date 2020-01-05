#include "EquationButton.h"
#include "EasingEquation.h"

EquationButton::EquationButton(EasingEquation* easing, ButtonParams params) : MyButton(params), easing(easing) {}
EquationButton::~EquationButton() {}

EasingEquation* EquationButton::GetEasing() const {
	return easing;
}