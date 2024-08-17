#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>

class Game{
public:
    Game();

    void start();

    void end();

    int getStatus() const;

private:
    int status; // 0 = not playing 1 = playing
};

#endif