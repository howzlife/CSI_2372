#include <vector>
#include "series.h"
#include <math.h>

double* getSeries( SERIES _s, double _limit, int& length ) {
	int n;
	bool add = false;
	std::vector<double> series;

	switch (_s) {
	case 1: 
		series.push_back(1.0);
		n = 2;
		while (series.at(n-2) < _limit ) {
			if (!add){
				series.push_back(series.at(n-2) + (-1)*pow((n - 1), (n - 1))/ (n-1));
				add = true;
				n++;
			}
			else {
				series.push_back(series.at(n-2) + pow((n-1), (n-1))/(n-1));
				add = false;
				n++;
			}
		length++;
		}
	case 2:
		n = 2;
		series.push_back(2.0);
		while (series.at(n-2) < _limit ) {
			series.push_back(series.at(n-2) + pow((n-1), (n-1)) / factorial(n-1));
			length++;
			n++;
		}
	case 3:
		n = 2;
		series.push_back(0);
		series.push_back(1);
		while (series.at(n-1) < _limit ) {
			series.push_back(series.at(n-1) + n);
			n++;
			length++;
		}
	case 4:
		series.push_back(1);
		while (series.at(n-1) < _limit ) {
			series.push_back(factorial(n)); 
			n++;
			length++;
		}
	}
}

int factorial (int x) {
	if (x > 1) {
		x *= factorial(x-1);
	}
	return x;
}

double mean (double* _values, int length ) {
	double sum = 0;
	
	for (int i = 0; i < length; ++i, ++*_values) {
		sum += *_values;
	}
	return ( sum/length );
}

void printSeries (double* _first, double* _last) {
	for (; *_first != *_last; ++*_first) {
		std::cout << _first << std::endl;
	}
}

