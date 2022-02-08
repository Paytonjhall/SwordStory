//
// Created by Payton Hall on 4/30/21.
//

#ifndef SWORDSTORY_ENEMY_H
#define SWORDSTORY_ENEMY_H

#include <iostream>
#include <vector>

using namespace std;
class Enemy {
private:
    string name = "";
    vector<string> enemyNames = {"Skeleton", "Zombie", "Witch", "Undead", "Rogue", "Ninja", "Thief", "Demon", "Beast", "Mummy", "Ent", "Monster", "Yeti"};
    vector<string> commonAdj = {"Ugly ", "Monstrous ", "Huge ", "Demonic ", "Unholy ", "Deadly ", "Scary ", "Sickly ", "Wicked ", "Gnarly ", "Creepy ", "Old ", "Corrupted ", "Hairy "};
    int health;
    int str;
    int spd;
    int def;
    int mag;
    int totStr;
    int totSpd;
    int totDef;
    int totMag;
    int totHealth;
    int totMana;
    int xp = 0;
    int curHealth = 1;
    int gold = 0;

public:
    void createEnemy(int lvl);
    void createTutEnemy();
    void calcStats();

    //gets
    string getName();
    vector<int> getStats();
    int getHealth();
    int getTotHealth();
    int getStr();
    int getDef();
    int getSpd();
    int getMag();
    int getCurHealth();
    int getXP();
    int getGold();
    int getTotSpd();
    //sets
    void setCurHealth(int);

};


#endif //SWORDSTORY_ENEMY_H
