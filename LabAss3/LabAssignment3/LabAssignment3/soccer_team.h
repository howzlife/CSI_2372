//
//  soccer_team.h
//  LabAssignment3
//
//  Created by Nicolas Dubus on 2014-10-03.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __LabAssignment3__soccer_team__
#define __LabAssignment3__soccer_team__
#include <string>
#include <array>
#include "player.h"
using namespace std;

class SoccerTeam{
private:
    string name;
    Player* roster[11];
    SoccerTeam();
public:
    SoccerTeam( string _name = "Team A");
    void tradePlayer( int _number, const Player& _p);
    void scores (int _number);
    void carded (int _number);
    void print();
};


#include <stdio.h>

#endif /* defined(__LabAssignment3__soccer_team__) */
