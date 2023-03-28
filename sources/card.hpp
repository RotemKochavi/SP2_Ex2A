#pragma once
#include <iostream>

using namespace std;

namespace ariel
{
    class Card 
    {
        private:
            char suit;
            int rank;
        
        public:
            Card(int value, char suit);
            char get_Suit() const { return suit; }
            int get_Value() const { return value; }

    };
};
