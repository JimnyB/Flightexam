#include <iostream>
#include <cstdlib>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <cstring>

#include "flight.hh"
#include "bookings.hh"
#include "ticketManager.hh"
#include "bookingManager.hh"

using namespace std;

ticketManager::ticketManager() {}
/**
 * @brief the "fit"-itterator itterates through the flightlist and checks if there is any flights with no bookings.
 * 
 * 
 */

void ticketManager::canceled_flights(list<Flights *> myFlights)
{
    list<Flights *>::iterator fit;
    for (fit = myFlights.begin(); fit != myFlights.end(); ++fit)
        if ((*fit)->get_fs() == 0 && (*fit)->get_bs() == 0 && (*fit)->get_es() == 0)
        {
            ofstream outfile("canceled_flights.txt");
            if (outfile.is_open())
            {
                outfile << "Flight nr " << (*fit)->get_flightno() << " " << (*fit)->get_timestr() << "is canceled" << endl;
            }
            outfile.close ();
        }
}

   /**
     * @brief Method that checks the seatclass and allocates a seat
     * 
     * 
     * @param myFlights 
     * @param myBookings 
     */

void ticketManager::matchseat(list<Flights *> myFlights, list<Bookings *> myBookings)
{

    list<Bookings *>::iterator bit;
    list<Flights *>::iterator fit;
    // fit and bit itterators check if there are any bookings that matches flights
    for (bit = myBookings.begin(); bit != myBookings.end(); ++bit)
    {
        for (fit = myFlights.begin(); fit != myFlights.end(); ++fit)
        {
            if ((*bit)->get_dep() == (*fit)->get_dep() && (*bit)->get_des() == (*fit)->get_des() && (*bit)->get_datestr() == (*fit)->get_datestr() && (*bit)->get_timestr() == (*fit)->get_timestr())
            {
                int seat;
                int row;

                // checks the first letter in the string f= first, b=business and e=economy-class
                switch ((*bit)->get_sclass()[0])
                {
                case 'f':
                    (*fit)->increaseFs();
                    seat = (*fit)->get_fs();
                    // if a first class seat is found its adds the amount of seats so that the same seats is never booked twice
                    row = seat / 7 + 1;
                    break;

                case 'b':
                    (*fit)->increaseBs();
                    seat = (*fit)->get_bs() + (*fit)->get_nfs();
                    row = seat / 7 + 1;
                    break;
                case 'e':
                    (*fit)->increaseEs();
                    seat = (*fit)->get_es() + (*fit)->get_nfs() + (*fit)->get_nbs();
                    row = seat / 7 + 1;
                    break;
                default:
                    break;
                }
                /**
                 * @brief
                 *
                 */

                char filename[20];
                sprintf(filename, "ticket-%d.txt", (*bit)->get_bookingsnum());
                ofstream ticket_file(filename);
                if (ticket_file.is_open())
                {
                    ticket_file << "BOOKING:" << (*bit)->get_bookingsnum() << endl;
                    ticket_file << "FLIGHT:" << (*fit)->get_flightno();
                    ticket_file << "\nDEPARTURE:" << (*bit)->get_dep();
                    ticket_file << "\nDESTINATION:" << (*fit)->get_des() << " ";
                    ticket_file << (*fit)->get_datestr() << " ";
                    ticket_file << (*fit)->get_timestr() << endl;
                    ticket_file << "PASSENGER:" << (*bit)->get_fname() << " " << (*bit)->get_lname();
                    ticket_file << "\nCLASS:" << (*bit)->get_sclass() << endl;
                    ticket_file << "ROW:" << row << "    "
                                << "SEAT:" << seat << endl;
                }
            }
        }
    }
}
