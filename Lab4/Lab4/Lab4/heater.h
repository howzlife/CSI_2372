//
//  heater.h
//  Lab4
//
//  Created by Nicolas Dubus on 2014-10-09.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __Lab4__heater__
#define __Lab4__heater__

#include <iostream>

using namespace std;

class WaterHeater {
public:
    enum FUEL { Gas, Electric, Propane, Coal, Wood };
protected:
    float d_price;
    FUEL d_energySource;
    float d_maxGPM;
    float d_energyFactor;
    bool d_energyStar;
    
public:
    virtual ~WaterHeater(){};
    WaterHeater() = default;
    WaterHeater(float price, FUEL energySource, float maxGPM, float energyFactor, bool energyStar) : d_price(price),
    d_energySource(energySource), d_energyFactor(energyFactor), d_maxGPM(maxGPM), d_energyStar(energyStar){};
    
    WaterHeater( const WaterHeater& _heater);
    
    float getPrice() const;
    
    virtual WaterHeater* clone() const{ return nullptr;}
    
    virtual float installedPrice(bool _hookUp, bool _newVent ) const = 0;
        
    void print();
};

class Tankless : public WaterHeater {

public:
    Tankless* clone() const{
        return new Tankless(*this);
    }
    
    Tankless() = default;
    
    Tankless (float d_price, FUEL d_energySource, float d_maxGPM, float d_energyFactor,
              bool d_energyStar = true);
    
    virtual float installedPrice ( const bool _hookUp, const bool _newVent) const override;
};

class StorageTank : public WaterHeater {
    
public:
    StorageTank* clone() const{
        
        return new StorageTank( *this );
    }
    
    StorageTank() = default;
    
    StorageTank (float d_price, FUEL d_energySource, float d_maxGPM, float d_energyFactor,
                 bool d_energyStar = true);
    
    float installedPrice ( bool _hookUp, bool _newVent) const override;
};

#endif /* defined(__Lab4__heater__) */
