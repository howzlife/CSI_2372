//
//  player.h
//  LabAssignment3
//
//  Created by Nicolas Dubus on 2014-10-03.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __LabAssignment3__player__
#define __LabAssignment3__player__
#include <string>
using namespace std;

#include <stdio.h>
class Player{
private:
    string d_firstName, d_lastName;
    int d_goals, d_yellowCards, d_redCards;
public:
Player(string first, string last, int goals = 0, int yellow = 0, int red = 0);
    void score();
    void carded();
    void print();
    
};
#endif /* defined(__LabAssignment3__player__) */
