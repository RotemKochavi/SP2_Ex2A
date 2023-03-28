#pragma once
#include <iostream>
#include "card.hpp"

using namespacestd;

namespace ariel
{
    class Player
    {
        private:
            string name;
            bool inGame;
            int stackSize;
            int takenCard;

        public:
        string getName(){ return this-> name; }
        bool getInGame() const { return this-> inGame; }
        int stacksize() const { return this-> stackSize; }
        int cardesTaken() const { return this-> takenCard; }
        void setInGame(bool status) {this-> inGame = status; }

        Player(string name);

    };
}