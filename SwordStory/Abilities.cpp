//
// Created by Payton Hall on 4/30/21.
//

#include "Abilities.h"


bool Abilities::checkAddAbility() {
    //TODO: run the if statements!
    cout << "rh " << reqHealth;
    cout << " rs " << reqStr;
    cout << " rd " << reqDef;
    cout << " rsp" << reqSpd;
    cout << " rm " << reqMag;
    cout << endl;
    if(health >= reqHealth && str >= reqStr && def >= reqDef && spd >= reqSpd && mag >= reqMag){
        //Gain ability
        cout << "TRUE " << endl;
        canUse = true;
        return canUse;
    }
    else return false;
}

bool Abilities::updateStats(int h, int s, int d, int sp, int m) {
    health = h;
    cout << "h: " << h;
    str = s;
    cout << " s: " << s;
    def = d;
    cout << " d: " << d;
    spd = sp;
    cout << " sp: " << sp;
    mag = m;
    cout << " m: " << m;
    bool usability = checkAddAbility();
    return usability;
}

//sets
void Abilities :: setRequirements(int rh, int rs, int rd, int rsp, int rm){

    reqHealth = rh;
    reqStr = rs;
    reqDef = rd;
    reqSpd = rsp;
    reqMag = rm;
}

void Abilities :: setName(string val){
    name = val;
}

void Abilities ::setEffect(string ef) {
    effect = ef;
}

void Abilities::setModifier(int mod) {
    dmgModifier = mod;
}

void Abilities::setManaCost(int manC) {
    manaCost = manC;
}

//gets
string Abilities::getName(){
    return name;
}

int Abilities::getModifier() {
    return dmgModifier;
}

string Abilities::getEffect() {
    return effect;
}

bool Abilities::getCanUse() {
    return canUse;
}

int Abilities::getManaCost() {
    return manaCost;
}
