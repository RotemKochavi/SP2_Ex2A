#pragma once
#include <iostream>

using namespace std;

namespace ariel
{
    class Card 
    {
        private:
            char suit;
            int value;
        
        public:
            Card(int value, char suit);
            char getSuit() const { return suit; }
            int getValue() const { return value; }

    };
};
