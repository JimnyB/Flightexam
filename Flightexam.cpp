/**
 * @file Flightexam.cpp
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
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

/**
 * @brief class Flights
 * 
 */

class Flights
{
private:
    int flightno;
    string dep;
    string des;
    string datestr;
    string timestr;
    int nfs;
    int fs;
    int nbs;
    int bs;
    int nes;
    int es;

public:
    Flights() { this->fs = 0, this->bs = 0, this->es = 0; }
  // Declaring setters & getters for the class flight
  // Setters
    void set_flightno(int flightno)
    {
        this->flightno = flightno;
    }
    void set_dep(string dep)
    {
        this->dep = dep;
    }
    void set_des(string des)
    {
        this->des = des;
    }
    void set_datestr(string datestr)
    {
        this->datestr = datestr;
    }
    void set_timestr(string timestr)
    {
        this->timestr = timestr;
    }
    void set_nfs(int nfs)
    {
        this->nfs = nfs * 7;
    }
    void set_nbs(int nbs)
    {
        this->nbs = nbs * 7;
    }
    void set_nes(int nes)
    {
        this->nes = nes * 7;
    }

    // getters
    int get_flightno()
    {
        return flightno;
    }
    string get_dep()
    {
        return dep;
    }
    string get_des()
    {
        return des;
    }
    string get_datestr()
    {
        return datestr;
    }
    string get_timestr()
    {
        return timestr;
    }
    int get_nfs()
    {
        return nfs;
    }
    int get_fs()
    {
        return fs;
    }
    int get_nbs()
    {
        return nbs;
    }
    int get_bs()
    {
        return bs;
    }
    int get_nes()
    {
        return nes;
    }
    int get_es()
    {
        return es;
    }
     // Used in the SeatMatching method to keep track of the amount of seats that is booked of the different classes
    void increaseFs()
    {
        this->fs = fs + 1;
    }
    void increaseBs()
    {
        this->bs = bs + 1;
    }
    void increaseEs()
    {
        this->es = es + 1;
    }
};
/**
 * @brief Booking class
 * 
 */

class Bookings
{
private:
    int bookingno;
    string datestr;
    string timestr;
    string dep;
    string des;
    string sclass;
    string fname;
    string lname;

public:
    Bookings() {}

    void set_bookingno(int bookingno)
    {
        this->bookingno = bookingno;
    }
    void set_datestr(string datestr)
    {
        this->datestr = datestr;
    }
    void set_timestr(string timestr)
    {
        this->timestr = timestr;
    }
    void set_dep(string dep)
    {
        this->dep = dep;
    }
    void set_des(string des)
    {
        this->des = des;
    }
    void set_sclasss(string sclass)
    {
        this->sclass = sclass;
    }
    void set_fname(string fname)
    {
        this->fname = fname;
    }
    void set_lname(string lname)
    {
        this->lname = lname;
    }
    // getters
    int get_bookingsnum()
    {
        return bookingno;
    }
    string get_datestr()
    {
        return datestr;
    }
    string get_timestr()
    {
        return timestr;
    }
    string get_dep()
    {
        return dep;
    }
    string get_des()
    {
        return des;
    }
    string get_sclass()
    {
        return sclass;
    }
    string get_fname()
    {
        return fname;
    }
    string get_lname()
    {
        return lname;
    }
};
/**
 * @brief flightManager gets the information from the file containing the different flights(Flights.csv) with the method called readFlights
 * 
 */

class flightManager
{
    list<Flights *> myFlights; 

public:
    void readFlights(string filename)
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
                //temporary variable called "filler"

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
    list<Flights *> get_flighList()
    {
        return myFlights;
    }
};

/**
 * @brief bookingManger gets the information from the file containing the different bookings(bookings.csv) with the method called readFlight
 * 
 */

class bookingManager
{
    list<Bookings *> myBookings;

public:
    bookingManager() {}
    void readBookings(string filename)
    {
        ifstream booking_file(filename);
        string line;
        if (booking_file.is_open())
        {
            while (getline(booking_file, line))
            {
                stringstream sstream(line);
                //creating a new structor
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
    list<Bookings *> get_bookingsList()
    {
        return myBookings;
    }
};

class ticketManager
{
public:
    ticketManager() {}
    void canceled_flights(list<Flights *> myFlights)
    {
        list<Flights *>::iterator fit;
        for (fit = myFlights.begin(); fit != myFlights.end(); ++fit)
            if ((*fit)->get_fs() == 0 && (*fit)->get_bs() == 0 && (*fit)->get_es() == 0)
            {
                ofstream outfile("canceled_flights.txt", ios_base::app);

                if (outfile.is_open())
                {
                    outfile << "Flight nr " << (*fit)->get_flightno() << " " << (*fit)->get_timestr() << "is canceled" << endl;
                }
                outfile.close();
            }
    }
    /**
     * @brief Method that checks the seatclass and allocates a seat
     * 
     * @param myFlights 
     * @param myBookings 
     */
    void matchseat(list<Flights *> myFlights, list<Bookings *> myBookings)
    {
    
        list<Bookings *>::iterator bit;
        list<Flights *>::iterator fit;

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
                        ticket_file << "ROW:" << row << "    " << "SEAT:" << seat << endl;
                    }
                }
            }
        }
    }
};

int main()
{
    flightManager fm;
    fm.readFlights("flights.csv");

    bookingManager bm;
    bm.readBookings("bookings.csv");

    ticketManager tm;
    tm.matchseat(fm.get_flighList(), bm.get_bookingsList());
    tm.canceled_flights(fm.get_flighList());

    return 0;
}

    /*
        void showlist()
        {

            list<Bookings *>::iterator it;
            for (it = myBookings.begin(); it != myBookings.end(); ++it)
            {
                cout << (*it)->get_dep() << endl;
            }
        }
        */

           /*
        void showlist()
        {
            list<Flights *>::iterator it;
            for (it = myFlights.begin(); it != myFlights.end(); ++it)
            {
                cout << (*it)->get_dep() << endl;
            }
        }
        */