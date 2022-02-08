//
// Created by Payton Hall on 4/29/21.
//

#include "Player.h"
//saves game
string Player::saveToString() {
    string saver = pName;
    saver += playerLvl + "\n";
    saver += xp + "\n";
    saver += totalGold + "\n";
    saver += health + "\n";
    saver += str + "\n";
    saver += def + "\n";
    saver += spd + "\n";
    saver += mag + "\n";
    saver += curHealth + "\n";
    saver += curMana + "\n";

    return saver;
}

//loads game from file.
void Player::readLoader(vector<string> vals) {
    Items setbag1;
    bag.push_back(setbag1);
    Items setbag2;
    bag.push_back(setbag1);
    Items setbag3;
    bag.push_back(setbag1);


    pName = vals.at(0);
    playerLvl = stoi(vals.at(1));
    xp = stoi(vals.at(2));
    totalGold = stoi(vals.at(3));
    this->health = stoi(vals.at(4));
    this->str = stoi(vals.at(5));
    def = stoi(vals.at(6));
    spd = stoi(vals.at(7));
    mag = stoi(vals.at(8));
    curHealth = stoi(vals.at(9));
    curMana = stoi(vals.at(10));
    cout << "Player: " << pName << " Health: " << health << " Str: " << str << endl;
    //probably calc stats now.

}



void Player::giveStartingItems() {
    //Give fists as item.
    Weapons fists;
    fists.setPhyDamage(1);
    fists.setCost(0);
    fists.setMagDamage(0);
    fists.setType("Physical");
    fists.setName("Fists");
    fists.setRarity("Not-Rare-At-All");
    fists.setQuality(0);
    equiptedWeapon = fists;

    Items healSalve;
    healSalve.setName("Healing Salve");
    healSalve.setType("Health");
    healSalve.setCost(20);
    healSalve.setValue(15);
    healSalve.setCount(1);
    bag.push_back(healSalve);

    Items manaPotion;
    manaPotion.setName("Mana Potion");
    manaPotion.setType("Mana");
    manaPotion.setCost(30);
    manaPotion.setValue(20);
    manaPotion.setCount(0);
    bag.push_back(manaPotion);

    Items healGreatSalve;
    healGreatSalve.setName("Greater Healing Salve");
    healGreatSalve.setType("Health");
    healGreatSalve.setCost(120);
    healGreatSalve.setValue(55);
    healGreatSalve.setCost(0);
    bag.push_back(healGreatSalve);
}

void Player:: calcStatsTut(){
    //TODO: Here will be all the equations for getting your in game stats. Recalc after each level up.
    totHealth = health * 3 + 12;
    totStr = str; //Weapon damage dramatically changes this value
    totDef = def; //def is a little different, you simply find a random number between 0 and the def, and subtract that from incoming damage.
    totSpd = spd * 2 + 1;
    totMag = mag; //Spell damage dramatically changes this value.
    totMana = mag * 3 + 7;
    curHealth = totHealth;
    curMana = totMana;

    cout << "Wonderful, your stats are as following: " << endl;
    printf("\x1b[32m Health: \x1b[0m "); cout << totHealth << endl;
    printf("\x1b[31m Strength: \x1b[0m "); cout << totStr << endl;
    printf("\x1b[34m Defense: \x1b[0m "); cout << totDef << endl;
    printf("\x1b[33m Speed: \x1b[0m "); cout << spd << endl;
    printf("\x1b[35m Magic: \x1b[0m "); cout << totMag << endl;
    printf("\x1b[36m Mana: \x1b[0m "); cout << totMana << endl;

    cout << endl;

    sleep(waitTime);
    cout << endl << endl << endl << endl; //"clear console"
}

void Player:: calcStats(){
    //TODO: Here will be all the equations for getting your in game stats. Recalc after each level up.
    totHealth = health * 3 + 12;
    totStr = str; //Weapon damage dramatically changes this value
    totDef = def; //def is a little different, you simply find a random number between 0 and the def, and subtract that from incoming damage.
    totSpd = spd * 2 + 1;
    totMag = mag; //Spell damage dramatically changes this value.
    totMana = mag * 3 + 7;
    curHealth = totHealth;
    curMana = totMana;

    //printf("\x1b[32m Health: \x1b[0m "); cout << totHealth << endl;
    //printf("\x1b[31m Strength: \x1b[0m "); cout << totStr << endl;
    //printf("\x1b[34m Defense: \x1b[0m "); cout << totDef << endl;
    //printf("\x1b[33m Speed: \x1b[0m "); cout << totSpd << endl;
    //printf("\x1b[35m Magic: \x1b[0m "); cout << totMag << endl;
    //printf("\x1b[36m Mana: \x1b[0m "); cout << totMana << endl;

    //sleep(waitTime);
    //cout << endl << endl; //"clear console"
}


void Player::outputStats(){
    printf("\x1b[32m Health: \x1b[0m "); cout << totHealth << endl;
    printf("\x1b[31m Strength: \x1b[0m "); cout << totStr << endl;
    printf("\x1b[34m Defense: \x1b[0m "); cout << totDef << endl;
    printf("\x1b[33m Speed: \x1b[0m "); cout << spd << endl;
    printf("\x1b[35m Magic: \x1b[0m "); cout << totMag << endl;
    printf("\x1b[36m Mana: \x1b[0m "); cout << totMana << endl;
}

void Player::newGame(){
    giveStartingItems();
    pName = game.start();
   vector<int> stats = game.stats(); //set all those stats and calc them here.
   health = stats.at(0);
   str = stats.at(1);
   def = stats.at(2);
   spd = stats.at(3);
   mag = stats.at(4);
   calcStats();
    cout << "As you progress in the game you will level up and receive more skill points." << endl;
   weapons = game.shop(totalGold); //check if these items end of there or not.
   //testWeapons();
   cout << "Looks like you got some weapons now, lets equip a weapon." << endl << "You can equip a new weapon during combat or out of combat" << endl;
   //Equip Items
   equipItems();
   cout << "Now that you have your gear, its about time to learn how to fight!" << endl;
}


void Player::equipItems() {
    printf("\x1b[32m---------Equipment Menu------------------------------------\x1b[0m \n");
    bool check = false;
    bool firstCheck = false;
    cout << "(Only 1 item can be equiped at a time)" << endl;
    do {
        cout << "Current equipted weapon" << endl;
        cout << equiptedWeapon.getName() << endl;
        cout << "Weapon Physical Damage: "; printf("\x1b[31m%d\x1b[0m\n",equiptedWeapon.getPhyDamage() );
        cout << "Weapon Magical Damage: " ; printf("\x1b[36m%d\x1b[0m\n",equiptedWeapon.getMagDamage() );
        cout << endl;
        cout << "Your weapons:" << endl;
        toStringWeapons();
        if (weapons.size() == 0) {
            cout << "You do not have any items to equip right now." << endl;
        } else {
            cout << "Which weapon would you like to equip right now? If none, type end (enter a number): ";
            string eqiup = "";
            cin >> eqiup;
            if (eqiup == "end" || eqiup == "End" || eqiup == "end " || eqiup == "End ") {
                firstCheck = true;
            } else {
                if (!isdigit(eqiup.at(0))) {
                    cout << "You didn't enter a digit, try again: " << endl;
                } else {
                    int eq = stoi(eqiup);
                    if (eq > weapons.size() || eq < 1) {
                        cout << "The entered number doesn't not correlate with a weapon number" << endl;
                    } else {
                        weapons.push_back(equiptedWeapon);
                        equiptedWeapon = weapons.at(eq - 1);
                        weapons.erase(weapons.begin() + eq - 1);
                        cout << "You are now equipping your " << equiptedWeapon.getName() << endl;
                    }
                }
            }
                if (!firstCheck) {
                    check = true;
                } else {
                    cout << "If you are done equipping items, enter end. If not, enter equip:" << endl;
                    string val = "";
                    cin >> val;
                    if (val == "end" || val == "End" || val == "end " || val == "End ")
                        check = true;
                }

        }
    }
    while(!check);

}

void Player::toStringWeapons() {
    if(weapons.size() == 0){
        cout << "You do not have any weapons in your stash at the moment. " << endl;
    }
    for(int i = 0; i < weapons.size(); i++){
        cout << "Weapon [" << i+1 << "]: " << weapons.at(i).getName() << endl;
        cout << "Weapon Type: ";
        if(weapons.at(i).getType()=="Physical") printf("\x1b[31m Physical\x1b[0m\n");
        else printf("\x1b[36m Magical\x1b[0m\n");
        cout << "Weapons Physical Damage: "; printf("\x1b[31m%d\x1b[0m\n",weapons.at(i).getPhyDamage() );
        cout << "Weapons Magical Damage: "; printf("\x1b[36m%d\x1b[0m\n",weapons.at(i).getMagDamage() );
        cout << endl;
    }

}

void Player::gainXP(int val){
    xp += val;

    if(xp >= xpLevelUp){
        playerLvl++;

        cout << "You leveled up! " << "You are now level " << playerLvl << "!" << endl;
        xp = xp - xpLevelUp;
        lvlUp();
    }
    else{
        cout << "You need " << xpLevelUp - xp << " more xp to level up" << endl;
    }
}

//TODO: lvl up function kinda long.
void Player::lvlUp() {
    int pointsleft = lvlUpPoints;
    bool check = false;
    do {
        cout << "When you level up, each stat will go up by 1, you also will gain " << lvlUpPoints << " to be added to stats of your choice." << endl;
        cout << "You have gained " << lvlUpPoints << " for leveling up. How would you like to use those?" << endl;
        sleep(2);
        health ++;
        str ++;
        def ++;
        spd ++;
        mag ++;
        cout << "How many points would you like to assign:" << endl;
        printf("\x1b[32m Health \x1b[0m");
        cout << " (current lvl: " << health << "): ";
        int lvlhealth;
        cin >> lvlhealth;
        cout << endl;
        pointsleft = pointsleft - lvlhealth;
        cout << "You have " << pointsleft << " points remaining" << endl;

        cout << "How many points would you like to assign:" << endl;
        printf("\x1b[31m Strength \x1b[0m");
        cout << " (current lvl: " << str << "): ";
        int lvlstr;
        cin >> lvlstr;
        cout << endl;
        pointsleft = pointsleft - lvlstr;
        cout << "You have " << pointsleft << " points remaining" << endl;

        cout << "How many points would you like to assign:" << endl;
        printf("\x1b[34m Defense \x1b[0m");
        cout << " (current lvl: " << def << "): ";
        int lvldef;
        cin >> lvldef;
        cout << endl;
        pointsleft = pointsleft - lvldef;
        cout << "You have " << pointsleft << " points remaining" << endl;

        cout << "How many points would you like to assign:" << endl;
        printf("\x1b[33m Speed \x1b[0m");
        cout << " (current lvl: " << spd << "): ";
        int lvlspd;
        cin >> lvlspd;
        cout << endl;
        pointsleft = pointsleft - lvlspd;
        cout << "You have " << pointsleft << " points remaining" << endl;

        cout << "How many points would you like to assign:" << endl;
        printf("\x1b[35m Magic \x1b[0m");
        cout << " (current lvl: " << mag << "): ";
        int lvlmag;
        cin >> lvlmag;
        cout << endl;
        pointsleft = pointsleft - lvlmag;
        cout << "You have " << pointsleft << " points remaining" << endl;

        int total = lvlhealth + lvlstr + lvldef + lvlspd + lvlmag;

        if (total > lvlUpPoints) {
            cout << "You used too many points, please try again." << endl;
        } else if (total < lvlUpPoints) {
            cout << "You didn't use all your points, please try again from the top." << endl;
        } else {
            check = true;
            health += lvlhealth;
            str += lvlstr;
            def += lvldef;
            spd += lvlspd;
            mag += lvlmag;
        }

    }
    while(!check);
    calcStats();
    //check abilities:
    abilities = library.checkUsability(health, str, def, spd, mag);
}


//TODO: Get and Set functions
//gets
int Player:: getTotMana(){
    return totMana;
}

int Player::getTotHealth(){
    return totHealth;
}

int Player::getCalcSpd(){
    return totSpd;
}

int Player::getHealth(){
    return health;
}

int Player::getStr(){
    return str;
}

int Player::getDef(){
    return def;
}

int Player::getSpd(){
    return spd;
}

int Player::getMag(){
    return mag;
}

int Player::getCurHealth(){
    return curHealth;
}

string Player::getName(){
    return pName;
}

int Player:: getWeapons()
{
    return weapons.size();
}

int Player:: getLvl(){
    return playerLvl;
}

int Player:: getCurMana(){
    return curMana;
}

int Player:: getGold(){
    return totalGold;
}

int Player::getXP(){
    return xp;
}

//sets
void Player::setCurHealth(int val) {
    curHealth = val;
}

void Player:: setCurMana(int val){
    curMana = val;
}

void Player::addGold(int money) {
    totalGold += money;
}

void Player::restore(){
    curHealth = totHealth;
    curMana = totMana;
}

void Player::setGold(int change){
    totalGold = change;
}

//HEALING:
void Player::addHealth(int heal){
    if(curHealth + heal > totHealth){
        int healed = totHealth - curHealth;
        curHealth = totHealth;
        cout << "You healed " << healed << " Health" <<endl;
    }
    else{
        curHealth += heal;
        cout << "You healed " << heal << " Health" <<endl;
    }
}


void Player::addMana(int heal){
    if(curMana + heal > totMana){
        int healed = totMana - curMana;
        curMana = totMana;
        cout << "You replenished " << healed << " Mana" <<endl;
    }
    else{
        curMana += heal;
        cout << "You replenished " << heal << " Mana" <<endl;
    }
}

void Player::useMana(int use){
    curMana = curMana - use;
}

void Player::lifesteal(int heal, string aName) {
    if(curHealth + heal > totHealth){
        int healed = totHealth - curHealth;
        curHealth = totHealth;
        cout << "You stole " << healed << " Health from " << aName <<endl;
    }
    else{
        curHealth += heal;
        cout << "You healed " << heal << " Health from " << aName << endl;
    }

}




//TODO: Testing functions
void Player ::testWeapons() {
    cout << "Testing weapons after buying: " << endl;
    cout << weapons.size() << " this is the weapons size" << endl;
    for(int i = 0; i > weapons.size(); i++){
        cout << weapons.at(i).getName() << endl;
    }
}

