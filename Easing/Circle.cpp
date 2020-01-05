#include "Circle.h"
#include <math.h>
#include "EasingEquation.h"

Circle::Circle(SDL_Renderer* renderer, int x, int y, EasingEquation* easing) : x(x), y(y), easing(easing) {
	std::string circlePath = SDL_GetBasePath();
	circlePath.append("circle.png");
	tex = IMG_LoadTexture(renderer,circlePath.c_str());
	SDL_SetTextureBlendMode(this->tex, SDL_BLENDMODE_BLEND);

	if (tex == nullptr)
		std::cout << "IMG_LoadTexture error: " << SDL_GetError() << std::endl;

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);
}

Circle::~Circle() {
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void Circle::Update(Uint32 deltaTime) {
	if (easing->GetTime() < 1) {
		easing->Update(deltaTime);
		double p = easing->Evaluate();
		x = (int)(destX*p + originX*(1-p));
		y = (int)(destY*p + originY*(1-p));
	}
}

void Circle::Draw(SDL_Renderer* renderer) const {
	SDL_Rect dst;
	dst.x = x - width/2;
	dst.y = y - height/2;
	dst.w = width;
	dst.h = height;

	SDL_RenderCopy(renderer, tex, NULL, &dst);
}

void Circle::SetDestination(int x, int y) {
	originX = this->x;
	originY = this->y;
	destX = x;
	destY = y;
	easing->Restart();
}

void Circle::SetEasing(EasingEquation* easing) {
	this->easing = easing;
}
