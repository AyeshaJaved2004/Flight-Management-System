#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include<iostream>
using namespace std;
#include<string>
#include <fstream>

struct flight {
    string arrival_city;
    string arrival_country;
    string flightype;
};

void flightDetails();
void trackFlight();

#endif