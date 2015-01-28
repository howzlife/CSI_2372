//
//  main.cpp
//  Lab5
//
//  Created by Nicolas Dubus on 2014-10-26.
//  Copyright (c) 2014 WorldDubination. All rights reserved.
//

#include <iostream>
#include "Customer.h"
#include "Service.h"
using namespace std;

int main(int argc, const char * argv[]) {

    for (int i = 0; i < 10; ++i) {
        int max = 0;
        for (int i = 1; i < 10000; ++i) {
            Service service(i);
            service.addCustomer();
            service.addCustomer();
            service.addCustomer();
            service.serve();
            service.display();
            if (service.max() > max) max = service.max();
        }
        if (max < 20) {
            std::cout << "We need " << max << " service points" <<std::endl;
            break;
        }
    }
    return 0;
}
