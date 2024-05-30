#include <ncurses.h>
#include <iostream>
#include "Board.hpp"
#include "SnakeGame.hpp"
#include "Drawable.hpp"
#define BOARD_DIM 12
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 3
int main(int argc, char** argv)
{
    int round =1;
    for (; round <= 4; round++) {
        initscr();
        refresh();
       
        noecho();
        curs_set(0);
        SnakeGame game(BOARD_ROWS, BOARD_COLS, 1000);
        game.addObstacles(round); //장애물 추가
        
        while (!game.isOver()) {
            game.processInput();
            game.updateState();
            game.redraw();
            game.goalAchieved();
        }
        getch();
        endwin();
        std::cout << "Round: " << round << std::endl;
        std::cout << "Score: " << game.getScore() << " points" << std::endl;
        std::cout << std::endl;
 
    }
    return 0;
}
