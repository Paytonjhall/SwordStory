//
// Created by Payton Hall on 4/30/21.
//

#include "Game.h"

Game::Game(string name){
    load(name);
}
Game::Game(){
    Player plays;
    player = plays;
}

void Game::newGame(){
    player.newGame();
    fights.fightTutorial(player);
    newgame.finTutorial();
    sleep(5);
    cout << "Console: (Going to town)" << endl;
    sleep(2);
    town();
}


//This function will be huge. Careful with it.
// colors: 0 black, 1 red, green 2, yellow 3, blue 4, magenta 5, cyan 6, white 7.
//Options: Shop1, Black smith2, Library3, Rest4, Embark5, Save6, Hero7, Equip 8,
void Game::town(){
    play_sound();
    bool storeCheck = false;
    player.restore();
    cout << "Welcome back to the town, Its good to have you back!" << endl;
    cout << "You always restore Health and Mana upon returning to the Town" << endl;

    bool savecheck = false;
    do {
        cout << "Select an option from below:" << endl;
        cout << "[" << 1 << "]: ";
        printf("\x1b[32mShop \x1b[0m");
        cout << "   [" << 2 << "]: ";
        printf("\x1b[31mBlack Smith \x1b[0m");
        cout << "   [" << 3 << "]: ";
        printf("\x1b[35mLibrary \x1b[0m");
        cout << "   [" << 4 << "]: ";
        printf("\x1b[34mMarket \x1b[0m");
        cout << "   [" << 5 << "]: ";
        printf("\x1b[33mEmbark \x1b[0m");
        cout << "   [" << 6 << "]: ";
        printf("\x1b[36mSave \x1b[0m");
        cout << "   [" << 7 << "]: Hero" << "    [8]: Equip" << "     [9]: Help "<< endl;
        string input = "";

        cin >> input;
     //   if (input.size() != 1) {
     //       cout << "Please enter a single digit to select what you would like to do. " << endl;
     //   } else if (!isdigit(input.at(0))) {
      //      cout << "Please enter a single digit to select what you would like to do. " << endl;
     //   } else
            if (input.at(0) == '1' || input == "shop" || input == "Shop") {
            //Shop
            cout << "Would you like to go to the ";
            printf("\x1b[32mShop \x1b[0m");
            cout << "?: <You can only go to the shop once each time you return to the shop> (Yes or No) " << endl;
            cin >> input;
            if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "yes " ||
                input == "Yes ") {
                if(!storeCheck){
                    int gold = player.getGold();
                    shop.townShop(player.getLvl(), player.getName(), gold);
                    player.setGold(gold);
                    storeCheck = true;
                    //run store
                }
                else{
                    cout << "You have already been to the store recently, Items won't change until you come back after an adventure." << endl;
                }
            }//run shop command
            else cout << "Okay, choose something else from the menu" << endl;
        } else if (input.at(0) == '2' || input == "black smith" || input == "Black Smith") {
            //Black SMith
            cout << "Would you like to go to the ";
            printf("\x1b[31mBlack Smith \x1b[0m");
            cout << "?: (Yes or No) " << endl;
            cin >> input;
            if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "yes " ||
                input == "Yes ") {}//run shop command
            else cout << "Okay, choose something else from the menu" << endl;
        } else if (input.at(0) == '3' || input == "library" || input == "Library") {
            //Library
            cout << "Would you like to go to the ";
            printf("\x1b[35mLibrary \x1b[0m");
            cout << "?: (Yes or No) " << endl;
            cin >> input;
            if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "yes " ||
                input == "Yes ") {}//run shop command
            else cout << "Okay, choose something else from the menu" << endl;
        } else if (input.at(0) == '4'|| input == "market" || input == "Market") {
            //Rest:
            cout << "Would you like to go to the ";
            printf("\x1b[34mMarket \x1b[0m");
            cout << "?: (Yes or No) " << endl;
            cin >> input;
            if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "yes " ||
                input == "Yes ") {
                int gold = player.getGold();
                market.shop(player.bag, gold);
                player.setGold(gold);
            }
            else cout << "Okay, choose something else from the menu" << endl;
        } else if (input.at(0) == '5' || input == "embark" || input == "Embark") {
            //Embark
            cout << "Would you like to go to ";
            printf("\x1b[33mEmbark \x1b[0m"); //CRASHES SOMEWHERE IN HERE
            cout << "on a new adventure?: (Yes or No) " << endl;
            cin >> input;
            if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "yes " ||
                input == "Yes ") {
                embark.startMish(player);
                storeCheck = false; //have embark return something so I can know if they actually did a mission or not.
                sleep(2);
                cout << "Welcome back to the Town!" << endl;
                sleep(2);
            }//run shop command
            else cout << "Okay, choose something else from the menu" << endl;
        } else if (input.at(0) == '6' || input == "save" || input == "Save") {
            //Save
            cout << "Would you like to go to ";
            printf("\x1b[36mSave \x1b[0m");
            cout << "your progress?: (Yes or No) " << endl;
            cin >> input;
            if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "yes " ||
                input == "Yes ") {
                //save game.
                cout
                        << "Your game has been saved, to load it next time you play, simply type load at the start of the game and type in your name. Thanks for playing!"
                        << endl;
                cout << "Powering down" << endl;
                sleep(3);
                save();
                savecheck = true;

            } else cout << "Okay, choose something else from the menu" << endl;
        } else if (input.at(0) == '7' || input == "hero" || input == "Hero") {
            //Hero
            player.calcStats();
            cout << "Hero" << endl;
            cout << "Players Name: " << player.getName() << "         Lvl: " << player.getLvl() << "         xp: " << player.getXP() << "/100" << endl;
            //player.outputStats(); TODO: THIS DOESN"T WORK
            cout << " Gold: " << player.getGold() << endl;

            player.outputStats();

        } else if (input.at(0) == '8' || input == "equip" || input == "Equip") {
            //Eqiup
            cout << "Equip" << endl;
            sleep(1);
            player.equipItems();


        }
        else if (input.at(0) == '9' || input == "help" || input == "Help") {
            string input = "";
        }
        else {
            cout << "Try again, unexpected value recieved: ";
        }
    }
    while(!savecheck);
    //end the program
}






//Save
void Game::save(){

    ofstream save (player.getName() + ".txt");
    //player stats
    //string saves = player.saveToString();
    string saves = "";
    int hold = 0;
    saves = player.getName();
    save << saves << endl;
    hold = player.getLvl();
    save << hold << endl;
    hold = player.getXP();
    save << hold << endl;
    hold = player.getGold();
    save << hold << endl;
    hold = player.getHealth();
    save << hold << endl;
    hold = player.getStr();
    save << hold << endl;
    hold = player.getDef();
    save << hold << endl;
    hold = player.getSpd();
    save << hold << endl;
    hold = player.getMag();
    save << hold << endl;
    hold = player.getCurHealth();
    save << hold << endl;
    hold = player.getCurMana();
    save << hold << endl;

    //weapons
    save << "Equipped weapon: " << endl;
    string eq = player.equiptedWeapon.getName();
    save << eq << endl;
    eq = player.equiptedWeapon.getType();
    save << eq << endl;
    int eqf = player.equiptedWeapon.getPhyDamage();
    save << eqf << endl;
    eqf = player.equiptedWeapon.getMagDamage();
    save << eqf << endl;
    eqf = player.equiptedWeapon.getCost();
    save << eqf << endl;
    eq = player.equiptedWeapon.getRarity();
    save << eq << endl;
    eqf = player.equiptedWeapon.getQuality();
    save << eqf << endl;

    save << "Weapons:" << endl;
    save << player.weapons.size() << endl;
    for(int i = 0; i < player.weapons.size(); i++){
        save << i << ":" << endl;
        vector<string> saver = player.weapons.at(i).toStringSave();
        string ssave = player.weapons.at(i).getName();
        save << ssave << endl;
        ssave = player.weapons.at(i).getType();
        save << ssave << endl;
        int whold = player.weapons.at(i).getPhyDamage();
        save << whold << endl;
        whold = player.weapons.at(i).getMagDamage();
        save << whold << endl;
        whold = player.weapons.at(i).getCost();
        save << whold << endl;
        ssave = player.weapons.at(i).getRarity();
        save << ssave << endl;
        whold =  player.weapons.at(i).getQuality();
        save << whold << endl;


    }
    //items
    //Healing Salve,
    //Mana Salve
    //Greater Salve;

    int num = player.bag.at(0).getCount();
    save << num << endl;
    num = player.bag.at(1).getCount();
    save << num << endl;
    num = player.bag.at(2).getCount();
    save << num << endl;






    save.close();
}


//Load
void Game::load(string loadName) {
    Player plays;
    vector<string> playVals;
    ifstream loader(loadName + ".txt");
    string reader = "";
    int count = 1;
    //Load Player
    for(int i = 0; i < 11; i++){
        string hold;
        getline(loader, hold);
        playVals.push_back(hold);
    }
    plays.readLoader(playVals);
    getline(loader, reader); //This should be the weapons output, can make check if want.


    //Load equipted weapon.

    vector<string> weaponEV;
    for(int j = 0; j < 7; j++) {
        //Weapons, it has 6 values in it for each value,

        string reads = "";

        getline(loader, reads);
        weaponEV.push_back(reads);
    }

    string voids = "";
    getline(loader, voids);
    Weapons equiptedWeaponn;
    equiptedWeaponn.loadEquippedW(weaponEV);
    plays.equiptedWeapon = equiptedWeaponn;
    string weaponCount = "";
    getline(loader, weaponCount);
    int wcount = stoi(weaponCount);

    //Load weapons list.
    for(int i = 0; i < wcount; i++){
        vector<string> weaponVect;
        for(int j = 0; j < 8; j++){
            //Weapons, it has 6 values in it for each value,
            string reads = "";
            if(j == 0){
                getline(loader, reads);
            }
            else{
                getline(loader, reads);
                weaponVect.push_back(reads);
            }
        }
        Weapons weapon;
        weapon.readLoader(weaponVect);
        plays.weapons.push_back(weapon);
    }
    //FIX ITEM LOADING:


    vector<Items> itemBag;
    Items healSalve;
    healSalve.setName("Healing Salve");
    healSalve.setType("Health");
    healSalve.setCost(20);
    healSalve.setValue(15);
    itemBag.push_back(healSalve);

    Items manaPotion;
    manaPotion.setName("Mana Potion");
    manaPotion.setType("Mana");
    manaPotion.setCost(30);
    manaPotion.setValue(20);
    itemBag.push_back(manaPotion);

    Items healGreatSalve;
    healGreatSalve.setName("Greater Healing Salve");
    healGreatSalve.setType("Health");
    healGreatSalve.setCost(120);
    healGreatSalve.setValue(55);
    itemBag.push_back(healGreatSalve);

    int itemcounts = 0;
    string itemc = "";
    getline(loader, itemc);
    itemcounts = stoi(itemc);

    itemBag.at(0).setCount(itemcounts);
    cout << itemBag.at(0).getName() << " : " << itemBag.at(0).getCount() << endl;
    getline(loader, itemc);
    itemcounts = stoi(itemc);

    itemBag.at(1).setCount(itemcounts);

    getline(loader, itemc);

    itemcounts = stoi(itemc);
    itemBag.at(2).setCount(itemcounts);

    plays.bag = itemBag;

    //items next.
    //calc stats.

    plays.calcStats();
    plays.library.makeAbiilties();
    plays.abilities = plays.library.checkUsability(plays.getHealth(), plays.getStr(), plays.getDef(), plays.getSpd(), plays.getMag());
    player = plays;

    town();

}