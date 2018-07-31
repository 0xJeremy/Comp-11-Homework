/*
* COMP11
* Homework 1
* Problem 3
* Jeremy Kanovsky
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "What do they call you?" << endl;
	string name;
	int points = 0;
	cin >> name;

	//Labyrinth setup
	cout << "Welcome to the Labyrinth, " << name << "." << endl;
	cout << "Please answer questions with Y for yes and N for no." << endl;
	cout << "Toby is crying his head off." << endl;

	//Choice one
	cout << endl;
	cout << "Do you wish the Goblin Kind would take him away right now?" << endl;
	string choice_one;
	cin >> choice_one;

	//Start of actual labyrinth
	if(choice_one == "N") 
	{
		cout << "Labyrinth over. You earned 0 points." << endl;
		cout << "You are kind of a coward. Your punishment is to take care of Toby, who will be a baby forever." << endl;
	}
	if(choice_one == "Y")
	{
		cout << "OK, he did! You have 13 hours to solve the labyrinth." << endl;
		cout << "Do you want to follow the talking worm?" << endl;
		points++;

		//Choice two
		string choice_two;
		cin >> choice_two;

		//Start of Choice two
		if(choice_two == "N")
		{
			cout << "Labyrinth over. You earned " << points << " points." << endl;
		}
		if(choice_two == "Y")
		{
			cout << "With the worm's help, you find Hoggle, then Ludo!" << endl;
			cout << endl;
			cout << "Do you want to confront the Goblin King alone?" << endl;
			points += 2;

			//Choice three
			string choice_three;
			cin >> choice_three;

			//Start of choice three
			if(choice_three == "N")
			{
				cout << "Labyrinth over. You earned " << points << " points." << endl;
			}
			if(choice_three == "Y")
			{
				cout << "Good choice. He has no power over you, " << name << "!" << endl;
				cout << endl;
				points += 3;
				cout << "Labyrinth over. You earned " << points << " points" << endl;
				cout << "You did perfectly! You get to go home and Ludo will be your best bud." << endl;
			}
		}
	}
	
	//Labyrinth over, readout if points are 1-5
	if(points > 0 && points < 6)
	{
		cout << "You're OK and will stay in the labyrinth with David Bowie." << endl;
	}
}
