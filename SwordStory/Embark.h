//
// Created by Payton on 5/2/21.
//

#ifndef SWORDSTORY_EMBARK_H
#define SWORDSTORY_EMBARK_H
#include "Player.h"
#include "Mission.h"
#include <iostream>
#include <vector>

class Embark {
public:

    Mission miss;
    void startMish(Player &player);
    vector<Mission> makeMissions(Player &player);
    void printMiss(Mission);

    //starting

private:






};


#endif //SWORDSTORY_EMBARK_H
