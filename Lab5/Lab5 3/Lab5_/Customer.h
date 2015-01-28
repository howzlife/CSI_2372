#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;
class Customer
{
public:
	Customer(int num);
	~Customer();
	bool served();
	int numItems;
};

#endif