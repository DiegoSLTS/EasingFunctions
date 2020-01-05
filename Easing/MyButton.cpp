#include "MyButton.h"
#include <iostream>

MyButton::MyButton(ButtonParams params) : GUIElement(params) {
	text = params.text;
	font = params.font;
	callbackObject = params.callbackObject;
	callbackFunction = params.callbackFunction;
}

MyButton::~MyButton() {}

void MyButton::Draw(SDL_Renderer* renderer, SDL_Rect container) {
	SDL_SetRenderDrawColor(renderer,255,255,255,255);

	container.x += x;
	container.y += y;
	container.w = width;
	container.h = height;

	SDL_RenderDrawRect(renderer, &container);

	SDL_Color fontColor = {255,255,255,255};
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), fontColor);
	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer,textSurface);
	
	SDL_QueryTexture(fontTexture, NULL, NULL, &container.w, &container.h);
	container.x += (width - container.w) / 2 + 1;
	container.y += 1;
	SDL_RenderCopy(renderer, fontTexture, NULL, &container);

	SDL_SetRenderDrawColor(renderer,0,0,0,255);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(fontTexture);
}

bool MyButton::HandleClic(int x, int y) {
	if (Contains(x, y)) {
		callbackFunction(callbackObject,this);
		return true;
	}
	return false;
}
