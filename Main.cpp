/*
* Jasmine Harris
* May 18, 2026
* Purpose: Chada Tech Clock Project
* CS 210
*/

#include <iostream>
#include "Clock.h"

using namespace std;

// Function to display the menu
void DisplayMenu() {
	cout << endl;
	cout << "*************************" << endl;
	cout << "* 1 - Add One Hour     *" << endl;
	cout << "* 2 - Add One Minute   *" << endl;
	cout << "* 3 - Add One Second   *" << endl;
	cout << "* 4 - Exit Program     *" << endl;
	cout << "*************************" << endl;
}

int main() {
	int hour;
	int minute;
	int second;
	int choice = 0;

	// Get initial time from the user
	cout << "Enter initial hour (0-23): ";
	cin >> hour;

	// Validate hour input
	while (hour < 0 || hour > 23) {
		cout << "Invalid hour. Enter again: ";
		cin >> hour;
	}

	cout << "Enter initial minute (0-59): ";
	cin >> minute;

	// Validate minute input 
	while (minute < 0 || minute > 59) {
		cout << "Invalid minute. Enter again: ";
		cin >> minute;
	}

	cout << "Enter initial second (0-59): ";
	cin >> second;

	// Validate second input
	while (second < 0 || second > 59) {
		cout << "Invalid second. Enter again: ";
		cin >> second;
	}

	// Create clock object
	Clock myClock(hour, minute, second);

	// Continue looping until user exits
	while (choice != 4) {
		// Display both clocks
		myClock.DisplayClocks();

		// Display Menu
		DisplayMenu();

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {

		case 1:
			// Add one hour
			myClock.AddHour();
			break;

		case 2: 
			// Add one minute
			myClock.AddMinute();
			break;

		case 3:
			// Add one second
			myClock.AddSecond();
			break;

		case 4:
			// Exit program
			cout << "Exiting program...." << endl;
			break;
		
		default:
			// Handles invalid menu options
			cout << "Invalid option. Please try again." << endl;
		}
	}

	return 0;
}