//
// Created by Payton Hall on 4/30/21.
//

#include "Items.h"

void Items::setCost(int num) {
    cost = num;
}

void Items::setName(string nam) {
    name = nam;
}

void Items::setType(string ty) {
    type = ty;
}

void Items::setValue(int num) {
    value = num;
}

void Items::setCount(int num) {
    count = num;
}

void Items::toString() {
    cout << "Name: " << name << endl;
    cout << "Effect: " << type << endl;
    cout << "Effect amount: " << value << endl;
    cout << "Cost: " << cost << endl;
}

void Items::useItem() {
    count--;
}

void Items::addItem() {
    count++;
}

void Items::loadCount(int counts) {
    count = counts;
}



//gets:



string Items::getName(){
    return name;
}

int Items::getCost(){
    return cost;
}

string Items::getType() {
    return type;
}

int Items::getValue(){
    return value;
}

int Items::getCount(){
    return count;
}

