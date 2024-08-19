#include <iostream>
#include <ncurses.h> 
#include <thread>
#include <chrono>


#include "board.hpp"
#include "snake.hpp"
#include "game.hpp"

using namespace std;

int main(int argc, char* argv[]){
    const int BOARDHEIGHT = 20;
    // BOARDWIDTH must be divisible by 2
    const int BOARDWIDTH = 48;
    // Initializes and allocates memory
    initscr();
    // ctrl+c exits
    cbreak();
    // input doesn't print
    noecho();
    // cursor is invisible and doesn't highlight
    curs_set(0);
   
    
    // init board
    Board b = Board(BOARDHEIGHT,BOARDWIDTH);
    b.initialize();
    b.addBorder();

    // init game 
    Game g;
    g.start();

    // init snake 
    Snake s(b, g);

    int ch;
    
    // Main game loop
    // While game is playing: 
    while (g.getStatus() == 1) {
        // Wait
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        // Listen for input
        ch = wgetch(b.getWin());
        
        // If ch is non-null
        if (ch != ERR) {
            if (ch == 'q') {  // Exit on 'q'
                break;
            }
            // Change direction
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