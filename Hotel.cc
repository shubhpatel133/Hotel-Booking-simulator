#include "Reservation.h"
#include "Hotel.h"
#include "Room.h"
// initialize roomAmount to 0
Hotel::Hotel()
{
    this->roomAmount = 0;
}

// Destructor to free heap memory stored in the roomarray
Hotel::~Hotel()
{
    for (int i = 0; i < roomAmount; i++)
    {
        delete roomArray[i];
    }
}
bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr)
{
    if (roomAmount >= MAX_ROOMS) // if roomamount is more then or equal to the max room
    {
        return false;
    }
    else
    {
        Room *newRoom = new Room(roomNumber, bedType, capacity, fr); // Creates new room object

        // Iterate through room array to find where the new room is smaller than rooms in the array
        for (int i = 0; i < roomAmount; i++)
        {
            cout << roomArray[i]->getRoomNumber() << endl;
            if (newRoom->lessThan(*roomArray[i]))
            {
                roomAmount += 1; // Increase room count by one so everything can be shifted

                for (int j = roomAmount - 1; j > i; j--)
                {
                    roomArray[j] = roomArray[j - 1]; // Shifts all the rooms to the right
                }
                roomArray[i] = newRoom; // Adds the new room to the array
                return true;
            }
        }
        // If no room exist in array, we add one to the array
        roomArray[roomAmount] = newRoom;
        roomAmount += 1;
        return true;
    }
    return false;
}
bool Hotel::getRoom(int roomNumber, Room **room) // Room **room is a pointer to a pointer
{
    for (int i = 0; i < roomAmount; i++) // Iterate through the room array
    {
        if (roomArray[i]->getRoomNumber() == roomNumber) // If the room number is same as getroomnumber
        {
            *room = roomArray[i];
            return true;
        }
    }
    return false;
}
bool Hotel::deleteRoom(int roomNumber)
{
    if (roomAmount == 0) // If there are no rooms in the array
    {
        return false;
    }
    else
    {
        for (int i = 0; i < roomAmount; i++) // Iterate through the room array
        {
            if (roomArray[i]->getRoomNumber() == roomNumber) // If the room number is same as getroomnumber
            {
                delete roomArray[i];                 // Deletes the room
                for (int j = i; j < roomAmount; j++) // Shifts all the rooms to the left
                {
                    roomArray[j] = roomArray[j + 1]; //
                }
                roomAmount -= 1; // Decrease room count by one(comment it out to see differnce when testing but no differnce due to seg fault)
                return true;
            }
        }
    }
    return false;
}
bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date &date, int duration)
{
    date.print();
    for (int i = 0; i < roomAmount; i++) // Iterate through the room array
    {
        if (roomArray[i]->isMatch(bedType, capacity, fr)) // if it matches the room
        {
            if (roomArray[i]->addReservation(customer, date, duration))
            {
                return true;
            }
        }
    }
    return false;
}
/*void Hotel::updateReservations(Date &d)
{
}*/
// Prints the room array
void Hotel::print()
{
    for (int i = 0; i < roomAmount; i++)
    {
        roomArray[i]->print();
    }
}
// Prints the reservations of all rooms
void Hotel::printReservations()
{
    for (int i = 0; i < roomAmount; i++)
    {
        roomArray[i]->printReservations();
    }
}
