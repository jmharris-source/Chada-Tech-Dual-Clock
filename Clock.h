#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock {

private:
	int hours;
	int minutes;
	int seconds;

public:

	// Constructor
	Clock(int h = 0, int m = 0, int s = 0);

	// Time increment functions
	void AddHour();
	void AddMinute();
	void AddSecond();

	// Time formatting functions
	std::string Get12HourFormat() const;
	std::string Get24HourFormat() const;

	// Display both clocks
	void DisplayClocks() const;

private:

	// Helper function to format time with leading zeros
	std::string FormatTime(int value) const;
};
#endif
