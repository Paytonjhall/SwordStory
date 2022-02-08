//
// Created by Payton Hall on 4/29/21.
//
//WORKS
#ifndef SWORDSTORY_SHOP_H
#define SWORDSTORY_SHOP_H
#include "Weapons.h"
#include "Items.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;

//TODO: WORKS, NEED TO ADD CONSUMABLE ITEMS.
class Shop {
public:
    Shop();

    Weapons makeCommon();
    Weapons makeMagicCommon();
    Weapons makeUncommon();
    Weapons makeMagicUncommon();
    Weapons makeRare();
    Weapons makeMagicRare();
    Weapons makeEpic();
    Weapons makeMagicEpic();
    Weapons makeLegendary();
    Weapons makeMagicLegendary();
    void toString(Weapons);
    vector<Weapons> begShop(string, int&); //Check if passing by reference works here for gold count
    vector<Weapons> townShop(int, string, int&);


    //game variables:
    int waitTime = 1;

private:
    vector<string> weaponNames = {"Axe", "Sword", "Mace", "Bowstaff", "Spear", "Lance", "Blade", "Claymore", "Knife", "Katana"};
    vector<string> magicNames = {"Tomb of", "Staff of", "Wand of", "Book of", "Candle of", "Knife of"};
    vector<string> commonAdj = {"Sharp", "Quick", "Hurtful", "Average", "Dainty", "Nice", "Secure", "Pointy", "Flat", "Long", "Ancient", "Stone", "Wild", "Used", "Brittle", "Light", "Slim"};
    vector<string> magCommonAdj = {" Hurting", " Pain", " the Wicked", " Woe", " Sorcery", " Magic", " Evil", " Light", " Dark", " Blight"};
    vector<string> uncommonAdj = {"Sharp", "Quick", "Hurtful","Nice", "Secure", "Pointy", "Fine", "Sweet"};
    vector<string> magUncommonAdj{" Rage", " Confusion", " Spite", " Woe", " Sorcery", " Magic", " Evil", " Knowledge", " Justice"};
    vector<string> rareAdj = {"Iron", "Well-Made", "Intense", "Extreme", "Pretty", "Steel", "Precise", "Incredible", "Flawless", "Remarkable", "Rare", "Deadly"};
    vector<string> magRareAdj{" Death", " Killing", " Dark Magic", " Light Magic", " Mysticism", " Dread", " Death", " Summoning"};
    vector<string> epicAdj = {"Immense", "Incredible", "Diamond", "Gold", "Gorgeous", "Perfect", "Epic", "Un-human", "Deadly", "Piercing", "Bloody"};
    vector<string> magEpicAdj = {" Icor", " Serenity", " the Unholy", " the Lich King", " the Undead", " Massacre", " Consciousness", " Blight"};
    vector<string> legendaryAdj = {"Perfect", "Godly", "Opal", "Heavenly", "Demonic", "Unholy", "Legendary", "Divine", "Killer", "Insane", "Maddening"};
    vector<string> magLegendaryAdj = {" the Gods", " the Goddess", " All Knowing", " All Seeing", " Massacre", " the Demon", " The Demon King", " Blights End", " Death Reborn", " the Cherbim", " the Holy Sentinels"};
};


#endif //SWORDSTORY_SHOP_H
