#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class EasingEquation;

class Circle {
public:
	Circle(SDL_Renderer* renderer, int x, int y, EasingEquation* easing);
	virtual ~Circle(void);
	void Update(Uint32 milliseconds);
	void Draw(SDL_Renderer* renderer) const;
	void SetDestination(int x, int y);
	void SetEasing(EasingEquation* easing);

private:
	SDL_Texture* tex;
	int width;
	int height;
	int x;
	int y;
	int originX;
	int originY;
	int destX;
	int destY;
	EasingEquation* easing;
};
