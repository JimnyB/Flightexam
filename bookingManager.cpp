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
#include "bookingManager.hh"
using namespace std;

bookingManager::bookingManager() {}
/**
 * @brief bookingManger gets the information from the file containing the different bookings(bookings.csv) with the method called readFlight
 *
 */

void bookingManager::readBookings(string filename)
{
    ifstream booking_file(filename);
    string line;
    if (booking_file.is_open())
    {
        while (getline(booking_file, line))
        {
            stringstream sstream(line);
            // creating a new structor
            Bookings *b = new Bookings;
            string filler;
            getline(sstream, filler, ',');
            b->set_bookingno(atoi(filler.c_str()));
            getline(sstream, filler, ',');
            b->set_datestr(filler);
            getline(sstream, filler, ',');
            b->set_timestr(filler);
            getline(sstream, filler, ',');
            b->set_dep(filler);
            getline(sstream, filler, ',');
            b->set_des(filler);
            getline(sstream, filler, ',');
            b->set_sclasss(filler);
            getline(sstream, filler, ',');
            b->set_fname(filler);
            getline(sstream, filler, ',');
            b->set_lname(filler);

            myBookings.push_back(b);
        }
        booking_file.close();
    }
}
list<Bookings *> bookingManager::get_bookingsList()
{
    return myBookings;
}
