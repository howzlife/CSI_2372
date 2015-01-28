//
//  Service.cpp
//  Lab5
//
//  Created by Nicolas Dubus on 2014-10-26.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "Service.h"
#include <stdlib.h>    
#include <iostream>
#include <array>
using namespace std;


Line::Line () : numCustomers(0), currentMax(10){
}

Service::Service(int numberLines) : numLines(numberLines) {
    for (int i = 0; i < numLines; ++i) {
        Line * x = new Line();
        servicePoints->push_back(*x);
    }
}

Service::~Service(){}

Service::Service(Service &service) : numLines(service.numLines){}

void Service::addCustomer(){
    Line * smallestLine = &servicePoints->front();
    int * minCustomers = &smallestLine->numCustomers;
    for (std::vector<Line>::iterator
         it = servicePoints->begin(); it != servicePoints->end();
         ++it) {
        if (it->numCustomers < *minCustomers && it->numCustomers >= 0) {
            minCustomers = &it->numCustomers;
            smallestLine = &*it;
            cout << "min Customers" << *minCustomers << " smallestLine " << endl;
        }
    }
    smallestLine->addCustomer();
}

void Line::addCustomer() {
    Customer x;
    if (this->numCustomers == currentMax) {
        int size1 = currentMax;
        Customer * line2 = new Customer[size1 * 2];
        for (int i = 0; i < numCustomers; ++i) {
            line2[i] = *line[i];
        }
        Customer * line[size1 * 2];
        for (int i = 0; i < numCustomers; ++i) {
            line[i] = &line2[i];
        }
        currentMax *=2;
    }
    *line[numCustomers] = x;
    numCustomers++;
}

void Line::removeCustomer() {
    if (line[0]->getNumItems() == 0) {
        for (int i = 0; i < numCustomers; i++)
            *line[i] = *line[1];
    }
    numCustomers--;
}

void Line::serve() {
    line[0]->served();
}

bool Line::checkFinished() {
    return (line[0]->getNumItems() == 0);
}

void Service::serve() {
    for (std::vector<Line>::iterator it = servicePoints->begin(); it < servicePoints->end(); ++it) {
        it->serve();
        if (it->checkFinished()) {
            it->removeCustomer();
        }
    }
}

void Service::display () {
    int i = 1;
    for (std::vector<Line>::iterator it = servicePoints->begin(); it < servicePoints->end(); ++it) {
        std::cout << "Line #" << i << ": " << it->numCustomers << std::endl;
    }
}

int Service::max() {
    Line * maxLine = &servicePoints->front();
    int max = maxLine->numCustomers;
    
    for (std::vector<Line>::iterator it = servicePoints->begin(); it < servicePoints->end(); ++it) {
        if (it->numCustomers > max) {
            max = it->numCustomers;
        }
    }
    return max;
}

