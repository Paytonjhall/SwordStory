//
// Created by Payton on 5/2/21.
//

#include "Mission.h"



void Mission::run(Player &player){

    int constLvl = player.getLvl();
    //fights loop:
    for(int i = 1; i < length + 1; i++) {
        cout << "You encounter enemy number " << i << " : " << endl;
        Enemy enemy;
        enemy.createEnemy(constLvl);
        fight.startCombat(player, enemy);
    }

    if(boss){
        //run create boss and fight boss command
    }

    cout << "You have successfully cleared this mission! " << endl;
    cout << "Upon returning home, you receive the promised gold for completing the mission " << endl;
    cout << "You have been give " << rewardGold << " Gold" << endl;

    player.addGold(rewardGold);

    cout << "You now have " << player.getGold() << " Gold!" << endl;

}
















//Make a name for the mission, use the premade names.
void Mission::makeMissName() {

}

void Mission::print(){
    cout << "Mission Name: " << missName << endl;
    cout << "Mission Length: " << length << endl;
    cout << "Mission Difficulty: ";
    for(int i = 0; i < challenge; i++) cout << "*";
    cout << endl;
    cout << "Mission Reward: " << rewardGold << " Gold" << endl;
    if(boss) cout << "This mission has a boss." << endl;
    else cout << "This mission doesn't have a boss." << endl;
    cout << endl;
}


//sets

void Mission::setChall(int chal){
    challenge = chal;
}

void Mission::setGold(int gold) {
    rewardGold = gold;
}

void Mission::setLeg(int leg){
    length = leg;
}

void Mission::hasBoss(bool val) {
    boss = val;
}




//getds
int Mission::getChall() {
    return challenge;
}

int Mission::getLeg() {
    return length;
}

int Mission::getReGold() {
    return rewardGold;
}

string Mission::getMissName() {
    return missName;
}

bool Mission::getBossVal() {
    return boss;
}