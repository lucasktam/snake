#include <iostream>
#include <ncurses.h> 


using namespace std;

int main(int argc, char* argv[]){
    int x,y;
    x = y = 10;
    initscr();
    int height = 10;
    int width = 20;
    WINDOW * win = newwin(height, width, y, x);
    refresh();
    box(win,0,0);
    // wprintw(win, "Hello");
    mvwprintw(win, 1, 1, "Hello");
    wrefresh(win);
    getch();
    endwin();
}