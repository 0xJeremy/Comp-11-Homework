/*
* COMP11
* Homework 4
* Problem 2
* Jeremy Kanovsky
*/

//Include Statements
#include<iostream>
#include<string>
using namespace std;

//Prototype
void swapint(int &, int &);

int main()
{
	//Ask for integers
	cout << "Please enter four integers." << endl;
	int one, two, three, four;
	cin >> one;
	cin >> two;
	cin >> three;
	cin >> four;

	//Call swap function on all integers
	swapint(one, two);
	swapint(one, three);
	swapint(one, four);
	swapint(two, three);
	swapint(two, four);
	swapint(three, four);

	//Print out the numbers in order
	cout << "Here are the numbers in order:" << endl;
	cout << one << " " << two << " " << three << " " << four << endl;

	return 0;
}

//Pass the actual values, not copies
void swapint(int &x, int &y)
{
	//Compare the values of the two numbers passed
	if(x > y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
}