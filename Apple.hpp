#pragma once
#include <curses.h>
#include"Drawable.hpp"

class Apple : public Drawable {
public:

	Apple(int y, int x) {
		this->y = y;
		this->x = x;
		this->icon = 'A';

	}
};
