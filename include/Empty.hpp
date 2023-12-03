#pragma once
#include "Drawable.hpp"

namespace mysnake {
class Empty : public Drawable {
  public:
    Empty(int y, int x) {
        this->_y = y;
        this->_x = x;
        this->_ch = ' ';
    }
};

} // namespace mysnake