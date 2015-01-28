#ifndef SERVICE_H
#define SERVICE_H

#include "Customer.h"
#include <vector>
#include <iostream>
using namespace std;


class Service
{
private:
	vector<Customer*> customers;

public:
	Service();
	~Service();
	void addCustomer();
	void serve();
	void display();
	int max();
};
#endif
