//
//  main.cpp
//  Lab4
//
//  Created by Nicolas Dubus on 2014-10-09.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include <iostream>
#include "house.h"
using namespace std;


int main(int argc, const char * argv[]) {

    House myHouse;
    
    WaterHeater* st = new StorageTank(1000, WaterHeater::Gas, 8.0, 0.55);
    myHouse.installWaterHeater(st, true, true);

    House otherHouse = *new House(myHouse);
    
    myHouse.removeWaterHeater();
    
    WaterHeater* st2 = new Tankless(2000, WaterHeater::Electric, 12.0, 0.93);
    otherHouse.installWaterHeater(st2, false, true);

    myHouse.printWaterHeater();
    
    otherHouse.printWaterHeater();
    
    return 0;
}
