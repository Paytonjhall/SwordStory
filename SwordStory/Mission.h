//
// Created by Payton on 5/2/21.
//

#ifndef SWORDSTORY_MISSION_H
#define SWORDSTORY_MISSION_H
#include "Player.h"
#include "Combat.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "Enemy.h"

class Mission {
public:
    Combat fight;

    void makeMissName();
    //sets
    void setGold(int);
    void setChall(int);
    void setLeg(int);
    void hasBoss(bool);
    void print();

    //gets
    int getReGold();
    int getChall();
    int getLeg();
    string getMissName();
    bool getBossVal();

    //Mission
    void run(Player &player);

private:

    bool boss = false; //might need to change this value.
    string missName = "";
    int length = 0;
    int challenge = 0;
    int rewardGold = 0;

    //Make variable names, to make custom locations.

};


#endif //SWORDSTORY_MISSION_H
