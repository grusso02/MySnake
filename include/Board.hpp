#pragma once
#include "Apple.hpp"
#include "Empty.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

namespace mysnake {
class Board {
  private:
    WINDOW* board;
    int     height, width;

  public:
    Board() : height(0), width(0) {}
    Board(int h, int w) : height(h), width(w) {
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        this->board = newwin(height, width, ((yMax / 2) - (this->height / 2)),
                             ((xMax / 2) - (this->width / 2)));
        keypad(board, true);
    };

    void initialize() {
        clear();
        refresh();
    }

    void addBorder() { box(board, 0, 0); }

    void refresh() { wrefresh(board); }

    void clear() {
        wclear(board);
        addBorder();
    }

    void printAt(int y, int x, char ch) { mvwaddch(board, y, x, ch); }

    void print(Drawable drawable) {
        printAt(drawable.getY(), drawable.getX(), drawable.getCh());
    }

    void getEmptyCoordinates(int& y, int& x) {
        while (mvwinch(board, y = rand() % height + 1,
                       x = rand() % width + 1) != ' ')
            continue;
    }

    int getInput() { return (wgetch(board)); }
};
} // namespace mysnake
