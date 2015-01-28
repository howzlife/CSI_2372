#include "Customer.h"
#include <stdlib.h>
#include <time.h>  
using namespace std;

Customer::Customer(int number)
{
	numItems = number;
}

Customer::~Customer()
{
	numItems = 0;
}

bool Customer::served()
{
	bool result = false;
	numItems -= 10;
	if (numItems <= 0)
		result = true;
	return result;
}