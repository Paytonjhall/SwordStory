//
// Created by Payton Hall on 4/29/21.
//

#include "Shop.h"
// colors: 0 black, 1 red, green 2, yellow 3, blue 4, magenta 5, cyan 6, white 7.
//EVERYTHING COSTS THE SAME IN BEG SHOP
Shop::Shop(){
    //Create consumable items:

}

void Shop:: toString(Weapons item){
cout << "Weapon Name: " << item.getName() << endl;
cout << "Rarity: " << item.getRarity() << endl; //TODO: ADD COLOR
cout << "Weapon Type: ";
if(item.getType()=="Physical") printf("\x1b[31m Physical\x1b[0m\n");
else printf("\x1b[36m Magical\x1b[0m\n");
cout << "Cost: " << item.getCost() << endl;
cout << "Average Physical Damage Bonus: "; printf("\x1b[31m%d\x1b[0m\n",item.getPhyDamage() );
cout << "Average Magical Damage Bonus: "; printf("\x1b[36m%d\x1b[0m\n",item.getMagDamage() );
}

//make items: common
Weapons Shop:: makeCommon(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Common");
    unsigned int i = rand() % (weaponNames.size());
    int j = rand() % (commonAdj.size());
    string name = commonAdj.at(j) + " " + weaponNames.at(i);
    item.setName(name);

    int dam = rand() % 2 + 2;
    dam = dam + (rand() % 2);
    item.setPhyDamage(dam);

    int magDam = rand() % 2;
    item.setMagDamage(magDam);

    int cost = 21;
    int add = rand() % 5;
    add = (add+1) * dam;
    cost = cost + add;
    item.setCost(cost);

    item.setType("Physical");

    return item;
}

Weapons Shop:: makeMagicCommon(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Common");
    int i = rand() % (magicNames.size());
    int j = rand() % (magCommonAdj.size());
    string name = magicNames.at(i) + magCommonAdj.at(j);
    item.setName(name);

    int dam = rand() % 1;
    item.setPhyDamage(dam);

    int magDam = (rand() % 4 ) + 1;
    item.setMagDamage(magDam);

    int cost = 25;
    int add = rand() % 4;
    add = (add+1) * magDam;
    cost = cost + add;
    item.setCost(cost);


    item.setType("Magical");

    return item;
}

//Make items: uncommon
Weapons Shop:: makeUncommon(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Uncommon");
    int i = rand() % (weaponNames.size());
    int j = rand() % (uncommonAdj.size());
    string name = uncommonAdj.at(j) + " " + weaponNames.at(i);
    item.setName(name);

    int dam = (rand() % 5) + 3;
    item.setPhyDamage(dam);

    int magDam = (rand() % 2) + 1;
    item.setMagDamage(magDam);

    int cost = 88;
    int add = rand() % 5;
    add = (add+1) * dam;
    cost = cost + add;
    item.setCost(cost);

    item.setType("Physical");

    return item;
}

Weapons Shop:: makeMagicUncommon(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Uncommon");
    int i = rand() % (magicNames.size());
    int j = rand() % (magUncommonAdj.size());
    string name = magicNames.at(i) + magUncommonAdj.at(j);
    item.setName(name);

    int dam = rand() % 1;
    item.setPhyDamage(dam);

    int magDam = (rand() % 7 ) + 2;
    item.setMagDamage(magDam);

    int cost = 92;
    int add = rand() % 5;
    add = (add+2) * magDam;
    cost = cost + add;
    cost += ((rand()  % 10) -5);
    item.setCost(cost);


    item.setType("Magical");

    return item;
}

//Make items: Rare
Weapons Shop:: makeRare(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Rare");
    int i = rand() % (weaponNames.size());
    int j = rand() % (rareAdj.size());
    string name = rareAdj.at(j) + " " + weaponNames.at(i);
    item.setName(name);

    int dam = (rand() % 7) + 6;
    item.setPhyDamage(dam);

    int magDam = (rand() % 2) + 3;
    item.setMagDamage(magDam);

    int cost = 245;
    int add = rand() % 7;
    add = (add+1) * dam;
    cost = cost + add;
    item.setCost(cost);

    item.setType("Physical");

    return item;
}

Weapons Shop:: makeMagicRare(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Rare");
    int i = rand() % (magicNames.size());
    int j = rand() % (magRareAdj.size());
    string name = magicNames.at(i) + magRareAdj.at(j);
    item.setName(name);

    int dam = rand() % 1;
    item.setPhyDamage(dam);

    int magDam = (rand() % 11 ) + 4;
    item.setMagDamage(magDam);

    int cost = 256;
    int add = rand() % 7;
    add = (add+2) * magDam;
    cost = cost + add;
    cost += ((rand()  % 10) -5);
    item.setCost(cost);


    item.setType("Magical");

    return item;
}

//Make items: Epic
Weapons Shop:: makeEpic(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Epic");
    int i = rand() % (weaponNames.size());
    int j = rand() % (epicAdj.size());
    string name = epicAdj.at(j) + " " + weaponNames.at(i);
    item.setName(name);

    int dam = (rand() % 9) + 13;
    item.setPhyDamage(dam);

    int magDam = (rand() % 4) + 3;
    item.setMagDamage(magDam);

    int cost = (rand() % 50) + 660;
    int add = rand() % 10 + 5;
    add = (add+1) * dam;
    cost = cost + add;
    item.setCost(cost);

    item.setType("Physical");

    return item;
}

Weapons Shop:: makeMagicEpic(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Epic");
    int i = rand() % (magicNames.size());
    int j = rand() % (magEpicAdj.size());
    string name = magicNames.at(i) + magEpicAdj.at(j);
    item.setName(name);

    int dam = rand() % 2;
    item.setPhyDamage(dam);

    int magDam = (rand() % 18 ) + 9;
    item.setMagDamage(magDam);

    int cost = (rand() % 90) + 630;
    int add = (rand() % 10) + 4;
    add = (add+2) * magDam;
    cost = cost + add;
    cost += ((rand()  % 10) -5);
    item.setCost(cost);

    item.setType("Magical");

    return item;
}

//Make items: Legendary
Weapons Shop:: makeLegendary(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Epic");
    int i = rand() % (weaponNames.size());
    int j = rand() % (legendaryAdj.size());
    string name = legendaryAdj.at(j) + " " + weaponNames.at(i);
    item.setName(name);

    int dam = (rand() % 17) + 16;
    item.setPhyDamage(dam);

    int magDam = (rand() % 8) + 4;
    item.setMagDamage(magDam);

    int cost = (rand() % 150) + 1160;
    int add = rand() % 10 + 5;
    add = (add+1) * dam;
    cost = cost + add;
    item.setCost(cost);

    item.setType("Physical");

    return item;
}

Weapons Shop:: makeMagicLegendary(){
    //srand (time(NULL));
    Weapons item;
    item.setRarity("Legendary");
    int i = rand() % (magicNames.size());
    int j = rand() % (magLegendaryAdj.size());
    string name = magicNames.at(i) + magLegendaryAdj.at(j);
    item.setName(name);

    int dam = rand() % 10;
    item.setPhyDamage(dam);

    int magDam = (rand() % 19 ) + 18;
    item.setMagDamage(magDam);

    int cost = (rand() % 190) + 1230;
    int add = (rand() % 10) + 4;
    add = (add+2) * magDam;
    cost = cost + add;
    cost += ((rand()  % 10) -5);
    item.setCost(cost);

    item.setType("Magical");

    return item;
}



vector<Weapons> Shop::begShop(string pName, int &totalGold) {
    //Fix randomness on items.
    //srand (time(NULL));
    vector<Weapons> purchased;
    vector<Weapons> store;
    cout << pName << ", Now that you have your stats, its time to prepare for your adventure!" << endl;
    cout << "There is no better way to prepare than to spend your gold at the "; printf("\x1b[33mShop\x1b[0m"); cout << "!" << endl;
    cout << "Looks like you have " << totalGold; printf("\x1b[33m Gold\x1b[0m"); cout << " already. That's a good start, you will earn more gold throughout your adventures" << endl << endl;
    printf("\x1b[33m Shop\x1b[0m"); cout << ":" << endl;
    //make three new items to sell. and 2 magic ones.
    for(int i = 0; i < 5; i ++){
        if(i<3)store.push_back(makeCommon());
        else store.push_back(makeMagicCommon());
    }
    bool check = false;
    do {
        check = false;
        if(store.size() == 0){
            cout << "There is currently nothing left in the store. " << endl << "Please type end to continue. " << endl;
        }
        else {
            for (int i = 0; i < store.size(); i++) {

                cout << "[" << i + 1 << "] ";
                toString(store.at(i));
                cout << endl;
            }

            cout << "Would you like to purchase any of these weapons? If so, please enter the number for that item.";
            cout << " If no item is wanted, type 'end': ";
        }
        string input = "";
        cin >> input;
        if (input == "end" || input == "End" || input == "'end'" || input == "'End'") {
            //do something
            check = true;
        } else if (input.size() > 1 || input.size() <= 0) {
            cout << "Your input is invalid, please try again" << endl;

        } else if (isdigit(input.at(0))) {
            int add = stoi(input);
            cout << add << endl;
            if(add > 5 || add <= 0){
                cout << "The number entered does not correspond with an item, please try again." << endl;
            }
            else if (totalGold >= store.at(add-1).getCost()) {

                purchased.push_back(store.at(add-1));
                cout << "You have purchased: " << store.at(add-1).getName() << endl;
                totalGold = totalGold - store.at(add-1).getCost();
                cout << "You currently have " << totalGold << " left" << endl;
                store.erase(store.begin() + add-1);
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
    return purchased;
}



//Common, lvls 1 -5 fills rest of spots
//UnCommon 5 - 10 max 3
//Rare 10 - 15 max 3
//Epic 15- 20 max 2
//Legenedary 20 - 25 max 1
vector<Weapons> Shop::townShop(int playerLvl, string pName, int &totalGold){
    //srand (time(NULL));
    cout << "Welcome to the "; printf("\x1b[33m Shop\x1b[0m"); cout << ":" << endl;
    cout << "Your "; printf("\x1b[33mGold\x1b[0m"); cout << ": " << totalGold << endl;
    vector<Weapons> purchased;
    vector<Weapons> store;






    //THIS IS THE TOWN SHOP, It will post different items. Have it sell pretty medicore stuff.

    for(int i = 0; i < 9; i ++){
        int wRarityUn = 5 * (playerLvl - 4);
        int wRarityRa = 4 * (playerLvl - 9);
        int wRarityEp = 3 * (playerLvl - 14);
        int wRarityLeg = 2 * (playerLvl - 19);
        bool un = false;
        bool ra = false;
        bool ep = false;
        bool leg = false;
        if(rand() % 100 <=  wRarityUn) un = true;
        if(rand() % 100 <=  wRarityRa) ra = true;
        if(rand() % 100 <=  wRarityEp) ep = true;
        if(rand() % 100 <=  wRarityLeg) leg = true;



        if(i<5){
            if(leg){
                store.push_back(makeLegendary());
            }
            else if(ep){
                store.push_back(makeEpic());
            }
            else if(ra){
                store.push_back(makeRare());
            }
            else if(un){
                store.push_back(makeUncommon());
            }
            else{
                store.push_back(makeCommon());
            }

        }

        else {
            if(leg){
                store.push_back(makeMagicLegendary());
            }
            else if(ep){
                store.push_back(makeMagicEpic());
            }
            else if(ra){
                store.push_back(makeMagicRare());
            }
            else if(un){
                store.push_back(makeMagicUncommon());
            }
            else{
                store.push_back(makeMagicCommon());
            }
             //Change this part based on lvl, not common, a spectrum
        }
    }
    bool check;
    do {
        check = false;
        if(store.size() == 0){
            cout << "There is currently nothing left in the store. " << endl << "Please type end to continue. " << endl;
        }
        else {
            for (int i = 0; i < store.size(); i++) {

                cout << "[" << i + 1 << "] ";
                toString(store.at(i));
                cout << endl;
            }

            cout << "Would you like to purchase any of these weapons? If so, please enter the number for that item.";
            cout << " If no item is wanted, type 'end': ";
        }
        string input = "";
        cin >> input;
        if (input == "end" || input == "End" || input == "'end'" || input == "'End'") {
            //do something
            check = true;
        } else if (input.size() > 1 || input.size() <= 0) {
            cout << "Your input is invalid, please try again" << endl;

        } else if (isdigit(input.at(0))) {
            int add = stoi(input);
            cout << add << endl;
            if(add > store.size() || add <= 0){
                cout << "The number entered does not correspond with an item, please try again." << endl;
            }
            else if (totalGold >= store.at(add-1).getCost()) {

                purchased.push_back(store.at(add-1));
                cout << "You have purchased: " << store.at(add-1).getName() << endl;
                totalGold = totalGold - store.at(add-1).getCost();
                cout << "You currently have " << totalGold << " left" << endl;
                store.erase(store.begin() + add-1);
                cout << "Would you like to purchase anything else?" << endl << endl;
                sleep(waitTime + 1);

            } else {
                cout << "You do not have enough ";
                printf("\x1b[33mGold\x1b[0m");
                cout << " to purchase that item, Sorry" << endl;
            }
            sleep(waitTime + 1);
        }
    }
    while(!check);
    //This is where we will get items for the player to buy.
    return purchased;

}