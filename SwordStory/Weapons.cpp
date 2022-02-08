//
// Created by Payton Hall on 4/29/21.
//

#include "Weapons.h"

vector<string> Weapons::toStringSave() {
    vector<string> sender;
    string save = name;
    sender.push_back(save);
    save += weaponType;
    sender.push_back(save);
    save += phyDamage;
    sender.push_back(save);
    save += magDamage;
    sender.push_back(save);
    save += cost;
    sender.push_back(save);
    save += rarity;
    sender.push_back(save);
    save+= quality;
    sender.push_back(save);
    //Going to need to change this when I add rarity / stars
    return sender;
}

void Weapons::readLoader(vector<string> vals) {
    name = vals.at(0);
    weaponType = vals.at(1);
    phyDamage = stoi(vals.at(2));
    magDamage = stoi(vals.at(3));
    cost = stoi(vals.at(4));
    rarity = vals.at(5);
    quality = stoi(vals.at(6));
}

void Weapons::loadEquippedW(vector<string> vals) {
    name = vals.at(0);
    weaponType = vals.at(1);
    phyDamage = stoi(vals.at(2));
    magDamage = stoi(vals.at(3));
    cost = stoi(vals.at(4));
    rarity = vals.at(5);
    quality = stoi(vals.at(6));
}


void Weapons::setCost(int cost){
    this->cost = cost;
}

void Weapons::setPhyDamage(int dam){
    phyDamage = dam;
}

void Weapons::setMagDamage(int dam){
    magDamage = dam;
}

void Weapons::setName(string name){
    this->name = name;
}

void Weapons::setPlayerGivenName(int playName) {
    playerGivenName = playName;
}

void Weapons::setType(string typ){
    weaponType = typ;
}

void Weapons::setRarity(string rar){
    rarity = rar;
}

void Weapons::setQuality(int qual) {
    quality = qual;
}


int Weapons ::getCost() {
    return cost;
}

int Weapons::getPhyDamage() {
    return phyDamage;
}

int Weapons::getMagDamage(){
    return magDamage;
}

string Weapons:: getName(){
    return name;
}

string Weapons:: getType(){
    return weaponType;
}

string Weapons::getRarity() {
    return rarity;
}

int Weapons::getQuality() {
    return quality;
}