//
//  Customer.cpp
//  Lab5
//
//  Created by Nicolas Dubus on 2014-10-26.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "Customer.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Customer::Customer() {
    numItems = rand() % 100;
}

Customer::~Customer() {
    delete this;
}
Customer::Customer(Customer &customer) : numItems(customer.numItems){}

void Customer::served() {
    if (numItems >= 10 ) {
        numItems -= 10;
    }
    else numItems -=numItems;
}

int Customer::getNumItems() {
    return numItems;
}
