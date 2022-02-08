//
// Created by Payton on 5/2/21.
//

#ifndef SWORDSTORY_MARKET_H
#define SWORDSTORY_MARKET_H
#include <iostream>
#include <vector>
#include "Items.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;

class Market {
private:
    vector<Items> stock;
    int waitTime = 1;
public:
    Market();
    void makeStock();
    void shop(vector<Items>&, int&);

};


#endif //SWORDSTORY_MARKET_H
