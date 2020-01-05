#include "Plot.h"
#include "EasingEquation.h"

Plot::Plot(EasingEquation* easing) : x(400), y(50), width(200), height(150), textTarget(nullptr) {
	SetEasing(easing);
}

Plot::~Plot() {}

void Plot::Draw(SDL_Renderer* renderer) {
	if (textTarget == nullptr) {
		textTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET, width, height);
		SDL_SetTextureBlendMode(textTarget, SDL_BLENDMODE_BLEND);

		SDL_SetRenderTarget(renderer, textTarget);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		int pad = 15;

		SDL_RenderDrawLine(renderer, 0, pad, 0, height - pad);
		SDL_RenderDrawLine(renderer, 0, height - pad, width, height - pad);

		int x1 = 0;
		int y1 = height - pad - points[0];

		int step = width / POINTS_COUNT;

		for (int i = 1; i < POINTS_COUNT; ++i) {
			int x2 = step * i;
			int y2 = height - pad - points[i] * (height - 2 * pad);
			SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_SetRenderTarget(renderer, NULL);
	}

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = width;
	dst.h = height;

	SDL_RenderCopy(renderer, textTarget, NULL, &dst);
}

void Plot::SetEasing(EasingEquation* easing) {
	this->easing = easing;
	Recalculate();
}

void Plot::Recalculate() {
	easing->Restart();

	int step = easing->GetDuration()/POINTS_COUNT;

	for (int i = 0; i < POINTS_COUNT; i++) {
		easing->Update(step);
		points[i] = easing->Evaluate();
	}

	if (textTarget != nullptr) {
		SDL_DestroyTexture(textTarget);
		textTarget = nullptr;
	}
}