/*
* COMP11
* Homework 1
* Problem 1
* Jeremy Kanovsky
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "Please enter eight (8) integers." << endl;

	int sum = 0;
	int user_input = 0;

	for(int x = 0; x<8; x++)
	{
		cin >> user_input;
		sum = sum+user_input;
	}

	cout << "The total is: " << sum << "." << endl;
}
