#include <iostream>
#include <stdexcept>
#include "game.hpp"

using namespace ariel;
using namespace std;

namespace ariel
{
    Game::Game(Player& player1, Player &player2) : p1(player1),p2(player2)
    {
        this->p1 = player1;
        this->p2 = player2;
        this->isTurn = false;
    }
    void Game::playTurn(){}
   
    void Game::printLastTurn(){}
   
    void Game::playAll(){}
    
    void Game::printWiner(){}
    
    void Game::printLog(){}
    
    void Game::printStats(){}

    bool Game::getIsTurn(){ return this-> isTurn;}

}