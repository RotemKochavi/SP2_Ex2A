#include "player.hpp"

namespace ariel
{
    Player::Player(string name)
    {
        this->name = name;
        this-> stackSize = 26;
        this-> takenCard = 0;
    }
}