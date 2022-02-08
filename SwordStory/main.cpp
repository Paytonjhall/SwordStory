#include <iostream>
#include <vector>
#include <cstdlib>
#include "Database.h"
#include "Game.h"
#include <stdlib.h>
//TODO: BUGS THAT NEED FIXING:
//Player name can be more than one word.
//pragma comment(lib, "winMM.lib");

//TODO: Things I still need to add:
// Abilities
// Items
// Spells
// Shop --> based on lvl, have certain items at the shop.
// Library
// BlackSmith
// Armor
// Embark
int main() {
    srand (time(NULL));
    using namespace std;
    //Opening dialogue
    cout << "Welcome to Sword Story" << endl;
    cout << "If you have played this game before, you can load your previous save, do this by type 'load'"<< endl;
    cout << "If this is your first time playing, simply type 'start' to start a new story" << endl;
    //play_sound("Filename"); //TODO: THIS IS HOW I WILL PLAY MUSIC I NEED TO GENERATE A HEADER AND A BIANARY
    string input = "";
    do {
        cout << "For more information, type 'help', Good Luck!" << endl;
        cin >> input;
        if (input == "start" || input == "Start") {

           Game game;
           game.newGame();
           return 0;
        } else if (input == "load" || input == "Load") {
            cout << "Please enter the name of the file you would like to load" << endl;
            string name ="";
            cin >> name;
        Game game(name);
        game.load(name);
        cout << "we tried to load" << endl;
        } else if (input == "help" || input == "Help") {
            cout << "type start, then hit enter to start a new game" << endl;
            cout << "type end, then hit enter to close the game" << endl;
            cout << "type load, to load a new game" << endl;
            cout << "This game was created by Payton Hall, paytonjhall@gmail.com" << endl;
        }
        else if(input == "end" || input == "End"){
            cout << "Thanks for playing" << endl;
        }
        else {
            cout << "You some how entered an option that doens't exist, try again." << endl;
        }
    }
    while(input != "end");
    return 0;
}
