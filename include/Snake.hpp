#pragma once

#include "Drawable.hpp"
#include <queue>

namespace mysnake {

enum Directions { UP = -1, DOWN = 1, RIGHT = -2, LEFT = 2 };

class SnakePiece : public Drawable {
  public:
    SnakePiece() {
        this->_y = this->_y = 0;
        this->_ch = '#';
    }

    SnakePiece(int y, int x) {
        this->_y = y;
        this->_x = x;
        this->_ch = '#';
    }
};

class Snake {
  private:
    std::queue<SnakePiece> snake;
    Directions             direction;

  public:
    Snake() : direction(DOWN) {}

    void addPiece(SnakePiece piece) { snake.push(piece); }

    void removePiece() { snake.pop(); }

    SnakePiece head() { return snake.back(); }

    SnakePiece tail() { return snake.front(); }

    Directions getCurrentDirection() { return direction; }
    void       setCurrentDirection(Directions d) {
        if (getCurrentDirection() + d)
            this->direction = d;
    }

    SnakePiece nextHead() {
        int currentY = head().getY();
        int currentX = head().getX();

        switch (getCurrentDirection()) {
        case UP:
            currentY--;
            break;
        case DOWN:
            currentY++;
            break;
        case RIGHT:
            currentX++;
            break;
        case LEFT:
            currentX--;
            break;
        default:
            break;
        }

        return (SnakePiece(currentY, currentX));
    }
};
} // namespace mysnake