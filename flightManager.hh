
/**
 * @brief flightManager gets the information from the file containing the different flights(Flights.csv) with the method called readFlights
 *
 */

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <list>
#include <fstream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "Flight.hh"
#include "bookings.hh"
#include "TicketManager.hh"

using namespace std;
#ifndef FLIGHTMANAGER_CLASS
#define FLIGHTMANAGER_CLASS

class flightManager
/**
 * @brief flightManager gets the information from the file containing the different flights(Flights.csv) with the method called readFlights
 * 
 */

{
    list<Flights *> myFlights;

public:
    flightManager();
    void readFlights(string filename);
    list<Flights *> get_flightList();

};
#endif