#include "snake.hpp"
#include "board.hpp"
#include "game.hpp"

using namespace std;


// default initializer - place holder for now. 
Snake::Snake(Board& b, Game& g) : board(b), game(g) {
    length = 5;
    direction = Direction::up;

    for (int i = 7; i < 20; i++){
        push({7, i});
    }
    head = {7, 20};
    push(head);
    board.refresh();
}

// initializes length and direction to parameters
Snake::Snake(Board& b, Game& g, int l, Direction d) : board(b), game(g){
    length = l;
    direction = d;
}

// Pops the tail (front value)
// Pushes a new head piece 
void Snake::move(){
    
    // board.addAt(0, 0, 'a');
    // board.addAt(board.getHeight()-1, 0, 'b');
    // board.addAt(0, board.getWidth()-1, 'c');
    // board.addAt(board.getHeight()-1, board.getWidth()-1, 'd');

    switch(direction){
        case Direction::up: // -y 
            pop(bodyqueue.front());
            // If the next part is in the snake's body already, then snake dies. 
            if (bodyset.find({head.first - 1, head.second}) != bodyset.end()){
                kill();
            }
            // If the next part is part of the border, then snake dies. 
            // Vertical border: y = 0, y = board.getHeight()
            
            if (head.first - 1 == 0){
                kill();
            }
            else{
                push({head.first - 1, head.second});
            }
            break;

        case Direction::down: // +y
            pop(bodyqueue.front());
            if (bodyset.find({head.first + 1, head.second}) != bodyset.end()){
                kill();
            }
            if (head.first + 1 == board.getHeight() - 1){
                kill();
            }
            else{
                push({head.first + 1, head.second});
            }
            break;
        case Direction::left: // -x
            pop(bodyqueue.front());
            if (bodyset.find({head.first, head.second - 2}) != bodyset.end()){
                kill();
            }
            // Horizontal border: x = 0, x = board.getWidth()
            if (head.second - 2 == 0){
                kill();
            }
            else{
                push({head.first, head.second - 2});
            }
            break;
        case Direction::right: // +x
            pop(bodyqueue.front());
            if (bodyset.find({head.first, head.second + 2}) != bodyset.end()){
                kill();
            }
            if (head.second + 2 == board.getWidth() - 2){
                kill();
            }
            else{
                push({head.first, head.second + 2});
            }
            break;
    }
}

// changes direction to set direction - ignoring opposites
void Snake::changeDirection(Direction d){
    if (direction + d != 0){
        direction = d;
    }
}

// returns direction 
Direction Snake::getDirection() const {
    return direction;
}

// pushes an element into both bodyqueue and bodyset. 
// Then resets head. 
void Snake::push(std::pair<int, int> p){
    bodyqueue.push(p);
    bodyset.insert(p);
    board.addAt(p.first, p.second, ' ' | A_REVERSE);
    head = p;
}

// If element is in bodyset, pops element from both bodyset and bodyqueue.
// then erases the element on the board. 
void Snake::pop(std::pair<int, int> p){
    if (bodyset.find(p) != bodyset.end()){
        bodyset.erase(p);
        bodyqueue.pop();
        board.addAt(p.first, p.second, ' ');
    }
}

void Snake::kill(){
    game.end();
}