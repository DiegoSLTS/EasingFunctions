#pragma once
#include "MyButton.h"

class EasingEquation;

class EquationButton : public MyButton {
public:
	EquationButton(EasingEquation* easing, ButtonParams params);
	virtual ~EquationButton();
	EasingEquation* GetEasing() const;

private:
	EasingEquation* easing;
};
