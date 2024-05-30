#pragma once
#include <ncurses.h>
#include "Drawable.hpp"
#include "SnakeGame.hpp"
#include "Scoreboard.hpp"
#include <queue>
enum Direction {
    up = -1,
    down = 1,
    left = -2,
    right =2
};
class SnakePiece : public Drawable {
public:
    SnakePiece() {
        this->x = this->y = 0;
        this->icon = '#';
    }
    SnakePiece(int y, int x) {
        this->x = x;
        this->y = y;
        this->icon = '#';
    }
};
class Snake {
    std::queue<SnakePiece> prev_pieces;
    Direction cur_direction;
public:
    Snake() {
        cur_direction = down;
    }
    void addPiece(SnakePiece piece) {
        prev_pieces.push(piece);
    }
    void removePiece() {
        prev_pieces.pop();
       
    }
    SnakePiece tail() {
        return prev_pieces.front();
    }
    SnakePiece head() {
        return prev_pieces.back();
    }
    Direction getDirection() {
        return cur_direction;
    }
    void setDirection(Direction d) {
        if (cur_direction + d != 0)
        cur_direction = d;
    }
    Direction getTailDirection() {
        if (prev_pieces.size() < 2) {
            // 꼬리가 한 조각만 있는 경우, 현재 방향을 반환합니다.
            return cur_direction;
        } else {
            // 꼬리의 두 번째 조각과 첫 번째 조각의 위치를 비교하여 방향을 결정합니다.
            SnakePiece tail = prev_pieces.front();
            SnakePiece secondTail = prev_pieces.back();
            int tailRow = tail.getY();
            int tailCol = tail.getX();
            int secondTailRow = secondTail.getY();
            int secondTailCol = secondTail.getX();
            if (tailRow < secondTailRow) {
                return up;
            } else if (tailRow > secondTailRow) {
                return down;
            } else if (tailCol < secondTailCol) {
                return left;
            } else {
                return right;
            }
        }
    }
    SnakePiece nextHead() {
        int row = head().getY();
        int col = head().getX();
        switch (cur_direction) {
        case down:
            row++;
            break;
        case up:
            row--;
            break;
        case left:
            col--;
            break;
        case right:
            col++;
            break;
        }
        return SnakePiece(row, col);
    }
};
