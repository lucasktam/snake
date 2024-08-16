#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream> 
#include <ncurses.h> 

class Board{
public:
    // Initializes Board to 20 and 28
    // Attempts to set nodelay 
    Board();

    // Initializes Board to given input
    // Attempts to set nodelay 
    Board(int height, int width);

    // Clear and refresh
    void initialize();

    // mvwaddch and refresh
    void addAt(int y, int x, chtype ch);

    // puts default border and refresh 
    void addBorder();

    // clears and add border
    void clear();

    void refresh(); 

    // returns win
    WINDOW* getWin() const;

private:
    WINDOW * win; 
};


#endif