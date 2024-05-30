#ifndef SnakeGame_hpp
#define SnakeGame_hpp
#pragma once
#include <ncurses.h>
#include "Board.hpp"
#include "Drawable.hpp"
#include <time.h>
#include <vector>
#include <stdlib.h>
#include "Apple.hpp"
#include "Map.hpp"
#include "Empty.hpp"
#include "Snake.hpp"
#include "Grape.hpp"
#include "Scoreboard.hpp"
#include "Gate.hpp"
class SnakeGame {
    Board board;
    bool game_over;
    Grape* grape;
    Apple* apple;
    Map* map;
    Gate* gate1;
    Gate* gate2;
    Snake snake;
    Scoreboard scoreboard;
    int score = 0;
    int round;
    int apple_cnt = 0;
    int grape_cnt = 0;
    int length = 4;
    int previousRound;
    int goal[4] = {7,3,1,1};
    void handleNextPiece(SnakePiece next) {
        if (apple != NULL) {
            switch (board.getCharAt(next.getY(), next.getX())) {
            case 'A':
                eatApple();
                break;
            case'B':{
                eatGrape();
                board.add(Empty(next.getY(), next.getX()));
                snake.removePiece();
                break;
                
            }
            case 'T':{
                contactGate();
                break;
                    
                }
            case ' ': {
                int emptyRow = snake.tail().getY();
                int emptyCol = snake.tail().getX();
                board.add(Empty(emptyRow, emptyCol));
                snake.removePiece();
                break;
            }
            default:
                game_over = true;
                break;
            }
        }
        board.add(next);
        snake.addPiece(next);
    }
    void createApple() {
        int y, x;
        board.getEmptyCoordinates(y, x);
        apple = new Apple(y, x);
        board.add(*apple);
    }
    void eatApple() {
        delete apple;
        apple = NULL;
        score += 100;
        length++;
        if (apple_cnt >= 0) apple_cnt++;
        scoreboard.updateScore(score,length,apple_cnt, grape_cnt);
    }
    void createGrape() {
        int y, x;
        board.getEmptyCoordinates(y, x);
        grape = new Grape(y, x);
        board.add(*grape);
    }
    
    void eatGrape() {
        delete grape;
        grape = NULL;
        length--;
        if (length <= 3) {
            game_over = true;
            return;
        }
        if (grape_cnt >= 0) grape_cnt++;
        score -= 100;
        scoreboard.updateScore(score, length, apple_cnt, grape_cnt);
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();
        Direction tailDirection = snake.getTailDirection();
        // 이전 꼬리 위치의 빈 공간 추가
        board.add(Empty(emptyRow, emptyCol));
        // 이전 꼬리 위치에서의 이동 방향에 따라 추가적인 빈 공간 추가
        switch (tailDirection) {
            case up:
                board.add(Empty(emptyRow + 1, emptyCol));
                break;
            case down:
                board.add(Empty(emptyRow - 1, emptyCol));
                break;
            case left:
                board.add(Empty(emptyRow, emptyCol + 1));
                break;
            case right:
                board.add(Empty(emptyRow, emptyCol - 1));
                break;
        }
        snake.removePiece();
    }
    void createGate1() {
        int y, x;
        board.getCkCoordinates(y, x);
        gate1 = new Gate(y, x);
        board.add(*gate1);
        
    }
    void createGate2() {
        int y, x;
        
        board.getCkCoordinates(y, x);
        gate2 = new Gate(y, x);
        board.add(*gate2);
    }
    
    
    void contactGate() {
       
    }
    
    std::vector<Drawable*> drawables;
    
    
public:
    SnakeGame(int height, int width, int speed = 300)
    {
        board = Board(height, width, speed);
        int sb_row = board.getStartRow() + height;
        int sb_col = board.getStartCol();
        scoreboard = Scoreboard(width, sb_row, sb_col);
        initialize();
    }
    ~SnakeGame() {
        delete apple;
        delete grape;
        delete gate1;
        delete gate2;
    }
    std::vector<Drawable*>& getDrawables() {
        return drawables;
    }
    void addObstacles(int stage) {
        switch (stage) {
        case 1: {
            int obstaclePositions[][2] = {
                {5, 10},{5, 11}, {5, 12}, {5, 13},{5, 14}, {5, 15},{5, 16},{5, 17}, {5, 18},{5, 19},{5, 20}, {5, 21},
                {5, 22},{5, 23}, {5, 24}
            };
            for (int i = 0; i < sizeof(obstaclePositions) / sizeof(obstaclePositions[0]); i++) {
                int y = obstaclePositions[i][0];
                int x = obstaclePositions[i][1];
                Map* obstacle = new Map(y, x);
                board.add(*obstacle);
            }
            break;
        }
        case 2: {
            int obstaclePositions[][2] = {
                             {8, 17},
                             {7, 17},
                             {6, 17},
{5, 13},{5, 14}, {5, 15},{5, 16},{5, 17}, {5, 18},{5, 19},{5, 20}, {5, 21},
                                 {4, 17},
                                 {3, 17},
                                 {2, 17}
            };
            for (int i = 0; i < sizeof(obstaclePositions) / sizeof(obstaclePositions[0]); i++) {
                int y = obstaclePositions[i][0];
                int x = obstaclePositions[i][1];
                Map* obstacle = new Map(y, x);
                board.add(*obstacle);
            }
            break;
        }
        case 3: {
            int obstaclePositions[][2] = {
                {4, 1},{4, 2}, {4, 3},{4, 4}, {4, 5},{4, 6},{4, 7}, {4, 8},{4, 9},{4, 10}, {4, 11},{4,12},{4, 13},{4, 14}, {4, 15}, {4, 16},
                {4, 17}, {4, 18},{4, 19},{4, 20}, {4, 21},{4,22},{4, 23},{4, 24}, {4, 25},
                {7, 11},{7,12},{7, 13},{7, 14}, {7, 15},{7, 16},{7, 17}, {7, 18},{7, 19},{7, 20}, {7, 21},{7,22},{7, 23},{7, 24}, {7, 25}, {7, 22}, {7, 23}, {7, 24},
                {7, 25}, {7, 26}, {7, 27}, {7, 28}, {7, 29}, {7, 30}, {7, 31}, {7, 32},
                {7, 33}, {7, 34},
                {9, 1}, {9, 2}, {9, 3}, {9, 4},
                                {9, 5}, {9, 6}, {9, 7}, {9, 8},
                                {9, 9}, {9, 10}, {9, 11}, {9, 12},
                                {9, 13}, {9, 14}, {9, 15}, {9, 16},
                                {9, 17}, {9, 18}, {9, 19}, {9, 20},
                                {9, 21}, {9, 22}, {9, 23}, {9, 24},
                                {9, 25}
            };
            for (int i = 0; i < sizeof(obstaclePositions) / sizeof(obstaclePositions[0]); i++) {
                int y = obstaclePositions[i][0];
                int x = obstaclePositions[i][1];
                Map* obstacle = new Map(y, x);
                board.add(*obstacle);
            }
            break;
        }
        case 4: {
            int obstaclePositions[][2] = {
                {3, 9},{3, 10}, {3, 11},{3, 12},{3, 13}, {3, 14},
                {4, 9},
                {5, 9},                                          {5, 17},{4, 17},                       {5, 22},{4, 22},
                {6, 9},                         {6, 15},{6, 16},{6, 17},{6, 18},{6, 19}, {6, 22},{6, 21},{6, 22},{6, 23},{6, 24},
                {7, 9},                                         {7, 17},{8, 17},                       {7, 22},{8, 22},
                {8, 9},{8, 10}, {8, 11},{8, 12},{8, 13}, {8, 14}
            };
            for (int i = 0; i < sizeof(obstaclePositions) / sizeof(obstaclePositions[0]); i++) {
                int y = obstaclePositions[i][0];
                int x = obstaclePositions[i][1];
                Map* obstacle = new Map(y, x);
                board.add(*obstacle);
            }
            break;
        }
        default:
            break;
        }
    }
    void initialize() {
        apple = NULL;
        grape = NULL;
        gate1 = NULL;
        gate2 = NULL;
        board.initialize();
        score = 0;
        scoreboard.initialize(score);
        game_over = false;
        srand(time(NULL));
        snake.setDirection(down);
        addObstacles(round);
        handleNextPiece(SnakePiece(1, 1));
        handleNextPiece(snake.nextHead());
        handleNextPiece(snake.nextHead());
        snake.setDirection(right);
        handleNextPiece(snake.nextHead());
        if (apple == NULL) {
            createApple();
        }
        if (grape == NULL) {
            createGrape();
        }
        if (gate1 == NULL) {
            createGate1();
        }
        if (gate2 == NULL) {
            createGate2();
        }
    }
    void processInput() {
        chtype input = board.getInput();
        switch (input) {
        case KEY_UP:
        case 'w':
            if (snake.getDirection() != down) {
                snake.setDirection(up);
            }
            else {
                game_over = true;
            }
            break;
        case KEY_DOWN:
        case 's':
            if (snake.getDirection() != up) {
                snake.setDirection(down);
            }
            else {
                game_over = true;
            }
            break;
        case KEY_RIGHT:
        case 'd':
            if (snake.getDirection() != left) {
                snake.setDirection(right);
            }
            else {
                game_over = true;
            }
            break;
        case KEY_LEFT:
        case 'a':
            if (snake.getDirection() != right) {
                snake.setDirection(left);
            }
            else {
                game_over = true;
            }
            break;
        case 'p':
            board.setTimeout(-1);
            while (board.getInput() != 'p')
                board.setTimeout(1000);
            break;
        default:
            break;
        }
    }
    void updateState()
    {
        handleNextPiece(snake.nextHead());
        if (apple == NULL) {
            createApple();
        }
        if (grape == NULL) {
            createGrape();
        }
        if (gate1 == NULL) {
            createGate1();
        }
        if (gate2 == NULL) {
            createGate2();
        }
    }
    void goalAchieved() {
      if (length >= goal[0] && apple_cnt >= goal[1] && grape_cnt >= goal[2]) {
            game_over = true;
        }
    }
    void redraw() {
        board.refresh();
        scoreboard.refresh();
    }
    bool isOver() {
        return game_over;
    }
    int getScore() {
        return score;
    }
};
#endif /* SnakeGame_h */