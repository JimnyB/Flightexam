#include <string>


using namespace std;
#ifndef FLIGHTS_CLASS
#define FLIGHTS_CLASS
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
#endif