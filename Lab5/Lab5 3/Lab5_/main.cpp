//
//  main.cpp
//  Lab5_
//
//  Created by Nicolas Dubus on 2014-10-28 3811637
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include "Customer.h"
#include "Service.h"
#include <iostream>
using namespace std;


int main()
{
    Service* service = new Service();
    
    //Add Customers
    for (int i = 0; i < 10; i++)
    {
        service->addCustomer();
        service->addCustomer();
        service->addCustomer();
        service->serve();
        service->display();
    }
    
    return 0;
}