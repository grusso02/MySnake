#pragma once

namespace mysnake {
class Drawable {
  protected:
    int  _y, _x;
    char _ch;

  public:
    Drawable() {}

    Drawable(int y, int x, char ch) {
        this->_y = y;
        this->_x = x;
        this->_ch = 'o';
    }

    int getY() { return _y; }

    int getX() { return _x; }

    char getCh() { return _ch; }
};

} // namespace mysnake