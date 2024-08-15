#include <iostream>
#include <ncurses.h>
#include "board.hpp"

using namespace std; 


Board::Board(){
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    win = newwin(20, 48, ymax/2 - 20 / 2, xmax/2 - 48 / 2);
}

Board::Board(int height, int width){
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    win = newwin(height, width, (ymax/2) - (height/2), (xmax/2) - (width / 2));
}

void Board::initialize(){
    clear();
    refresh();
}

void Board::addAt(int y, int x, chtype ch){
    mvwaddch(win, y, x, ch);
}

void Board::addBorder(){
    box(win, 0, 0);
}

void Board::clear(){
    wclear(win);
    addBorder();
}

void Board::refresh(){
    wrefresh(win);
}