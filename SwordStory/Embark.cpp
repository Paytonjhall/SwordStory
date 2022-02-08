//
// Created by Payton on 5/2/21.
//

#include "Embark.h"

void Embark::startMish(Player &player){
    cout << endl << endl << "Welcome to towns mission board, here you can select a mission to go on." << endl;
    cout << "Each mission is challenging but some will have harder enemies than others. You will receive rewards upon completing a mission: " << endl;
    cout << "Please select a mission from below: " << endl;

    vector<Mission> misslist;
    misslist = makeMissions(player);
    for(int i = 0; i < misslist.size(); i ++) {
        cout << "[" << i+1 << "]: " ;
        misslist.at(i).print();
    }
    cout << "Your health is: " << player.getCurHealth() << endl;
    cout << "Which mission would you like to choose? Please enter the name of the mission or the correlating number: ";
    string input = "";
    cin >> input;
    int select = 0;
    if(isdigit(input.at(0))){
        select = stoi(input);
    }

    misslist.at(select-1).run(player);

    cout << "Returning back to town. " << endl;

}

void Embark::printMiss(Mission miss) {
    miss.print();
}

vector<Mission> Embark::makeMissions(Player &player) {
    vector<Mission> missBoard;
    for(int i = 0; i < 3; i++){
        //Just need to set a name.
        Mission post;
        //leg
        int leg = rand()%3 + 3;
        post.setLeg(leg);
        //boss?
        int bossVal = rand() % 5;
        if(bossVal == 0)    post.hasBoss(true);
        else    post.hasBoss(false);
        //diff
        int challenge = rand() % 5 + 5;
        challenge = challenge * player.getLvl();
        challenge = challenge/80; //or so idk?
        post.setChall(challenge);
        //gold
        int gold  = rand() % 25 + (65 + 155 * challenge * .75);
        post.setGold(gold);
        missBoard.push_back(post);
    }
return missBoard;
}