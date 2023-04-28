#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
#include "Reservation.h"
#include "defs.h"

using namespace std;
class Room
{
public:
    // constructors
    Room(int roomNumber, string bedType, int capacity, bool hasFridge);
    ~Room();
    // getter
    int getRoomNumber();
    // other
    bool isMatch(string bt, int cap, bool f);
    bool lessThan(Room &r);
    bool addReservation(string customerName, Date &d, int duration);
    void updateReservations(Date &currentDate);
    void printReservations();
    void print();
    // variables
private:
    int roomNumber;
    string bedType;
    int capacity;
    bool hasFridge;
    Reservation *reservationArray[MAX_RES];
    int reservationAmount;
};
#endif
