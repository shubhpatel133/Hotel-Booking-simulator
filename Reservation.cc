#include "Reservation.h"
#include <iostream>
using namespace std;

Reservation::Reservation(string customerName, Date &checkIn, int duration)
    : checkIn(checkIn)
{
    this->customerName = customerName;
    this->duration = duration;
}
// setter to make sure that the duration is at least 1
void Reservation::setDuration(int duration)
{
    if (duration < 1)
    {
        duration = 1;
    }
    else
    {
        duration = duration;
    }
}
// Checks if the reservation overlaps with given reservation
bool Reservation::overlaps(Reservation &r)
{
    if (checkIn.equals(r.checkIn))
    {
        return true;
    }
    else if (checkIn.lessThan(r.checkIn))
    {
        Date checkout(checkIn);
        checkout.addDays(duration);
        if (checkout.equals(r.checkIn))
        {
            return false;
        }
        if (checkout.lessThan(r.checkIn))
        {
            return false;
        }
        return true;
    }
    else
    {
        Date checkout(r.checkIn);
        checkout.addDays(r.duration);
        if (checkout.equals(checkIn))
        {
            return false;
        }
        if (checkout.lessThan(checkIn))
        {
            return false;
        }
        return true;
    }
    return false;
}
// Checks if the reservation is less than given reservation
bool Reservation::lessThan(Reservation &res)
{
    if (overlaps(res))
    {
        return false;
    }
    else
    {
        return (checkIn.lessThan(res.checkIn));
    }
}
// Checks if the reservation is less than given date
bool Reservation::lessThan(Date &d)
{
    if (checkIn.lessThan(d))
    {
        return true;
    }
    else
    {
        return false;
    }
}
// output
void Reservation::print()
{
    cout << "Reservation for " << customerName << " on "
         << " "
         << ", "
         << " for " << duration << endl;
    checkIn.print();
}