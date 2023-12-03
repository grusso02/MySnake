#pragma once
#include <ncurses.h>

namespace mysnake {
class Scoreboard {
  private:
    WINDOW* scoreboard;

  public:
    Scoreboard(){};
    Scoreboard(int width, int y, int x) {
        this->scoreboard = newwin(1, width, y, x);
    }
    ~Scoreboard(){};

    void initialize(int intial_score) {
        clear();
        mvwprintw(scoreboard, 0, 0, "Score: ");
        updateScore(intial_score);
        refresh();
    }

    void clear() { wclear(scoreboard); };

    void refresh() { wrefresh(scoreboard); }

    void updateScore(int score) {
        mvwprintw(scoreboard, 0, getmaxx(scoreboard) - 10, "%10llu", score);
    }
};

} // namespace mysnake