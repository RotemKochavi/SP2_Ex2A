#pragma once
#include <iostream>
#include"player.hpp"

namespace ariel
{
    class Game
    {
         private:
        Player &p1, &p2;
        bool isTurn;

        public:
            Game(Player& player1, Player& player2);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            bool getIsTurn();
    };
}