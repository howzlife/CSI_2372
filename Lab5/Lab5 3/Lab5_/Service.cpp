
#include "Service.h"
#include <stdlib.h>
#include <time.h>  
using namespace std;


//Constructors and Destructors
Service::Service()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 100 + 1;
		customers.push_back(new Customer(random));
	}
}

Service::~Service()
{
	for (Customer* customer : customers)
	{
		delete customer;
		customer = NULL;
	}
	//delete every element in array
	customers.clear();
}

//Methods
void Service::addCustomer()
{
	int radnom = rand() % 100 + 1;
	customers.push_back(new Customer(radnom));
}

void Service::serve()
{
	int size = customers.size();
	for (int i = 0; i < size; i++)
	{
		if (customers[i]->served() == true)
		{
			delete customers[i];
			customers[i] = NULL;

			//Get rid of the customer, prevent memory leak
			customers.erase(customers.begin() + i);

			
			size = customers.size();
		}
	}
}

void Service::display()
{
	int size = customers.size();
	int point[100];
	for (int j = 0; j< 100; j++)
	{
		point[j] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		point[customers[i]->numItems - 1] ++;
	}

	//display
	for (int k = 0; k< 100; k++)
	{
		if (point[k] > 0)
			cout << "Line Number " << k + 1 << " has " << point[k] << " Customers" << endl;
	}
}

int Service::max()
{
	return customers.max_size();
}