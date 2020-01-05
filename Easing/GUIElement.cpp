#include "GUIElement.h"

GUIElement::GUIElement() : x(GUIElementParams::DEFAULT_X), y(GUIElementParams::DEFAULT_Y), width(GUIElementParams::DEFAULT_WIDTH), height(GUIElementParams::DEFAULT_HEIGHT) {}

GUIElement::GUIElement(GUIElementParams params) {
	x = params.x;
	y = params.y;
	width = params.width;
	height = params.height;
}

GUIElement::~GUIElement() {}

bool GUIElement::Contains(int x, int y) const {
	x -= this->x;
	y -= this->y;
	return x >= 0 && x <= width && y >= 0 && y <= height;
}

int GUIElement::GetHeight() const {
	return height;
}

int GUIElement::GetWidth() const {
	return width;
}
