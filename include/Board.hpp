#pragma once

#include "Drawable.hpp"
#include "Time.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

namespace mysnake {
class Board {
  private:
    WINDOW* board;
    int     height, width;
    int     timeout;

  public:
    Board() : height(0), width(0) {}
    Board(int h, int w, int speed) : height(h), width(w) {
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);
        this->timeout = speed;
        this->board = newwin(height, width, ((yMax / 2) - (this->height / 2)),
                             ((xMax / 2) - (this->width / 2)));
        keypad(board, true);
        setTimeout(speed);
    };

    int getHeight() { return height; }

    int getWidth() { return width; }

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

    int getInput() {
        time_t time_last_input = Time::milliseconds();

        chtype input = wgetch(board);

        setTimeout(0);
        while (time_last_input + timeout >= Time::milliseconds())
            ;
        setTimeout(timeout);

        return input;
    }

    chtype getCharAt(int y, int x) { return (mvwinch(board, y, x)); }

    int  getTimeout() { return timeout; }
    void setTimeout(int speed) { wtimeout(board, speed); }
};
} // namespace mysnake
