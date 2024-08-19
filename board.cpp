#include <iostream>
#include <ncurses.h>
#include "board.hpp"

using namespace std; 

// Initializes Board to 20 and 48
// Attempts to set nodelay 
Board::Board(){
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);
    height = 20;
    width = 48;
    win = newwin(20, 48, ymax/2 - 20 / 2, xmax/2 - 48 / 2);
    nodelay(win, TRUE);
}

// Initializes Board to given input
// Attempts to set nodelay 
Board::Board(int h, int w){
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);
    height = h;
    width = w;
    win = newwin(height, width, (ymax/2) - (height/2), (xmax/2) - (width / 2));
    nodelay(win, TRUE);
}

// Clear and refresh
void Board::initialize(){
    clear();
    refresh();
}

// mvwaddch and refresh
void Board::addAt(int y, int x, chtype ch){
    mvwaddch(win, y, x, ch);
    mvwaddch(win, y, x+1, ch);
    refresh();
}

// puts default border and refresh 
void Board::addBorder(){
    box(win, 0, 0);
}

// clears and add border
void Board::clear(){
    wclear(win);
    addBorder();
}

// refresh
void Board::refresh(){
    wrefresh(win);
}

// returns win
WINDOW* Board::getWin() const {
    return win;
}

int Board::getHeight() const{
    return height;
}

int Board::getWidth() const{
    return width;
}