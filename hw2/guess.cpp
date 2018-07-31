/*
* COMP11
* Homework 2
* Problem 1
* Jeremy Kanovsky
*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	srand(time(NULL));
	int random = rand() % 30 + 5;
	cout << "Try to guess the random number between 5 and 35." << endl;
	int user_guess = 0;
	while (user_guess != random)
	{
		cin >> user_guess;
		if(user_guess > random) {
			cout << "That number is too large. Try again." << endl;
		}
		else if(user_guess < random) {
			cout << "That number is too small. Try again." << endl;	
		}
		else {
			cout << "You got it right! The random number was: " << random << "." << endl;
		}
	}
}
