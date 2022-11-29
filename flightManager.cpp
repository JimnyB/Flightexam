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
#include "bookingManager.hh"
#include "FlightManager.hh"

flightManager::flightManager() {}

/**
 * @brief flightManager gets the information from the file containing the different flights(Flights.csv) with the method called readFlights
 * 
 */

void flightManager::readFlights(string filename)
{
    ifstream flight_file(filename);
    string line;
    if (flight_file.is_open())
    {
        while (getline(flight_file, line))
        {
            stringstream sstream(line);
            Flights *f = new Flights;
            string filler;
            // temporary variable called "filler"

            getline(sstream, filler, ',');
            f->set_flightno(atoi(filler.c_str()));

            getline(sstream, filler, ',');
            f->set_dep(filler);
            getline(sstream, filler, ',');
            f->set_des(filler);
            getline(sstream, filler, ',');
            f->set_datestr(filler);
            getline(sstream, filler, ',');
            f->set_timestr(filler);
            getline(sstream, filler, ',');
            f->set_nfs(atoi(filler.c_str()));
            getline(sstream, filler, ',');
            f->set_nbs(atoi(filler.c_str()));
            getline(sstream, filler, ',');
            f->set_nes(atoi(filler.c_str()));

            myFlights.push_back(f);
        }
        flight_file.close();
    }
}
list<Flights *> flightManager::get_flightList()
{
    return myFlights;
}
