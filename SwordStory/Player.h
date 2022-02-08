//
// Created by Payton Hall on 4/29/21.
//

#ifndef SWORDSTORY_PLAYER_H
#define SWORDSTORY_PLAYER_H
#include <iostream>
#include "NewGame.h"
#include "Weapons.h"
#include "Spells.h"
#include "Abilities.h"
#include "Items.h"
#include "Library.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

//this class will be very large.
//TODO: TEST HEALING DURING BATTLE AND THE MARKET
class Player{
    NewGame game;
private:
    //stats
    string pName;
    int health;
    int str;
    int spd;
    int def;
    int mag;
    int statCap = 7;
    int totStr;
    int totSpd;
    int totDef;
    int totMag;
    int curHealth = 1;
    int totHealth;
    int totMana;
    int curMana;
    int playerLvl = 0;

    //items
    int totalGold = 100;
    int xp = 0;
    int xpLevelUp = 100;
    int lvlUpPoints = 5;





public:
    vector<Weapons> weapons;
    Weapons equiptedWeapon;
    vector<Spells> spellbook;
    vector<Abilities> abilities;
    vector<Items> bag;
    Library library;


    void newGame();
    void giveStartingItems();
    void setStats();
    void calcStatsTut();
    void calcStats();
    void testWeapons();
    void equipItems();
    void toStringWeapons();
    void gainXP(int);
    void lvlUp();

    string saveToString();
    void readLoader(vector<string>);
    void outputStats();
    void restore();

    //Game variables
    int waitTime = 1;


    //gets and sets
    //gets
    int getLvl();
    int getHealth();
    int getStr();
    int getDef();
    int getSpd();
    int getMag();
    int getCurHealth();
    string getName();
    int getWeapons();
    int getCurMana();
    int getGold();
    int getXP();
    int getTotHealth();
    int getTotMana();
    int getCalcSpd();


    //sets
    void addHealth(int);
    void addMana(int);
    void setCurHealth(int);
    void setCurMana(int);
    void useMana(int);
    void addGold(int);
    void setGold(int);
    void lifesteal(int, string);

};


#endif //SWORDSTORY_PLAYER_H
