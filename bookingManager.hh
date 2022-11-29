#ifndef BOOKINGMANAGER_CLASS
#define BOOKINGMANAGER_CLASS

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <cstring>
#include <unistd.h>

#include "Flight.hh"
#include "bookings.hh"
#include "FlightManager.hh"
#include "TicketManager.hh"

using namespace std;

/**
 * @brief bookingManger gets the information from the file containing the different bookings(bookings.csv) with the method called readFlight
 *
 */

class bookingManager
{
    list<Bookings *> myBookings;

public:
    bookingManager();
    void readBookings(string filename);
    list<Bookings *> get_bookingsList();
};
#endif
