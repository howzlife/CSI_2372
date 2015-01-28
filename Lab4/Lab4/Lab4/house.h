//
//  house.h
//  Lab4
//
//  Created by Nicolas Dubus on 2014-10-15.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __Lab4__house__
#define __Lab4__house__

#include "heater.h"
#include <iostream>
using namespace std;

class House {
    WaterHeater* heater;
    
public:
    void installWaterHeater( WaterHeater const *,
                            bool, bool);
    
    WaterHeater* removeWaterHeater();
    
    void printWaterHeater();
    
};

#endif /* defined(__Lab4__house__) */
