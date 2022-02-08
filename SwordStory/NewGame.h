//
// Created by Payton Hall on 4/29/21.
//

#ifndef SWORDSTORY_NEWGAME_H
#define SWORDSTORY_NEWGAME_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "Weapons.h"
#include "Shop.h"
using namespace std;
class NewGame {
private:
    int  totalPoints = 20;
    string pName;
    int health;
    int str;
    int spd;
    int def;
    int mag;
    int statCap = 7;
    //int totalGold = 100;
    int waitTime = 0;
public:
    string start();
    void setInfo();
    vector<int> stats();
    vector<Weapons> shop(int&);
    void finTutorial();
};


#endif //SWORDSTORY_NEWGAME_H
