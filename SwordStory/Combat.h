//
// Created by Payton Hall on 4/30/21.
//

#ifndef SWORDSTORY_COMBAT_H
#define SWORDSTORY_COMBAT_H
#include "Player.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "Enemy.h"
using namespace std;
class Combat {
private:
    //Player player;
    Enemy enemy;
    int tutorialTimer = 0;
public:

    void fightTutorial(Player&);
    void createEnemy(int);
    void startCombat(Player&, Enemy&);
    bool checkDead(Player&, Enemy&);
    void printOptions(Player&);
    void playerAttack(int, int, Enemy&, Player&);
    void enemyAttack(int, Player&, Enemy&);
    int calcDamage (int, int);
    void examine(Player&, Enemy&);
    void printEnemyInfo(Enemy&);
    void attackWAbility(Player&, Enemy&, int);
};


#endif //SWORDSTORY_COMBAT_H
