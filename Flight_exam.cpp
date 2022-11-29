/**
 * @file safe.cpp
 * @author Jimmy Barr (jimmy.barr94@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-23
 *
 * @copyright Copyright (c) 2022
 *
 */
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
#include "bookingManager.hh"
#include "TicketManager.hh"

using namespace std;

int main(int argc,char** argv)
{
    flightManager fm; bookingManager bm;
    int opt;
    while((opt=getopt(argc,argv,"f:b:"))!=-1)
    {
        switch (opt)
        {
            case 'f':
            fm.readFlights(optarg);
            break;
            
            case 'b':
            bm.readBookings(optarg);
            break;

        }
    }
    
    //fm.readFlights("flights.csv");
    //bm.readBookings("bookings.csv");

    ticketManager tm;
    
    tm.matchseat(fm.get_flightList(), bm.get_bookingsList());
    tm.canceled_flights(fm.get_flightList());
    
    
    
    return 0;
}
