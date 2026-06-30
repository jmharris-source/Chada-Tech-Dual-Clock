#include "Clock.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Constructor to initialize clock values
Clock::Clock(int h, int m, int s) {
	hours = h;
	minutes = m;
	seconds = s;
}

// Add one hour and reset after 23
void Clock::AddHour() {
	hours = (hours + 1) % 24;
}

// Add one munite and adjust hour if needed
void Clock::AddMinute() {
	minutes++;

	// If minutes exceed 59, reset and add hour
	if (minutes >= 60) {
		minutes = 0;
		AddHour();
	}
}

// Add one second and adjust minute if needed
void Clock::AddSecond() {
	seconds++;

	// If seconds exceed 59, reset and add minute
	if (seconds >= 60) {
		seconds = 0;
		AddMinute();
	}
}

// Format time values with leading zeros
string Clock::FormatTime(int value) const {

	stringstream ss;

	if (value < 10) {
		ss << "0";
	 }
	
	ss << value;

	return ss.str();
}

// Return time in 24-hour format
string Clock::Get24HourFormat() const {

	return FormatTime(hours) + ":" +
		FormatTime(minutes) + ":" +
		FormatTime(seconds);
}

// Return time in 12-hour format with AM/PM
string Clock::Get12HourFormat() const {

	int displayHour = hours;
	string period = "AM";

	// Handles midnight
	if (hours == 0) {
		displayHour = 12;
	}

	// Handles noon
	else if (hours == 12) {
		period = "PM";
	}

	return FormatTime(displayHour) + ":" +
		   FormatTime(minutes) + ":" +
		   FormatTime(seconds) + ":" + period;
}

// Display both clocks side-by-side
void Clock::DisplayClocks() const {

	cout << endl;

	cout << "*************************    *************************" << endl;
	cout << "*    12-Hour Clock      *    *      24-Hour Clock    *" << endl;

	// Use setw() to align text inside the borders
	cout << "*     "
		<< left << setw(17) << Get12HourFormat()
		<< "*    *     "
		<< left << setw(17) << Get24HourFormat()
		<< "*" << endl;

	cout << "*************************    *************************" << endl;
}
