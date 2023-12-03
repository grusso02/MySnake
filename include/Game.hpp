#pragma once
#include "Board.hpp"
#include <ncurses.h>

namespace mysnake {
class Game {
  private:
    Board  board;
    bool   is_over;
    Apple* apple;

  public:
    Game(int height, int width) {
        this->board = Board(height, width);
        board.initialize();
        this->is_over = false;
        srand(time(NULL));
    }

    ~Game() {
        if (apple)
            delete apple;
    }

    void processInput() {
        board.getInput();
    }

    void updateState() {
        int y, x;
        board.getEmptyCoordinates(y, x);
        if (apple)
            board.print(Empty(apple->getY(), apple->getX()));
        apple = new Apple(y, x);
        board.print(*apple);
    }

    void redraw() { board.refresh(); }

    bool isOver() { return is_over; }
};
} // namespace mysnake
