#pragma once
#include "MyButton.h"
#include "MyTypes.h"

class EasingButton : public MyButton {
public:
	EasingButton(EasingType ease, ButtonParams params);
	virtual ~EasingButton();
	EasingType GetEase() const;

private:
	EasingType ease;
};
