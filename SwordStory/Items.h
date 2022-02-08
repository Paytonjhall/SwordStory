//
// Created by Payton Hall on 4/30/21.
//

#ifndef SWORDSTORY_ITEMS_H
#define SWORDSTORY_ITEMS_H
#include <iostream>
#include <vector>
using namespace std;

class Items {
private:
    string name ="";
    int cost = 0;
    int count = 0;
    string type = "";
    int value = 0;

public:

    void toString();

    //sets
    void setName(string);
    void setCost(int);
    void setType(string);
    void setValue(int);
    void setCount(int);

    //gets
    string getName();
    int getCost();
    string getType();
    int getValue();
    int getCount();

    void addItem();
    void useItem();
    void loadCount(int);



};


#endif //SWORDSTORY_ITEMS_H
