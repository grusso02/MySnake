#pragma once

#include "Drawable.hpp"

namespace mysnake {
class Apple : public Drawable {
  public:
    Apple(int y, int x) {
        this->_y = y;
        this->_x = x;
        this->_ch = 'o';
    }
};

} // namespace mysnake