//
// Created by Payton on 5/2/21.
//

#include "Market.h"

Market::Market() {
    makeStock();
}

void Market::makeStock(){
    //Healing Salve
    Items healSalve;
    healSalve.setName("Healing Salve");
    healSalve.setType("Health");
    healSalve.setCost(20);
    healSalve.setValue(15);
    stock.push_back(healSalve);

    Items manaPotion;
    manaPotion.setName("Mana Potion");
    manaPotion.setType("Mana");
    manaPotion.setCost(30);
    manaPotion.setValue(20);
    stock.push_back(manaPotion);

    Items healGreatSalve;
    healGreatSalve.setName("Greater Healing Salve");
    healGreatSalve.setType("Health");
    healGreatSalve.setCost(120);
    healGreatSalve.setValue(55);
    stock.push_back(healGreatSalve);

}

void Market::shop(vector<Items> &bag, int &totalGold){
   // vector<Items> purchased;
    //urchased = stock;
    cout << "Welcome to the "; printf("\x1b[34mMarket\x1b[0m"); cout << "! Come in and take a look at what we got: " << endl;
    cout << "You currently have " << totalGold << " "; printf("\x1b[33mGold\x1b[0m"); cout << endl;
    //make three new items to sell. and 2 magic ones.
    bool check = false;
    do {
        check = false;

            for (int i = 0; i < stock.size(); i++) {
                cout << "[" << i + 1 << "] ";
                stock.at(i).toString();
                cout << "You currently have " << bag.at(i).getCount() << endl;
                cout << endl;
        }
            cout << endl << "Type a number corresponding to an item that you would like to buy or type end to leave the market: ";
            string input = "";
            cin >> input;
            cout << endl;
        if (input == "end" || input == "End" || input == "'end'" || input == "'End'") {
            //do something
            check = true;
        } else if (input.size() > 1 || input.size() <= 0) {
            cout << "Your input is invalid, please try again" << endl;

        } else if (isdigit(input.at(0))) {
            int add = stoi(input);
            cout << add << endl;
            if(add > stock.size() || add <= 0){
                cout << "The number entered does not correspond with an item, please try again." << endl;
            }
            else if (totalGold >= stock.at(add-1).getCost()) {
                //TODO: ADD ITEM TO PLAYERS STASH
                bag.at(add-1).addItem();
                cout << "You have purchased: " << stock.at(add-1).getName() << endl;
                totalGold = totalGold - stock.at(add-1).getCost();
                cout << "You currently have " << totalGold << " left" << endl;
                cout << "Would you like to purchase anything else?" << endl << endl;
                sleep(waitTime);

            } else {
                cout << "You do not have enough ";
                printf("\x1b[33mGold\x1b[0m");
                cout << " to purchase that item, Sorry" << endl;
            }
            sleep(waitTime);
        }
    }
    while(!check);
    //This is where we will get items for the player to buy.
    //return purchased;
}