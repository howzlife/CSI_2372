//
//  player.cpp
//  LabAssignment3
//
//  Created by Nicolas Dubus on 2014-10-03.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "player.h"
#include <iostream>
using namespace std;

Player::Player(string first, string last, int goals, int yellow, int red)
    {
        d_firstName = first;
        d_lastName = last;
        d_goals = goals;
        d_yellowCards = yellow;
        d_redCards = red;
    }

void Player::score() {d_goals++;}
void Player::carded() {
     d_yellowCards++;
    if (d_yellowCards == 4) {
        d_redCards++;
        d_yellowCards = 0;
    }
}
void Player::print() {
    std::cout << d_firstName << " " << d_lastName << std::endl;
    std::cout << "goals: " << d_goals << std::endl;
    std::cout << "yellow cards: " << d_yellowCards << std::endl;
    std::cout << "red cards: " << d_redCards << std::endl;
    std::cout << std::endl;
}