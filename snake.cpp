#include "snake.hpp"
#include "board.hpp"

using namespace std;


// default initializer - place holder for now. 
Snake::Snake(){
    length = 5;
    direction = Direction::up;

    for (int i = 7; i < 13; i++){
        push({7, i});
        
    }
    head = {7, 13};
    push(head);
}

// initializes length and direction to parameters
Snake::Snake(int l, Direction d){
    length = l;
    direction = d;
}

// Pops the tail (front value)
// Pushes a new head piece 
void Snake::move(){
    switch(direction){
        case Direction::up: // -y 
            pop(bodyqueue.front());
            push({head.first - 1, head.second});
            break;
        case Direction::down: // +y
            pop(bodyqueue.front());
            push({head.first + 1, head.second});
            break;
        case Direction::left: // -x
            pop(bodyqueue.front());
            push({head.first, head.second - 1});
            break;
        case Direction::right: // +x
            pop(bodyqueue.front());
            push({head.first, head.second + 1});
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
Direction Snake::getDirection(){
    return direction;
}

// pushes an element into both bodyqueue and bodyset. 
// Then resets head. 
void Snake::push(std::pair<int, int> p){
    bodyqueue.push(p);
    bodyset.insert(p);
    b.addAt(p.first, p.second, '#');
    head = p;
}

// If element is in bodyset, pops element from both bodyset and bodyqueue.
// then erases the element on the board. 
void Snake::pop(std::pair<int, int> p){
    if (bodyset.find(p) != bodyset.end()){
        bodyset.erase(p);
        bodyqueue.pop();
        b.addAt(p.first, p.second, ' ');
    }
}