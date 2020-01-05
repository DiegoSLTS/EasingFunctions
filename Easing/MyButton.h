#pragma once
#include <functional>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "GUIElement.h"

class GUI;
class MyButton;

class ButtonParams : public GUIElementParams {
public:
	static const int DEFAULT_X = GUIElementParams::DEFAULT_X;
	static const int DEFAULT_Y = GUIElementParams::DEFAULT_Y;
	static const int DEFAULT_WIDTH = GUIElementParams::DEFAULT_WIDTH;
	static const int DEFAULT_HEIGHT = GUIElementParams::DEFAULT_HEIGHT;

	std::string text;
	TTF_Font* font = nullptr;
	GUI* callbackObject;
	std::function<void(GUI*,MyButton*)> callbackFunction;
};

class MyButton : public GUIElement {
public:
	MyButton(ButtonParams params);
	virtual ~MyButton();
	void Draw(SDL_Renderer* renderer, SDL_Rect container);
	bool HandleClic(int x, int y);

private:
	std::string text;
	TTF_Font* font;
	GUI* callbackObject;
	std::function<void(GUI*, MyButton*)> callbackFunction;
};