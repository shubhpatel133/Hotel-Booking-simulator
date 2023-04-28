#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;
class Reservation
{
public:
    // constructor
    Reservation(string customerName, Date &checkIn, int duration);
    // setter
    void setDuration(int duration);
    // other
    bool overlaps(Reservation &r);
    bool lessThan(Reservation &res);
    bool lessThan(Date &d);
    void print();
    // variables
private:
    string customerName;
    Date &checkIn;
    int duration;
};
#endif
