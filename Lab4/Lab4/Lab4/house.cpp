//
//  house.cpp
//  Lab4
//
//  Created by Nicolas Dubus on 2014-10-15.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "house.h"
#include <iostream>
using namespace std;

void House::installWaterHeater( WaterHeater const* _heater,
                                bool _hookUp, bool _newVent) {
    this->heater = _heater-> clone();
    std::cout << "Installation price: $" << _heater->installedPrice(_hookUp, _newVent) << std::endl;
}

WaterHeater* House::removeWaterHeater() {
    WaterHeater* removed = this->heater;
    this->heater = nullptr;
    return removed;
}

void House::printWaterHeater() {
    this->heater->print();
    cout << endl;
}