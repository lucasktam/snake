#include "game.hpp"

using namespace std; 

Game::Game(){
    status = 0;
}

void Game::start(){
    status = 1;
}

void Game::end(){
    status = 0;
}

int Game::getStatus() const{
    return status; 
}