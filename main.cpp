#include <iostream>
#include <ncurses.h> 
#include <thread>
#include <chrono>


#include "board.hpp"
#include "snake.hpp"

using namespace std;

int main(int argc, char* argv[]){
    // Initializes and allocates memory
    initscr();
    // ctrl+c exits
    cbreak();
    // input doesn't print
    noecho();
    // cursor is invisible and doesn't highlight
    curs_set(0);
   
    
    // init board
    Board b;
    b.initialize();
    b.addBorder();
    
    // init snake 
    Snake s(b);

    int ch;
    // Attempt at main loop. 
    // wgetch() is blocking. Need to fix.
    while (true) {
        // sleep 
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        ch = wgetch(b.getWin());
        
        if (ch != ERR) {
            if (ch == 'q') {  // Exit on 'q'
                break;
            }
            // Handle other keys or perform actions
            else if (ch == 'w'){
                s.changeDirection(Direction::up);
            }
            else if (ch == 's'){
                s.changeDirection(Direction::down);
            }
            else if (ch == 'a'){
                s.changeDirection(Direction::left);
            }
            else if (ch == 'd'){
                s.changeDirection(Direction::right);
            }
            
            
        }
        s.move();
    }
    
    // Deallocates memory
    endwin();

    return 0;
}