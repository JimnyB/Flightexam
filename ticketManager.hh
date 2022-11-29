
#ifndef TICKETMANAGER_CLASS
#define TICKETMANAGER_CLASS

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <cstring>
#include "flight.hh"
#include "bookings.hh"
using namespace std;

class ticketManager
{
public:
    ticketManager();
    void canceled_flights(list<Flights *> myFlights);
    void matchseat(list<Flights *> myFlights, list<Bookings *> myBookings);
};
#endif
