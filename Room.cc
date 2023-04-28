#include "Room.h"
#include <iostream>
using namespace std;
// Constructor to initialize the variables
Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge)
{
    this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    this->reservationAmount = 0;
}
// Destructor to free heap stored in the reservation array
Room::~Room()
{
    for (int i = 0; i < reservationAmount; i++)
    {
        delete reservationArray[i];
    }
}
// getter, return room number
int Room::getRoomNumber()
{
    return roomNumber;
}
// Checks if the current room is a match for specific parameters
bool Room::isMatch(string bt, int cap, bool f)
{
    if (f)
    {
        if ((bedType.compare(bt) == 0) && capacity >= cap && f == hasFridge) // If the room has a fridge
        {
            return true;
        }
        else
            return false;
    }
    else
    {
        if ((bedType.compare(bt) == 0) && capacity >= cap) // If the room does not have a fridge
            return true;
        else
            return false;
    }
}
bool Room::lessThan(Room &r)
{
    if (roomNumber < r.getRoomNumber()) // If the room number is smaller than the r room number
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Room::addReservation(string customerName, Date &d, int duration)
{
    if (reservationAmount >= MAX_RES)
    {
        return false;
    }
    else
    {
        Reservation *newReservation = new Reservation(customerName, d, duration); // Creates new reservation object
        // Check for any overlaps
        for (int i = 0; i < reservationAmount; i++)
        {
            reservationArray[i]->print();
            if (reservationArray[i]->overlaps(*newReservation))
            {
                printReservations();

                return false;
            }
        }
        // finds where the new reservation is smaller than the reservations in the array
        for (int i = 0; i < reservationAmount; i++)
        {
            if (newReservation->lessThan(*reservationArray[i]))
            {
                reservationAmount += 1;
                // Shifts all the reservations after the new reservation to the right
                for (int j = reservationAmount - 1; j > i; j--)
                {
                    reservationArray[j] = reservationArray[j - 1];
                }
                // Updates the index
                reservationArray[i] = newReservation;
                printReservations();
                return true;
            }
        }
        // If reservation is bigger than all the reservations in the array then we add it to the end of array
        reservationArray[reservationAmount] = newReservation;
        reservationAmount += 1;
        printReservations();
        return true;
    }
}
/*void Room::updateReservations(){

}*/
// Prints the room number, the bedtype, the capacity and if the room will have a fridge or not
void Room::print()
{
    if (hasFridge)
        cout << "Room number is " << roomNumber << " with a " << bedType << " bed "
             << " with capacity of " << capacity << " with a fridge" << endl;
    else
        cout << "Room number is " << roomNumber << " with a " << bedType << "bed "
             << " with capacity of " << capacity << " without fridge" << endl;
}
// Prints the room number and the reservations of the room
void Room::printReservations()
{
    cout << endl;
    this->print();
    cout << roomNumber << " Reservations: " << endl;
    for (int i = 0; i < reservationAmount; i++)
    {
        reservationArray[i]->print();
    }
}