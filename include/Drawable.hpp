#pragma once
#include "ncurses.h"

namespace mysnake {
class Drawable {
  protected:
    int    _y, _x;
    chtype _ch;

  public:
    Drawable() : _y(0), _x(0), _ch(0) {}

    Drawable(int y, int x, char ch) {
        this->_y = y;
        this->_x = x;
        this->_ch = 'o';
    }

    int  getY() { return _y; }
    void setY(int y) { this->_y = y; }

    int  getX() { return _x; }
    void setX(int x) { this->_x = x; }

    char getCh() { return _ch; }
};

} // namespace mysnake