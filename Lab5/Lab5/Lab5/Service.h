//
//  Service.h
//  Lab5
//
//  Created by Nicolas Dubus on 2014-10-26.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __Lab5__Service__
#define __Lab5__Service__

#include <stdio.h>
#include <stdlib.h>   
#include "Customer.h"
#include <vector>
#include <array>
#include <iostream>
using namespace std;

struct Line {
    Customer * line[10];
    int numCustomers;
    int currentMax;
    Line();
    void addCustomer();
    void serve();
    void removeCustomer();
    bool checkFinished();
};

class Service {
    vector<Line> * servicePoints;
    int numLines;
public:
    Service(int);
    Service(Service &service);
    ~Service();
    void addCustomer();
    void serve();
    void display();
    int max();
};

#endif /* defined(__Lab5__Service__) */
