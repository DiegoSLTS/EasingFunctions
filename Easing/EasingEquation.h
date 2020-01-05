#pragma once
#include <SDL.h>
#include "MyTypes.h"

class EasingEquation {
public:
	EasingEquation();
	virtual ~EasingEquation(void);
	void Update(Uint32 deltaTime);
	virtual double Evaluate() const = 0;
	float GetTime() const;
	void Restart();
	void Stop();
	void SetEase(EasingType ease);
	Uint32 GetDuration() const;

protected:
	Uint32 duration;
	Uint32 currentTime;
	EasingType ease;
};
