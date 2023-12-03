#include "Board.hpp"
#include "Game.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#define N 25
#define HEIGHT N
#define WIDTH N * 2.5

using namespace mysnake;

int main() {
    initscr();
    refresh();

    Game game(HEIGHT, WIDTH);

    while (!game.isOver()) {
        game.processInput();
        game.updateState();
        game.redraw();
    }

    getch();
    endwin();

    return 0;
}
