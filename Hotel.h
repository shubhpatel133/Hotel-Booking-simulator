#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
#include "Reservation.h"
#include "defs.h"
#include "Room.h"

using namespace std;
class Hotel
{
public:
    // constructors
    Hotel();
    ~Hotel();
    // other
    bool addRoom(int roomNumber, string bedType, int capacity, bool fr);
    bool deleteRoom(int roomNumber);
    bool getRoom(int roomNumber, Room **room);
    bool addReservation(string customer, string bedType, int capacity, bool fr, Date &date, int duration);
    void updateReservations(Date &d);
    // print
    void print();
    void printReservations();
    // variables
private:
    Room *roomArray[MAX_ROOMS];
    int roomAmount;
};
#endif