#pragma once
#include <vector>
#include <SDL.h>

class EasingEquation;

class Plot {
public:
	Plot(EasingEquation* easing);
	virtual ~Plot();
	void Draw(SDL_Renderer* renderer);
	void SetEasing(EasingEquation* easing);
	void Recalculate();

private:
	static const int POINTS_COUNT = 100;

	EasingEquation* easing;
	double points[POINTS_COUNT];
	int x;
	int y;
	int width;
	int height;
	SDL_Texture* textTarget;
};
