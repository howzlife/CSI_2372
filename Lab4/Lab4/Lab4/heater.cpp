//
//  heater.cpp
//  Lab4
//
//  Created by Nicolas Dubus on 2014-10-09.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "heater.h"
#include <iostream>
using namespace std;

float WaterHeater::getPrice() const{
    return this->d_price;
}

void WaterHeater::print() {
    
    std::cout << "Price: " << this->d_price << std::endl;
    std::cout << "Fuel: " << this->d_energySource << std::endl;
    std::cout << "Max GPM: " << this->d_maxGPM << std::endl;
    std::cout << "Energy Factor: " << this->d_energyFactor << std::endl;
    std::cout << "Energy Star: ";
    if (this->d_energyStar) {
        cout << "Yes";
    } else {
        cout  << "No";
    }
    cout << std::endl;
}

Tankless::Tankless (float price, FUEL energySource, float maxGPM, float energyFactor, bool energyStar){
    this->d_price = price;
    d_energySource = energySource;
    d_maxGPM = maxGPM;
    d_energyFactor = energyFactor;
    d_energyStar = energyStar;
};

float Tankless::installedPrice(bool _hookUp, bool _newVent) const {
    float cost = 0;
    cost += getPrice() * 2;
    if (_hookUp) cost += 1000;
    if (_newVent) cost += 500;
    return cost;
};

StorageTank::StorageTank(float price, FUEL energySource, float maxGPM, float energyFactor, bool energyStar){
    d_price = price;
    d_energySource = energySource;
    d_maxGPM = maxGPM;
    d_energyFactor = energyFactor;
    d_energyStar = energyStar;
};

float StorageTank::installedPrice(bool _hookUp, bool _newVent) const {
    float cost = 0;
    cost = this->getPrice() * 1.5;
    if (_hookUp) cost += 500;
    if (_newVent) cost += 300;
    return cost;
};

WaterHeater::WaterHeater( const WaterHeater& _heater){};












