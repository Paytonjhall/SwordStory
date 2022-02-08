//
// Created by Payton Hall on 4/30/21.
//

#ifndef SWORDSTORY_GAME_H
#define SWORDSTORY_GAME_H
#include "Player.h"
#include "Combat.h"
#include "Shop.h"
#include "Market.h"
#include "Embark.h"
#include "Library.h"
#include "sound/my_header.h"
#include <iostream>
#include <fstream>

// colors: 0 black, 1 red, green 2, yellow 3, blue 4, magenta 5, cyan 6, white 7.
class Game {
private:

    Player player;
    Combat fights;
    NewGame newgame;
    Shop shop;
    Market market;
    Embark embark;
    //Library library;
public:
    Game();
    Game(string);
    void newGame();
    void town();
    void load(string);
    void save();
};


#endif //SWORDSTORY_GAME_H
