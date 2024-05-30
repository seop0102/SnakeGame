#pragma once
#include "Drawable.hpp"
#include <cstdlib>
#include <vector>
 
class Board
{
public:
    Board() {
        construct(0, 0, 300);
    }
    Board(int height, int width, int speed) {
        construct(height, width, speed);
    }
    void initialize() {
        clear();
        refresh();
    }
    void addBorder() {
        wborder(board_win, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD);
    }
    void add(Drawable drawable) {
        addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
    }
    void addAt(int y, int x, chtype ch) {
        mvwaddch(board_win, y, x, ch);
    }
    chtype getInput() {
        return wgetch(board_win);
    }
    void getEmptyCoordinates(int& y, int& x) {
        while ((mvwinch(board_win, y = std::rand() % height, x = std::rand() % width)) != ' ');
    }
    void getCkCoordinates(int& y, int& x) {
        int randomY, randomX;
        bool foundCk = false;
        while (!foundCk) {
            randomY = std::rand() % height;
            randomX = std::rand() % width;
            if (mvwinch(board_win, randomY, randomX) == ACS_CKBOARD) {
                foundCk = true;
            }
        }
        y = randomY;
        x = randomX;
    }
    
    void remove(Drawable& object) {
            // Remove the object from the board grid
            int y = object.getY();
            int x = object.getX();
            mvwaddch(board_win, y, x, ACS_CKBOARD) ;
        }
    chtype getCharAt(int y, int x) {
        return mvwinch(board_win, y, x);
    }
    void clear() {
        wclear(board_win);
        addBorder();
    }
    void refresh() {
        wrefresh(board_win);
    }
    void setTimeout(int timeout) {
        wtimeout(board_win, timeout);
    }
    int getStartRow() {
        return start_row;
    }
    int getStartCol() {
        return start_col;
    }
    int getHeight() {
        return height;
    }
    int getWidth() {
        return width;
    }
private:
    WINDOW* board_win;
    int height, width, start_row, start_col;
    std::vector<std::vector<chtype>> grid;
    void construct(int height, int width, int speed) {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        this->height = height;
        this->width = width;
        start_row = (yMax / 2) - (height / 2);
        start_col = (xMax / 2) - (width / 2);
        board_win = newwin(height, width, start_row, start_col);
        setTimeout(speed);
        keypad(board_win, true);
    }
};
