//
//  Customer.h
//  Lab5
//
//  Created by Nicolas Dubus on 2014-10-26.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#ifndef __Lab5__Customer__
#define __Lab5__Customer__

#include <stdio.h>
#include <stdlib.h>    
#include <iostream>
using namespace std;

class Customer {
    int numItems;
public:
    Customer();
    void served();
    int getNumItems();
    ~Customer();
    Customer(Customer &customer);
};
#endif /* defined(__Lab5__Customer__) */
