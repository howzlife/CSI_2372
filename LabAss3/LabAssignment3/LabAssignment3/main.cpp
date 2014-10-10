//
//  main.cpp
//  LabAssignment3
//
//  Created by Nicolas Dubus on 2014-10-03.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include <iostream>
#include "soccer_team.h"
#include "player.h"

int main(int argc, const char * argv[]) {
    SoccerTeam* teamA = new SoccerTeam("Packers");
    SoccerTeam* teamB = new SoccerTeam("Broncos");
    
    teamA->scores(2);
    teamB->scores(5);
    teamA->scores(10);
    teamB->scores(0);
    teamA->scores(2);
    
    teamA->carded(3);
    teamA->carded(5);
    teamA->carded(3);
    teamA->carded(3);
    teamA->carded(3);
    teamB->carded(10);
    teamB->carded(1);
    teamB->carded(2);
    teamB->carded(9);
    teamB->carded(8);
    teamB->carded(4);

    teamA->print();
    teamB->print();
    
    return 0;
}
