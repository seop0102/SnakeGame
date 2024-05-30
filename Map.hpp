#ifndef Map_hpp
#define Map_hpp
#pragma once
#include <ncurses.h>
#include"Drawable.hpp"
class Map : public Drawable {
public:
    Map(int y, int x) : Drawable(y, x, ACS_CKBOARD) {}


};
#endif
