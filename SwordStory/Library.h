//
// Created by Payton Hall on 5/3/21.
//

#ifndef SWORDSTORY_LIBRARY_H
#define SWORDSTORY_LIBRARY_H
#include <vector>
#include <iostream>

#include "Abilities.h"

using namespace std;

class Library {
public:
    Library();
    void makeAbiilties();
    vector<Abilities> checkUsability(int, int, int, int, int);

private:
    vector<Abilities> abilityList;

};


#endif //SWORDSTORY_LIBRARY_H
