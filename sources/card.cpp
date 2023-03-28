#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;

namespace ariel
{
    Card:: Card(int value, char suit)
    {
        this->suit = suit;
        this->value = value;
        
    }
}