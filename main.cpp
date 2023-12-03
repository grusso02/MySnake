#include "Game.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#define N 20
#define HEIGHT N
#define WIDTH N * 2.5

using namespace mysnake;

int main() {
    initscr();
    refresh();
    noecho();
    curs_set(0);

    Game game(HEIGHT, WIDTH);

    while (!game.isOver()) {
        game.processInput();
        game.updateState();
        game.redraw();
    }

    endwin();
    std::cout << "Game Over! Your score is: " << game.getScore();
    return 0;
}
