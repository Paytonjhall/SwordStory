//
// Created by Payton Hall on 4/30/21.
//

#ifndef SWORDSTORY_ABILITIES_H
#define SWORDSTORY_ABILITIES_H

#include <vector>
#include <iostream>
using namespace std;

class Abilities {
public:

    bool checkAddAbility();
    bool updateStats(int, int, int, int, int);



    //sets
    void setName(string);
    void setEffect(string);
    void setRequirements(int, int, int, int, int);
    void setModifier(int);
    void setManaCost(int);

    //gets
    string getName();
    bool getCanUse();
    string getEffect();
    int getModifier();
    int getManaCost();

private:

    bool canUse = false;
    string effect;
    string name;
    int health;
    int str;
    int def;
    int spd;
    int mag;

    int manaCost;
    int dmgModifier;

    //req
    int reqHealth;
    int reqStr;
    int reqDef;
    int reqSpd;
    int reqMag;

};


#endif //SWORDSTORY_ABILITIES_H
