#include "GUI.h"
#include <math.h>
#include <iostream>

#include "EasingEquation.h"
#include "EasingButton.h"
#include "EquationButton.h"

GUI::GUI(TTF_Font* font) : linear(1), quad(2), cubic(3), quart(4), quint(5) {
	font = font;
	textTarget = nullptr;

	buttonLists.reserve(2);

	buttonLists.emplace_back();
	ButtonList& equationButtons = buttonLists.back();

	ButtonParams params;
	params.font = font;
	params.callbackObject = this;
	params.callbackFunction = std::mem_fn(&GUI::EquationButtonClicked);

	params.text = "Linear";
	equationButtons.AddButton(new EquationButton(&linear, params));
	params.text = "Quad";
	equationButtons.AddButton(new EquationButton(&quad, params));
	params.text = "Cubic";
	equationButtons.AddButton(new EquationButton(&cubic, params));
	params.text = "Quart";
	equationButtons.AddButton(new EquationButton(&quart, params));
	params.text = "Quint";
	equationButtons.AddButton(new EquationButton(&quint, params));
	params.text = "Back";
	equationButtons.AddButton(new EquationButton(&back, params));
	params.text = "Bounce";
	equationButtons.AddButton(new EquationButton(&bounce, params));
	params.text = "Circular";
	equationButtons.AddButton(new EquationButton(&circular, params));
	params.text = "Sinusoidal";
	equationButtons.AddButton(new EquationButton(&sinusoidal, params));
	params.text = "Elastic";
	equationButtons.AddButton(new EquationButton(&elastic, params));
	params.text = "Exponential";
	equationButtons.AddButton(new EquationButton(&exponential, params));

	ButtonListParams listParams;
	listParams.x = equationButtons.x + equationButtons.GetWidth();

	buttonLists.emplace_back(listParams);
	ButtonList& easingButtons = buttonLists.back();

	params.callbackFunction = std::mem_fn(&GUI::EasingButtonClicked);

	params.text = "EaseIn";
	easingButtons.AddButton(new EasingButton(EasingType::IN, params));
	params.text = "EaseOut";
	easingButtons.AddButton(new EasingButton(EasingType::OUT, params));
	params.text = "EaseInOut";
	easingButtons.AddButton(new EasingButton(EasingType::IN_OUT, params));

	width = easingButtons.GetWidth() + equationButtons.GetWidth();
	height = easingButtons.GetHeight();
	if (height < equationButtons.GetHeight())
		height = equationButtons.GetHeight();

	selectedEasingButton = (EasingButton*)easingButtons.at(0);
	selectedEquationButton = (EquationButton*)equationButtons.at(0);
}

GUI::~GUI() {}

void GUI::EasingButtonClicked(MyButton* button) {
	EasingButton* b = (EasingButton*)button;
	selectedEasingButton = b;
	EasingEquation* selectedEquation = getSelectedEquation();
	selectedEquation->SetEase(getSelectedType());
}

void GUI::EquationButtonClicked(MyButton* button) {
	EquationButton* b = (EquationButton*)button;
	selectedEquationButton = b;
	EasingEquation* selectedEquation = getSelectedEquation();
	selectedEquation->SetEase(getSelectedType());
}

EasingEquation* GUI::getSelectedEquation() {
	return selectedEquationButton->GetEasing();
}

EasingType GUI::getSelectedType() {
	return selectedEasingButton->GetEase();
}

bool GUI::HandleClic(int mouseX, int mouseY) {
	for (auto&& buttonsList : buttonLists)
		if (buttonsList.HandleClic(mouseX, mouseY))
			return true;

	return false;
}

void GUI::Draw(SDL_Renderer* renderer) {
	if (textTarget == nullptr) {
		textTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET, width, height);
		SDL_SetTextureBlendMode(textTarget, SDL_BLENDMODE_BLEND);

		SDL_SetRenderTarget(renderer, textTarget);

		for (auto&& buttonsList : buttonLists)
			buttonsList.Draw(renderer);

		SDL_SetRenderTarget(renderer,NULL);
	}

	SDL_Rect dst;
	dst.x = 0;
	dst.y = 0;
	dst.w = width;
	dst.h = height;

	SDL_RenderCopy(renderer, textTarget, NULL, &dst);
}
