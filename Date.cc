#include "Date.h"
using namespace std;
Date::Date()
{
	setDate(1901, 1, 1);
}

Date::Date(int y, int m, int d)
{
	setDate(y, m, d);
}

Date::Date(const Date &d)
{
	setDate(d.year, d.month, d.day);
}

// setters
void Date::setDay(int d)
{
	int max = getMaxDay();
	if (d > max)
		d = max;
	if (d < 1)
		d = 1;
	day = d;
}

void Date::setMonth(int m)
{
	if (m > 12)
		m = 12;
	if (m < 1)
		m = 1;
	month = m;
}

void Date::setYear(int y)
{
	if (y < 1901)
		y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}

void Date::setDate(Date &d)
{
	setDate(d.year, d.month, d.day);
}

// getters
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
string Date::getMonthName()
{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month - 1];
}

// other
void Date::incDate()
{
	day += 1;
	// is it now the 32nd of January (for example)? If so make it February 1st
	if (day > getMaxDay())
	{
		day = 1;
		month += 1;
	}

	// is it now the 13th month? (Smarch 1st) If so make it January of next year
	// https://simpsonswiki.com/wiki/Smarch
	if (month > 12)
	{
		month = 1;
		year += 1;
	}
}

void Date::print()
{
	cout << getMonthName() << " " << day << ", " << year;
}
// if dates in question are same then return true
bool Date::equals(Date &d)
{
	if (year == d.year && month == d.month && day == d.day) // if all are same
	{
		return true; // return true
	}
	else
		return false; // else return false
}

// returns true if this date is less than the date passed in
bool Date::lessThan(Date &d)
{
	if (year == d.year) // if the years are the same
	{
		if (month == d.month) // if the months are the same
		{
			return (day < d.day); // if day is than day passed in
		}
		else
		{
			return (month < d.month); // if month is less than month passed in
		}
	}
	else
	{
		return (year < d.year); // if year is less than year passed in
	}
}

void Date::addDays(int days)
{
	for (int i = 0; i < days; i++) // add days
	{
		incDate();
	}
}
int Date::getMaxDay()
{
	switch (getMonth())
	{
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return 28;
	default:
		return 31;
	}
}
