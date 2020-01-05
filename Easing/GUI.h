#pragma once

#include "MyTypes.h"

#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>

#include "ButtonList.h"

#include "PolygonEquation.h"
#include "BackEquation.h"
#include "BounceEquation.h"
#include "CircularEquation.h"
#include "ElasticEquation.h"
#include "ExponentialEquation.h"
#include "SineEquation.h"

class EasingEquation;
class EasingButton;
class MyButton;
class EquationButton;

class GUI {
public:
	GUI(TTF_Font* font);
	~GUI();
	EasingEquation* getSelectedEquation();
	EasingType getSelectedType();
	bool HandleClic(int mouseX, int mouseY);
	void Draw(SDL_Renderer* renderer);
	void EasingButtonClicked(MyButton* button);
	void EquationButtonClicked(MyButton* button);

private:
	TTF_Font* font;
	int width;
	int height;
	std::vector<ButtonList> buttonLists;
	EasingButton* selectedEasingButton;
	EquationButton* selectedEquationButton;
	SDL_Texture* textTarget;

	PolygonEquation linear;
	PolygonEquation quad;
	PolygonEquation cubic;
	PolygonEquation quart;
	PolygonEquation quint;
	BackEquation back;
	BounceEquation bounce;
	CircularEquation circular;
	ElasticEquation elastic;
	ExponentialEquation exponential;
	SineEquation sinusoidal;
};
