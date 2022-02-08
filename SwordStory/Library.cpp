//
// Created by Payton Hall on 5/3/21.
//

#include "Library.h"

Library::Library() {

}


void Library::makeAbiilties() {

    //Vampiric Strike
    Abilities vamStrike;
    vamStrike.setName("Vampiric Strike");
    vamStrike.setRequirements(12, 18, 0, 0, 0);
    vamStrike.setEffect("Lifesteal");
    vamStrike.setModifier(-1);
    vamStrike.setManaCost(3);
    //cout << "Created " << vamStrike.getName() << endl;
    abilityList.push_back(vamStrike);

}

vector<Abilities> Library::checkUsability(int h, int s, int d, int sp, int m) {
    vector<Abilities> playerCanUse;
    //cout << "Checking new spells " << endl;
    for(int i = 0; i < abilityList.size(); i ++){
        bool check = abilityList.at(i).updateStats(h, s, d, sp, m);

        if(check ){
            playerCanUse.push_back(abilityList.at(i));
            //cout << "You can now use the ability " << abilityList.at(i).getName() << endl;
        }
    }

    return playerCanUse;
}



