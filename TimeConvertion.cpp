// Created by Ian Catapano
// Created on 3/2/2014
// Homework 4

#include <iostream>
#include <iomanip>
using namespace std;

struct TwelveHour 
{
	int hour;
	int minute;
	char meridiem;
};

bool validateTime(int h, int m); //Validates if time entered by user is valid.
TwelveHour convertTime(int h, int m); //Converts time from 24-hour notation to 12-hour notation.

int main()
{
	char again = 'y';
	int userHours = 0;
	int userMinutes = 0;
	char colon;

	while (again == 'y')
	{
		bool check = false;

		while (check == false)
		{
			cout << "Enter a time in 24-hour notation: ";
			cin >> userHours >> colon >> userMinutes;
			check = validateTime(userHours, userMinutes);
		}
		TwelveHour currentEntry = convertTime(userHours, userMinutes);
		cout << "Convert " << userHours << ":" << setfill('0') << setw(2) << userMinutes << " to 12-hour notation: " << currentEntry.hour << ':'
			<< setw(2) << currentEntry.minute << " " << currentEntry.meridiem << ".M." << endl;
		cout << "Do you want to convert again (y/n)?: ";
		cin >> again;
		cout << endl;
	}
	return 0;
}

bool validateTime(int h, int m)
{
	if (h == 24 && m == 0)
		return true;
	else if (h == 0 && m == 0)
	{
		cout << "The time you entered is not a valid time, please try again." << endl;
		return false;

	}
	else if (h >= 0 && h < 24 && m >= 0 && m <= 59)
		return true;
	else
	{
		cout << "The time you entered is not a valid time, please try again." << endl;
		return false;
	}
}

TwelveHour convertTime(int h, int m)
{
	TwelveHour entry;

	if (h == 0)
	{
		entry.meridiem = 'A';
		entry.hour = 12;
		entry.minute = m;
	}
	else if (h < 12)
	{
		entry.meridiem = 'A';
		entry.hour = h;
		entry.minute = m;
	}
	else if (h == 24)
	{
		entry.meridiem = 'A';
		entry.hour = h - 12;
		entry.minute = m;
	}
	else if (h == 12)
	{
		entry.meridiem = 'P';
		entry.hour = h;
		entry.minute = m;
	}
	else
	{
		entry.meridiem = 'P';
		entry.hour = h - 12;
		entry.minute = m;
	}
	return entry;
}