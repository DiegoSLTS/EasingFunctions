#pragma once
#include <vector>
#include <SDL_ttf.h>
#include "MyButton.h"

class ButtonListParams {
public:
	static const int DEFAULT_VERTICAL_PADDING = 10;
	static const int DEFAULT_HORIZONTAL_PADDING = 10;
	static const int DEFAULT_X = 0;
	static const int DEFAULT_Y = 0;

	int verticalPadding = DEFAULT_VERTICAL_PADDING;
	int horizontalPadding = DEFAULT_HORIZONTAL_PADDING;
	int x = DEFAULT_X;
	int y = DEFAULT_Y;
};

class ButtonList {
public:
	std::vector<MyButton*> buttons;
	int verticalPadding;
	int horizontalPadding;
	int x;
	int y;
	int contentWidth;
	int contentHeight;

	ButtonList();
	ButtonList(ButtonListParams params);
	void AddButton(MyButton* button);
	void Draw(SDL_Renderer* renderer);
	MyButton* at(unsigned int index) const;
	int GetWidth() const;
	int GetHeight() const;
	bool HandleClic(int mouseX, int mouseY);

	~ButtonList();
};
