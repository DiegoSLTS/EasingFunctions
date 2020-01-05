#pragma once
#include <SDL.h>

class GUIElementParams {
public:
	static const int DEFAULT_X = 0;
	static const int DEFAULT_Y = 0;
	static const int DEFAULT_WIDTH = 100;
	static const int DEFAULT_HEIGHT = 20;

	int x = DEFAULT_X;
	int y = DEFAULT_Y;
	int width = DEFAULT_WIDTH;
	int height = DEFAULT_HEIGHT;
};

class GUIElement {
public:
	GUIElement();
	GUIElement(GUIElementParams params);
	virtual ~GUIElement(void);
	bool Contains(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;

protected:
	int x;
	int y;
	int width;
	int height;
};
