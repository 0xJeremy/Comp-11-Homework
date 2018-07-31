/*
* COMP11
* Homework 3
* Problem 1
* Jeremy Kanovsky
*/

#include<iostream>
#include<string>
using namespace std;

int main ()
{
	// Define and initialize variables
	int pins_per_row = 1;
	int total_pins = 0;

	// Loop that prints pin numbers per row and adds them to total
	for(int i = 0; i<73; i++)
	{
		cout << "Row " << i+1 << ": " << pins_per_row << endl;
		total_pins = total_pins + pins_per_row;
		pins_per_row = pins_per_row + 2;
	}

	// Prints total pins
	cout << "TOTAL PINS: " << total_pins << endl;


	return 0;
}
