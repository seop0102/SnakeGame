#pragma once
#include <ncurses.h>
#include "Drawable.hpp"
class Gate : public Drawable {
public:
    
    Gate(int y, int x) : Drawable(y, x, ACS_DIAMOND) {
        this->icon = 'T';
    }
   
    void setPosition(int newY, int newX) {
        y = newY;
        x = newX;
    }
    
    
};
