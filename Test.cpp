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

TEST_CASE("Test (11) : 5 turns ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    for( int i=0; i<5; i++)
        game.playTurn();

    game.printLastTurn();
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.stacksize() == 21);
    CHECK(p2.stacksize() == 21);
}

TEST_CASE("Test (12) :2 players have the same name")
{
    Player p1("Alice");
    
    CHECK_THROWS(Game{ p1,p1});
}

TEST_CASE("Test (13) :There is no name to player 1 ")
{
    Player p1("");
    Player p2("Bob");

    CHECK_THROWS( Game {p1,p2});
}

TEST_CASE("Test (14) :There is no name to player 2 ")
{
    Player p1("Alice");
    Player p2("");

    CHECK_THROWS( Game {p1,p2});
}

TEST_CASE("Test (15) :player can play only in one game at the same time")
{
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Cami");
    Game game(p1,p2);
    
    CHECK_THROWS(Game(p2,p3));
}

TEST_CASE("Test (16) :if the stacks works OK ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    for( int i=0; i<5; i++)
        game.playTurn();
    
    CHECK(p2.stacksize() <=21);
}

TEST_CASE("Test (17) :if the cards taken works OK ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

     for( int i=0; i<5; i++)
        game.playTurn();
    
    CHECK((p1.cardesTaken() !=0) || (p2.cardesTaken() !=0));
}

TEST_CASE("Test (18) : there is no cards")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();
    p1.setInGame(true);
    p2.setInGame(true);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Test (19) :have the same number of cards after one turn")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playTurn();

    CHECK( p1.stacksize() == p2.stacksize() );
}

TEST_CASE("Test (20) : play turn check ")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();
    CHECK_THROWS(game.playTurn());
}

