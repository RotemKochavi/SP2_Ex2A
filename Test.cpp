#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test (1) : Game over - 26 turns")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() == 26);
    CHECK(p2.cardesTaken() == 26);
}   

TEST_CASE("Test (2) : Check players's stacks on start")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("Test (3) : Perfect winning of Alice ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    CHECK(p1.cardesTaken() == 26);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Test (4) : Perfect winning of Bob ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 26);
}

TEST_CASE("Test (5) : Printing the winner - Alice ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Test (6) : Printing the winner - Bob ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Test (7) : Printing the winner - No one is winner ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_THROWS(game.printWiner());
}

TEST_CASE("Test (8) : There is no cards ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();
    p1.setInGame(true);
    p2.setInGame(true);

    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Test (9) : Winner post just after game over ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_THROWS(game.printWiner());
}

TEST_CASE("Test (10) :initialization case ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

