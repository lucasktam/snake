#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream> 
#include <ncurses.h> 

class Board {
public:
    Board();

    Board(int height, int width);

    void initialize();

    void addAt(int y, int x, chtype ch);

    void addBorder();

    void clear();

    void refresh(); 

private:
    WINDOW * win; 
};


#endif