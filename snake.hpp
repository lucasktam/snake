#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <ncurses.h>
#include <queue> 
#include <unordered_set>
#include <utility>
#include "board.hpp"

// Custom hash function for std::pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

// If direction + new direction == 0, then they're opposites. 
enum Direction{
    up = -1,
    down = 1,
    left = -2,
    right = 2,
};

class Snake{
public:
    // default initializer - place holder for now. 
    Snake(Board b);

    // initializes length and direction to parameters
    Snake(Board b, int l, Direction d);

    // Pops the tail (front value)
    // Pushes a new head piece 
    void move();

    // changes direction to set direction - ignoring opposites
    void changeDirection(Direction d);
    
    // returns direction 
    Direction getDirection();

    // pushes an element into both bodyqueue and bodyset. 
    // Then resets head. 
    void push(std::pair<int, int> p);

    // If element is in bodyset, pops element from both bodyset and bodyqueue.
    // then erases the element on the board. 
    void pop(std::pair<int, int> p);

private:
    Board board;
    int length;
    Direction direction;
    std::queue<std::pair<int, int>> bodyqueue;
    std::unordered_set<std::pair<int,int>, pair_hash> bodyset; 
    
    // The head is the back element of the queue.
    std::pair<int,int> head;
};

#endif