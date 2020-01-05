#include "ButtonList.h"
#include <iostream>

ButtonList::ButtonList() : verticalPadding(ButtonListParams::DEFAULT_VERTICAL_PADDING), horizontalPadding(ButtonListParams::DEFAULT_HORIZONTAL_PADDING),
	x(ButtonListParams::DEFAULT_X), y(ButtonListParams::DEFAULT_Y), contentWidth(0), contentHeight(0) {}

ButtonList::ButtonList(ButtonListParams params) : contentWidth(0), contentHeight(0) {
	verticalPadding = params.verticalPadding;
	horizontalPadding = params.horizontalPadding;
	x = params.x;
	y = params.y;
}

void ButtonList::AddButton(MyButton* button) {
	buttons.push_back(button);

	if (contentWidth < button->GetWidth())
		contentWidth = button->GetWidth();
	
	contentHeight += button->GetHeight();

	if (buttons.size() > 1)
		contentHeight += verticalPadding;
}

ButtonList::~ButtonList() {
	for (auto&& button : buttons)
		delete button;

	buttons.clear();
}

MyButton* ButtonList::at(unsigned int index) const {
	return buttons.at(index);
}

void ButtonList::Draw(SDL_Renderer* renderer) {
	SDL_Rect rect;
	rect.x = x + horizontalPadding;
	rect.y = y + verticalPadding;
	rect.h = 0;

	if (buttons.size() > 1)
		rect.h += (buttons.size() - 1) * verticalPadding;

	/*SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Rect rect2;
	rect2.x = this->x;
	rect2.y = this->y;
	rect2.w = this->getWidth();
	rect2.h = this->getHeight();

	SDL_RenderDrawRect(renderer, &rect2);*/

	for (auto&& button : buttons) {
		button->Draw(renderer, rect);
		rect.y += button->GetHeight() + verticalPadding;
	}
}

int ButtonList::GetWidth() const {
	return contentWidth + horizontalPadding * 2;
}

int ButtonList::GetHeight() const {
	return contentHeight + verticalPadding * 2;
}

bool ButtonList::HandleClic(int mouseX, int mouseY) {
	int x = mouseX - (this->x + horizontalPadding);
	int y = mouseY - (this->y + verticalPadding);
	
	for (auto&& button : buttons) {
		if (button->HandleClic(x, y))
			return true;
		y -= button->GetHeight() + verticalPadding;
	}

	return false;
}