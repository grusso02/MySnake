#pragma once

#include "Apple.hpp"
#include "Board.hpp"
#include "Empty.hpp"
#include "Snake.hpp"
#include <ncurses.h>

namespace mysnake {
class Game {
  private:
    Board  board;
    bool   is_over;
    Apple* apple;
    Snake  snake;

  public:
    Game() : board(), is_over(false), apple(nullptr) {}

    Game(int height, int width) {
        this->board = Board(height, width, 150);
        initialize();
    }

    ~Game() {
        if (apple)
            delete apple;
    }

    void initialize() {
        board.initialize();
        this->is_over = false;
        apple = NULL;
        srand(time(NULL));

        snake.setCurrentDirection(DOWN);
        handleNextPiece(SnakePiece(1, 1));

        createApple();
    }

    void processInput() {
        switch (board.getInput()) {
        case KEY_UP:
            snake.setCurrentDirection(UP);
            break;
        case KEY_DOWN:
            snake.setCurrentDirection(DOWN);
            break;
        case KEY_RIGHT:
            snake.setCurrentDirection(RIGHT);
            break;
        case KEY_LEFT:
            snake.setCurrentDirection(LEFT);
            break;
        case 'p': {
            board.setTimeout(-1);
            while (board.getInput() != 'p')
                ;
            board.setTimeout(board.getTimeout());
        }
        default:
            break;
        }
    }

    void updateState() {
        SnakePiece next = snake.nextHead();
        checkOverBoard(next);
        checkCollision(next);
        handleNextPiece(next);
        createApple();
    }

    void redraw() { board.refresh(); }

    bool isOver() { return is_over; }

  private:
    void createApple() {
        if (!apple) {
            int y, x;
            board.getEmptyCoordinates(y, x);
            apple = new Apple(y, x);
            board.print(*apple);
        }
    }

    void destroyApple() {
        if (apple) {
            delete apple;
            apple = NULL;
        }
    }

    void handleNextPiece(SnakePiece piece) {
        if (apple &&
            (piece.getX() != apple->getX() || piece.getY() != apple->getY())) {
            int emptyRow = snake.tail().getY();
            int emptyColumn = snake.tail().getX();
            board.print(Empty(emptyRow, emptyColumn));
            snake.removePiece();
        } else
            destroyApple();
        board.print(piece);
        snake.addPiece(piece);
    }

    void checkOverBoard(SnakePiece& piece) {
        if (piece.getY() == (board.getHeight() - 1))
            piece.setY(1);
        if (!piece.getY())
            piece.setY(board.getHeight() - 2);
        if (piece.getX() == (board.getWidth() - 1))
            piece.setX(1);
        if (!piece.getX())
            piece.setX(board.getWidth() - 2);
    }

    void checkCollision(SnakePiece& piece) {
        if (board.getCharAt(piece.getY(), piece.getX()) == piece.getCh())
            endGame();
    }

    void endGame() { is_over = true; }
};
} // namespace mysnake
