//
// Created by Payton Hall on 4/29/21.
//

#ifndef SWORDSTORY_WEAPONS_H
#define SWORDSTORY_WEAPONS_H

#include <iostream>
#include <vector>
using namespace std;
//TODO: WEAPON RARITY:
// Common: P: 1 - 4 M: 1-4
// Uncommon: P: 3 - 7 M: 2-8
// Rare: P: 6 - 12 M: 4 - 14;
// Epic: P: 13 - 21 M: 9 - 26;
// Legendary: P: 22- 32 M: 18 - 36;
class Weapons {
public:
    //sets
    void setName(string);
    void setPhyDamage(int);
    void setMagDamage(int);
    void setCost(int);
    void setPlayerGivenName(string);
    void setType(string);
    void setRarity(string);
    void setQuality(int);

    vector<string> toStringSave();

    void readLoader(vector<string>);
    void loadEquippedW(vector<string>);

    string getName();
    int getPhyDamage();
    int getMagDamage();
    int getCost();
    string getRarity();
    int getQuality();

    string getPlayerGivenName();
    string getType(void);
private:
    string name = "";
    string playerGivenName = "";
    int phyDamage;
    int magDamage;
    int cost;
    string weaponType = "";
    void setPlayerGivenName(int playName);
    string rarity = "";
    int quality = 0;
    void setName(int name);
};


#endif //SWORDSTORY_WEAPONS_H
