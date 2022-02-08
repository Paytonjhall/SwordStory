//
// Created by Payton Hall on 4/30/21.
//

#include "Enemy.h"
void Enemy::createTutEnemy() {
    int i = rand() % (enemyNames.size()-1);
    int j = rand() % (commonAdj.size()-1);
    name = commonAdj.at(j) + enemyNames.at(i) ;

    //Health
    health = (rand() % 2) +1;
    xp += health;
    //Str
    str = (rand() % 2) + 1;
    xp += str;
    //Def
    def = (rand() % 2) + 2;
    xp += def;
    //spd
    spd = (rand() % 2) + 2;
    xp += spd;
    //mag
    mag = (rand() % 2) + 1;
    xp += mag;
    xp *= 1.7;
    gold = ((rand() % xp/2) + xp/2) + ((rand()%20) - 5);
    calcStats();


}

void Enemy::createEnemy(int lvl) {
    //Make each enemy have a specialty.
    int i = rand() % (enemyNames.size()-1);
    int j = rand() % (commonAdj.size()-1);
    name = commonAdj.at(j) + enemyNames.at(i) ;

    //Health
    health = (rand() % 2) + 2 * (1+lvl);
    xp += health;
    //Str
    str = (rand() % 3) + 2 * (1+lvl);
    xp += str;
    //Def
    def = (rand() % 3) + 2 * (1+lvl);
    xp += def;
    //spd
    spd = (rand() % 3) + 1 * (1+lvl);
    xp += spd;
    //mag
    mag = (rand() % 2) + 1 * (1+lvl);
    xp += mag;
    xp *= 1.45;
    gold = ((rand() % xp/2) + xp/2) + ((rand()%20) - 10);
    calcStats();
}


void Enemy:: calcStats(){
    //TODO: Here will be all the equations for getting your in game stats. Recalc after each level up.
    totHealth = health * 2 + 8;
    curHealth = totHealth;
    totStr = str; //Weapon damage dramatically changes this value
    totDef = def; //def is a little different, you simply find a random number between 0 and the def, and subtract that from incoming damage.
    totSpd = spd * 2 + 1;
    totMag = mag; //Spell damage dramatically changes this value.
    totMana = mag * 2 + 5;
}

string Enemy:: getName(){
    return name;
}

vector<int> Enemy:: getStats(){
    vector<int>stats;
    stats.push_back(health);
    stats.push_back(str);
    stats.push_back(def);
    stats.push_back(spd);
    stats.push_back(mag);

    return stats;
}

//TODO: Gets and Sets
//gets
int Enemy::getHealth(){
    return health;
}

int Enemy::getStr(){
    return str;
}

int Enemy::getDef(){
    return def;
}

int Enemy::getSpd(){
    return spd;
}

int Enemy::getMag(){
    return mag;
}

int Enemy::getCurHealth(){
    return curHealth;
}

int Enemy:: getXP(){
    return xp;
}

int Enemy:: getGold(){
    return gold;
}

int Enemy:: getTotHealth(){
    return totHealth;
}

int Enemy::getTotSpd() {
    return totSpd;
}

//sets
void Enemy::setCurHealth(int val){
    curHealth = val;
}
