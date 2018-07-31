/*

UNFINISHED -- DOES NOT CURRENTLY WORK
* COMP11
* Homework 4
* Problem 1
* Jeremy Kanovsky
*
* Input: 10 feet, 6 inches
* Output: 3 meters, 20 centimeters
*
* Input: 50 feet, 5 inches
* Output: 15 meters, 37 centimeters
*
* Input: 12 feet, 4 inches
* Output: 3 meters, 76 centimeters
*/

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

//Declare prototypes
int feet();
int inches();
bool keep_going();
void conversion(int, int);

int main()
{
	//Create loop for multiple conversions
	bool flag = true;
	while(flag)
	{
		//Call functions for feet and inches
		int num_feet = feet();
		int num_inches = inches();

		//Convert feet and inches to meters and centimeters
		conversion(num_feet, num_inches);
		flag = keep_going();
	}


	return 0;
}

int feet()
{
	//Create loop to catch negative values
	while(true)
	{
		//Ask for input
		cout << "Please enter a number of feet: ";
		int feet;
		cin >> feet;

		//Check for negative values
		if(feet >= 0)
		{
			return feet;
		}
	}
}

int inches()
{
	//Create loop to catch negative values
	while(true)
	{
		//Ask for input
		cout << "Please enter a number of inches: ";
		int inches;
		cin >> inches;

		//Check for negative values
		if((inches >= 0) && (inches <= 11))
		{
			return inches;
		}
	}
}

bool keep_going()
{
	//Create loop to catch values not "Y", "N"
	while(true)
	{
		//Prompt user
		cout << "Would you like to convert more measurements? (Y/N)" 
		<< endl;
		string again;
		cin >> again;

		//Return user value
		if(again == "Y")
			return true;
		else if (again == "N")
			return false;
	}
}

void conversion(int feet, int inches)
{
	//Convert to centimeters and meters
	double centimeters = ((feet*12)+inches)*2.54;
	double meters = 0;

	//Change centimeters to meters when centimeters is over 1 meter
	while(centimeters >= 100)
	{
		centimeters = centimeters-100;
		meters++;
	}

	//Print out converted values
	cout << (int)round(meters) << " Meter(s), and " 
	<< (int)round(centimeters)  
	<< " centimeters" << endl;
}