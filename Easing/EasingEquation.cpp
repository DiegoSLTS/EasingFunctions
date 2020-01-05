#include "EasingEquation.h"

EasingEquation::EasingEquation() : ease(EasingType::IN), duration(1000), currentTime(1001) {}
EasingEquation::~EasingEquation() {}

void EasingEquation::Update(Uint32 deltaTime) {
	if (currentTime < duration)
		currentTime += deltaTime;

	if (currentTime >= duration)
		currentTime = duration;
}

void EasingEquation::Restart() {
	currentTime = 0;
}

void EasingEquation::Stop() {
	currentTime = duration + 1;
}

float EasingEquation::GetTime() const {
	return (float)currentTime / duration;
}

void EasingEquation::SetEase(EasingType ease) {
	this->ease = ease;
}

Uint32 EasingEquation::GetDuration() const {
	return duration;
}