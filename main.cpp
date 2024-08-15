#include <iostream>
#include <ncurses.h> 
#include <thread>
#include <chrono>

#include "board.hpp"

using namespace std;

int main(int argc, char* argv[]){
    initscr();
    refresh();
    Board b;
    b.initialize();
    b.addBorder();

    b.addAt(1, 1, '#');
    b.refresh();
    for (int i = 0; i < 5; i++){
        this_thread::sleep_for(chrono::seconds(1));
        b.addAt(1, i+2, '#');
        b.refresh();
    }

    getch();
    endwin();

}