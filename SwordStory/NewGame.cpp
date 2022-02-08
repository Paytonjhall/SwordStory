//
// Created by Payton Hall on 4/29/21.
//

#include "NewGame.h"

string NewGame :: start(){

    cout << "Welcome to Sword Story!" << endl;
    cout << "Please enter your name, hero: ";
    string name = "";
    cin >> name;
    pName = name;
    return name;
}

vector<int> NewGame :: stats(){
    // colors: 0 black, 1 red, green 2, yellow 3, blue 4, magenta 5, cyan 6, white 7.
    cout << pName << ", you now have the option to set your stats. You are given "<< totalPoints<<" points to add to the following categories:" << endl;
    sleep(waitTime);
    printf("\x1b[32m Health: this is how much health you have. If it falls to 0 you die. \x1b[0m  \n");
    sleep(waitTime);
    printf("\x1b[31m Strength: this how much physical damage you will deal to enemies. \x1b[0m  \n");
    sleep(waitTime);
    printf("\x1b[34m Defense: this is how much physical damage you will block each time you take damage. \x1b[0m  \n");
    sleep(waitTime);
    printf("\x1b[33m Speed: this will affect will strikes first in battles as well as evasion. \x1b[0m  \n");
    sleep(waitTime);
    printf("\x1b[35m Magic: this will affect how much magic damage you deal as well as your mana \x1b[0m  \n");
    sleep(waitTime);
    bool check = false;
    do{
        int points = totalPoints;
         cout << "You may assign up to " << statCap << " points into each slot, but remember, you are only given " << totalPoints << " and each spot must have at least 1 point in it" << endl;

         cout << "How many points would you like to assign:" << endl;
         printf("\x1b[32m Health \x1b[0m");
         cout << ": ";
         cin >> health;
         cout << endl;
         points= points - health;
         cout << "You have " << points << " points remaining" << endl;

         cout << "How many points would you like to assign:" << endl;
         printf("\x1b[31m Strength \x1b[0m");
         cout << ": ";
         cin >> str;
         cout << endl;
         points= points - str;
        cout << "You have " << points << " points remaining" << endl;

         cout << "How many points would you like to assign:" << endl;
         printf("\x1b[34m Defense \x1b[0m");
         cout << ": ";
         cin >> def;
         cout << endl;
         points= points - def;
        cout << "You have " << points << " points remaining" << endl;

         cout << "How many points would you like to assign:" << endl;
         printf("\x1b[33m Speed \x1b[0m");
         cout << ": ";
         cin >> spd;
         cout << endl;
         points= points - spd;
        cout << "You have " << points << " points remaining" << endl;

         cout << "How many points would you like to assign:" << endl;
         printf("\x1b[35m Magic \x1b[0m");
         cout << ": ";
         cin >> mag;
         cout << endl;
         points = points - mag;
        cout << "You have " << points << " points remaining" << endl;

         int total = health + str + def + spd + mag;

         if(total > totalPoints){
             cout << "You used too many points, please try again, here are the rules: " << endl;
         }
         else if(total < totalPoints){
             cout << "You didn't use all your points, please try again from the top, here are the rules: " << endl;
         }

         else if(str > statCap || health > statCap || def > statCap || spd > statCap || mag > statCap){
                 cout << "One of your chosen stats are above " << statCap << ", you have to pick a value equal or below that, here are the rules" << endl;
         }
         else if(str < 1 || health < 1 || def < 1 || spd < 1 || mag < 1){
             cout << "You have stats that are either negative or 0, you must have at least 1 point in a stat. Here are the rules again: " << endl;
         }
         else{
             check = true;
         }
    }
    while(!check);

    vector<int> stats;
    stats.push_back(health);
    stats.push_back(str);
    stats.push_back(def);
    stats.push_back(spd);
    stats.push_back(mag);

    return stats;
}


vector<Weapons> NewGame::shop(int &gold){
    vector<Weapons> purchased;
    Shop shop;
    purchased  = shop.begShop(pName, gold);
    return purchased;
}


void NewGame::finTutorial() {
    cout << endl << endl;
    cout << "Now that you have finished the tutorial, the Town is now available. You can save, shop, upgrade, and embark on adventures here." << endl;
    cout << "You will be given a list of options to choose from. I would suggest stocking up on supplies before going anywhere sketchy though!" << endl;

    

}


