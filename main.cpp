#include <iostream>
#include <ncurses.h> 

using namespace std;

int main(int argc, char* argv[]){
    initscr();
    noecho();
    cbreak();

    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW * inputwin = newwin(3, xmax-12, ymax-5, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    int c = wgetch(inputwin);
    if (c == 'j'){
        wprintw(inputwin, "You pressed J");
        wrefresh(inputwin);
    }
    getch();

    endwin();
    return 0;
}