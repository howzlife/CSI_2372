//
//  soccer_team.cpp
//  LabAssignment3
//
//  Created by Nicolas Dubus on 2014-10-03.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "soccer_team.h"
#include "player.h"
using namespace std;

SoccerTeam::SoccerTeam(string _name) {
    name = _name;
    string alphabet[11] = {"A", "B", "C", "D", "E", "F",
        "G", "H", "I", "J", "K"};
    int j = 0;
    for (Player **i = std::begin(roster); i < std::end(roster); i++) {
        *i = new Player(alphabet[j], name);
        j++;
    }
}

void SoccerTeam::tradePlayer( int _number, const Player& _p) {
    Player** x = &roster[0];
    x += _number;
    **x = _p;
}

void SoccerTeam::scores (int _number) {
    Player *x = roster[0];
    x += _number;
    x->score();
}

void SoccerTeam::carded ( int _number) {
    Player *x = roster[0];
    x += _number;
    x->carded();
}

void SoccerTeam::print (){
    for (Player* i : roster) {
        i->print();
    }
};