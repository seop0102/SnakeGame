#pragma once
#include <curses.h>
#include"Drawable.hpp"

class Grape : public Drawable {
public:

	Grape(int y, int x) {
		this->y = y;
		this->x = x;
		this->icon = 'B';

	}
};
