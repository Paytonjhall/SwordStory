//
// Created by Payton Hall on 4/30/21.
//

#include "Combat.h"

void Combat::fightTutorial(Player &player) {

    cout << "You won't survive long if you don't know how to fight. Lets walk you through it." << endl;
    sleep(tutorialTimer);
    cout << "When fighting, the goal is to lower your enemies health to 0, while staying alive yourself." << endl;
    sleep(tutorialTimer);
    cout << "Lets summon an enemy for you!: " << endl;
    createEnemy(player.getLvl());
    cout << "Your enemy is a " << enemy.getName() << "!" << endl;
    sleep(tutorialTimer);
    cout << "Its time to learn how to fight" << endl;
    sleep(tutorialTimer);
    cout << "As you become stronger and gain more XP, you will learn new skills and spells." << endl;
    sleep(tutorialTimer);
    cout << "You currently don't have any, but these abilities and spells can be used to help you during combat." << endl;
    sleep(tutorialTimer);
    cout << "You can select these skills and spells during your turn in combat, doing so will use your turn however." << endl;
    sleep (tutorialTimer);
    cout << "You can also attack with whatever weapon you are holding. Damage will be calculated depending on your Stregnth or Magic plus the weapon damage." << endl;
    sleep(tutorialTimer);
    cout << "Magic weapons will cost a little bit of mana to use, Spells cost a significant amount of mana." << endl;
    sleep(tutorialTimer);
    cout << "Enemies with more defense and health will take longer to take down." << endl;
    sleep(tutorialTimer);
    cout << "You can also choose to 'Examine' your foe, this will tell you some important information about them." << endl;
    sleep(tutorialTimer);
    cout << "Items you acquire through shops and looting can also be used during combat. Each one will do something different. " << endl;
    sleep (tutorialTimer);
    cout << "After defeating an enemy, you will be given XP and sometimes gold or other items. When you get enough XP, you will level up and gain more skill points to use." << endl;
    sleep(tutorialTimer);
    cout << "Lets give it a try now" << endl;
    sleep(tutorialTimer);
    startCombat(player, enemy);
    cout << "Great job, You have finished the tutorial for Sword Story! Its time for you to start your adventure. Good Luck!" << endl << endl << endl;

}

void Combat::createEnemy(int lvl) {
    if(lvl == 0){
        enemy.createTutEnemy();
    }
    enemy.createEnemy(lvl);
}

void Combat::startCombat(Player &player, Enemy &enemy) {
    //check who has the higher speed they attack first
    int turnCount = 0;
    bool firstStrike;
    cout << "~~~ You encountered a " << enemy.getName() << " ~~~" << endl;

    if(player.getSpd() >= enemy.getSpd()){
        printf("\x1b[36m Your speed is higher than your enemy's, you will strike first!\x1b[0m\n");
        firstStrike = true;
    }
    else{
        printf("\x1b[31m Your enemy's speed is higher than yours, they will attack first.\x1b[0m\n");
        firstStrike = false;
    }
    //TODO: Combat goes here

    while(!checkDead(player, enemy)) {
    if(firstStrike) {
        bool finmove = false;
        firstStrike = false;

        do {
            //IF I want to print out enemy information, put it here.
            printEnemyInfo(enemy);
            cout << endl << endl;


            printf("\x1b[31mHealth: \x1b[0m"); cout << player.getCurHealth() << "          " ; printf("\x1b[36mMana: \x1b[0m"); cout << player.getCurMana() << endl;
            cout << "What will " << player.getName() << " do?:" << endl;
            printOptions(player);
            string move = "";
            cin >> move;
            if (move == "attack" || move == "Attack" || move == "attack " || move == "Attack ") {
                cout << "You attack: " << endl;
                if (player.equiptedWeapon.getType() == "Physical")
                    playerAttack(player.getStr(),  player.equiptedWeapon.getPhyDamage(), enemy, player);
                if (player.equiptedWeapon.getType() == "Magical")
                    playerAttack(player.getMag(),  player.equiptedWeapon.getMagDamage(), enemy, player);
                finmove = true;
            } else if (move == "Examine" || move == "examine" || move == "Examine " || move == "examine ") {
                examine(player, enemy);
                finmove = true;
            }
            else if(move == "Equip" || move == "equip" || move == "Equip " || move == "equip "){
                player.equipItems();
                finmove= true;
            }
            else if(move == "Bag" || move == "bag" || move == "Bag " || move == "bag "){
                for(int i = 0; i < player.bag.size(); i ++){
                    if(player.bag.at(i).getCount()>0) cout << "[" << i+1 << "]: " << player.bag.at(i).getName() << endl;
                }
                    cout << "Back" << endl;
                    cout << "Which Item would you like to use?" << endl;
                    string input = "";
                    cin >> input;
                if(move == "Back" || move == "back" || move == "Back " || move == "back "){
                    cout << "Please select another action: " << endl << endl;
                    sleep(2);
                }
                else if(isdigit(input.at(0))){
                    int action = stoi(input);
                    action --;
                    if(player.bag.at(action).getType() == "Health"){
                        //heal player equal to value, take away 1
                        if(player.bag.at(action).getCount()<1){
                            cout << "You don't have any of those in your bad, returning to combat" << endl;
                        }
                        else {
                            player.addHealth(player.bag.at(action).getValue());
                            player.bag.at(action).useItem();
                            cout << "Your Health is now: " << player.getCurHealth() << endl;
                            finmove = true;
                        }

                    }
                    else if(player.bag.at(action).getType() == "Mana"){
                        if(player.bag.at(action).getCount()<1){
                            cout << "You don't have any of those in your bad, returning to combat" << endl;
                        }
                        else {
                            //Heal player mana equal to value, take away 1.
                            player.addMana(player.bag.at(action).getValue());
                            player.bag.at(action).useItem();
                            cout << "Your Mana is now: " << player.getCurMana() << endl;
                            finmove = true;
                        }
                    }
                }
                else{
                    cout << "Invalid response" << endl;
                }
            }
            else if(move == "Abilities" || move == "abilities" || move == "Abilities " || move == "abilities ") {
                cout << "Select an ability or type 'back': " << endl;
                for (int i = 0; i < player.abilities.size(); i++) {
                    cout << "[" << i+1 << "]: " << player.abilities.at(i).getName() << "  "; printf("\x1b[36mMana Cost: \x1b[0m"); cout << player.abilities.at(i).getManaCost() << endl;
                }
                string is = "";
                cin >> is;

                if(is == "back" || is == "Back" || is == "back " || is == "Back "){
                    //just return back
                }
                else{
                    int in = stoi(is);
                    in--;
                    if(player.getCurMana() < player.abilities.at(in).getManaCost()){
                        cout << "You don't enough mana for that ability, going back to combat: " << endl;
                        sleep(2);
                    }
                    else {
                        attackWAbility(player, enemy, in);
                        finmove = true;
                    }
                }
            }
            else{
                cout << "The entered action does not exist, please enter a new command " << endl;
                sleep(2);
            }
        } while (!finmove);
    }

        else{
            firstStrike = true;
            cout << "Your enemy is about to attack!" << endl;
            sleep(2);
            enemyAttack(enemy.getStr(), player, enemy);
        }
        //call new function. Players turn.
        //call new function, enemies turn.


    cout << endl << endl;
    }
    cout << "Well done! You have slain the " << enemy.getName() << ". You have gained " << enemy.getXP() << " xp!" << endl;
    player.gainXP(enemy.getXP());
    cout << "You also got found some gold on the " << enemy.getName() << "! It had " << enemy.getGold() <<" Gold!" << endl;
    player.addGold(enemy.getGold()); //this isn't adding gold.
}

void Combat::enemyAttack(int dam, Player &player, Enemy &enemy)
{
    int temp = dam;
   // dam = ((rand() % (dam/2)) + 1) + (dam); //check if this works. It would break whenever I try to do this, so I'm giving this a try.
    dam = dam/2;
    if(dam > 0) dam = (rand() % dam);
    dam ++;
    dam += temp;
    int dodge = 0;
    dodge = player.getCalcSpd() - (enemy.getSpd()/2);
    int rands = rand() % 100;
    if(dodge>=rands){
        cout << "Your enemy's attack missed! You evaded the attack. " << endl;
    }
    else{
        int damage = calcDamage(dam, player.getDef());
        if(damage<=0){
            cout << player.getName() << " took no damage from the attack!" << endl;
        }
        else{
            cout << player.getName() << " took " << damage << " from the attack." << endl;
            player.setCurHealth(player.getCurHealth() - damage);
        }
    }

}

void Combat::playerAttack(int str, int itemDam, Enemy &enemy, Player &player) {
    int dam = (((rand() % (str/2)) + 1) + (str * (3/4))) + itemDam; //check if this owrks.
    int dodge = 0;
    dodge = enemy.getSpd() - (player.getCalcSpd()/2);
    int rands = rand() % 100;
    if(dodge>=rands){
        cout << "Your attack missed! Your enemy evaded the attack. " << endl;
    }
    else{
        int damage = calcDamage(dam, enemy.getDef());
        if(damage<=0){
            cout << enemy.getName() << " took no damage from your attack!" << endl;
        }
        else{
            cout << enemy.getName() << " took " << damage << " from your attack." << endl;
            enemy.setCurHealth(enemy.getCurHealth() - damage);
        }
    }
}

int Combat:: calcDamage(int dam, int def){
    int blockedDmg = (rand() % (def/2));
    int addBlock = def/3;
    blockedDmg += addBlock;
    int total = dam - blockedDmg;
    return total;
}

void Combat::printOptions(Player &player) { //Make these colorful plz
    cout << "Attack ";
    int items = 0;
    for(int i = 0; i < player.bag.size(); i++){
        items += player.bag.at(i).getCount();
    }
    if(player.getWeapons()>0){
        cout << "Equip ";
    }
    if(player.abilities.size()>0){
        cout << "Abilities ";
    }
    if(player.spellbook.size()>0){
        cout << "Spells ";
    }
    if(items > 0){
        cout << "Bag ";
    }
    cout << "Examine" << endl;
}

void Combat:: examine(Player &player, Enemy &enemy){
    cout << "You examine your enemy:" << endl;
    sleep(2);
    if(enemy.getCurHealth() > enemy.getTotHealth()/2){
        cout << "The " << enemy.getName() << " looks pretty strong, and angry!" << endl;
    }
    else{
        cout << "The " << enemy.getName() << " looks pretty beat up, still angry though!" << endl;
    }
    sleep(2);
    cout << enemy.getName() << " Health:";
    double healthInc = enemy.getTotHealth()/10;
    int counter  = 0;
    //int percent = 100 * (enemy.getCurHealth() / enemy.getHealth());
    for(int i = 0; i < 10; i++){
        if( counter <= enemy.getCurHealth() ) {
            printf("\x1b[41m \x1b[0m");
            counter += healthInc;

        }
        else{
            printf("\x1b[40m \x1b[0m");
            counter+= healthInc;
        }
        cout << counter << " counter" << endl;

    }
    //cout << "  " << "(" << percent << "%)" << endl;
}

void Combat::attackWAbility(Player &player, Enemy &enemy, int abiNum) {
    int damage = player.getStr() + player.equiptedWeapon.getPhyDamage() + player.abilities.at(abiNum).getModifier() - enemy.getDef();
    cout << enemy.getName() << " took " << damage << " from " << player.abilities.at(abiNum).getName() << endl;
    enemy.setCurHealth(enemy.getCurHealth() - damage);
    if(player.abilities.at(abiNum).getEffect() == "Lifesteal") {
        damage = damage / 2;
        player.lifesteal(damage, player.abilities.at(abiNum).getName());
    }

}










bool Combat::checkDead(Player &player, Enemy &enemy) {
    if(player.getCurHealth()<=0){
        //Player is dead
        //end program.
        cout << "You died, your world slowly turns to black" << endl;
        cout << "The game will close shortly" << endl;
        sleep(4);
        exit(0);
    }
    else if(enemy.getCurHealth()<= 0){
        //Enemy is dead
        return true;
    }
    else{
        //battle is still going.
        return false;
    }
}

void Combat::printEnemyInfo(Enemy &enemyy){
    cout << "\t\t\t\t" << enemyy.getName() << endl;
    cout << "\t\t\t\t";
    int black = enemyy.getTotHealth() - enemyy.getCurHealth();
    for(int i = 0; i < black; i++){
        printf("\x1b[40m \x1b[0m");
    }
    for(int i = 0; i < enemyy.getCurHealth(); i++){
        printf("\x1b[41m \x1b[0m");
    }


}