/*
* COMP11
* Homework 4
* Problem 3
* Jeremy Kanovsky
*/

//Inport libraries
#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<math.h>
using namespace std;

//Define prototypes
void user_turn(int &, int &, bool &);
void stake_attack(int &, int &, bool &);
bool stake_check(int , int);
void buffy_stake(int &, int &, bool &);
void willow_stake(int &, bool &);
void xander_stake(int &, int &, bool &);
void spell_attack(int &, int &, bool &);
void buffy_spell(int &, int &, bool &);
void willow_spell(int &, bool &);
void xander_spell(int &, bool &);
void run_away(int &, bool &);
void buffy_died(bool &);
void status_print(int, int, bool);

int main()
{
	//Define and initialize variables (and an srand function)
	srand(time(NULL));
	int num_vampires = 3;
	int num_stakes = 10;
	bool buffy_dead = false;

	//Give information to the user
	cout << endl;
	cout << "You encounter 3 vampires in a graveyard. Kill them!" 
	<< endl;
	cout << "You have 10 stakes to use, kill the vampires "
	<< "without Buffy dying." << endl;

	//Has the user play a turn infinitely until the game is over
	while((num_vampires != 0) && (buffy_dead == false) 
		&& (num_stakes != 0))
	{
		user_turn(num_vampires, num_stakes, buffy_dead);
		status_print(num_vampires, num_stakes, buffy_dead);
	}
	return 0;
}

void user_turn(int &num_vampires, int &num_stakes, bool &buffy_dead)
{
	//Ask for and check user input values
	int user_input = 3;
	while((user_input != 0) && (user_input != 1) && (user_input != 2))
	{
		cout << "Enter 0 to attack with a stake, 1 to cast a spell, or "
		<< "2 to run away." << endl;
		cin >> user_input;
	}

	//Call the correct move based on user input
	if(user_input == 0)
	{
		stake_attack(num_vampires, num_stakes, buffy_dead);
	}
	else if(user_input == 1)
	{
		spell_attack(num_vampires, num_stakes, buffy_dead);
	}
	else if(user_input == 2)
	{
		run_away(num_stakes, buffy_dead);
	}
}

void stake_attack(int &num_vampires, int &num_stakes, bool &buffy_dead)
{
	//Ask for and check user input values
	cout << "Who should use a stake attack?" << endl;
	int user_input = 4;
	while((user_input != 0) && (user_input != 1) && (user_input != 2))
	{
		cout << "Enter 0 for Buffy, 1 for Willow, or 2 for Xander." 
		<< endl;
		cin >> user_input;
	}

	//Call the correct move based on user input
	if(user_input == 0)
	{
		buffy_stake(num_vampires, num_stakes, buffy_dead);
	}
	else if(user_input == 1)
	{
		willow_stake(num_vampires, buffy_dead);
	}
	else if(user_input == 2)
	{
		xander_stake(num_vampires, num_stakes, buffy_dead);
	}
}

void buffy_stake(int &num_vampires, int &num_stakes, bool &buffy_dead)
{
	//Check the number of stakes and determines if the vampire is 
	//killed or Buffy dies
	if(stake_check(num_stakes, 3))
	{}
	else
	{
		if((rand()%10 + 1) <= 8)
		{
			num_vampires--;
			cout << "Vampire killed!" << endl;
		}
		if((rand()%10 + 1) <= 2)
		{
			buffy_died(buffy_dead);
		}
		num_stakes = num_stakes-3;
	}
}

void willow_stake(int &num_vampires, bool &buffy_dead)
{
	//Determines if the vampire dies or if buffy is killed
	if((rand()%10 + 1) <= 6)
	{
		num_vampires--;
		cout << "Vampire killed!" << endl;
	}
	if((rand()%10 + 1) <= 2)
	{
		buffy_died(buffy_dead);
	}
}


void xander_stake(int &num_vampires, int &num_stakes, bool &buffy_dead)
{
	//Check the number of stakes and determines if the vampire is 
	//killed or Buffy dies
	if(stake_check(num_stakes, 1))
	{}
	else
	{
		if((rand()%10 + 1) <= 3)
		{
			num_vampires--;
			cout << "Vampire killed!" << endl;
		}
		if((rand()%10 + 1) <= 1)
		{
			buffy_died(buffy_dead);
		}
		num_stakes = num_stakes-1;
	}
}

bool stake_check(int num_stakes, int stakes_needed)
{
	//Checks if the user has enough stakes to perform the move
	if(num_stakes >= stakes_needed)
	{
		return false;
	}
	else
	{
		cout << "You don't have enough stakes to use this attack. "
		<< "Start your turn over!" << endl;
		return true;
	}
}

void spell_attack(int &num_vampires, int &num_stakes, bool &buffy_dead)
{
	//Asks for user input and verifys correct input values
	cout << "Who should use a spell attack?" << endl;
	int user_input = 4;
	while((user_input != 0) && (user_input != 1) && (user_input != 2))
	{
		cout << "Enter 0 for Buffy, 1 for Willow, or 2 for Xander." 
		<< endl;
		cin >> user_input;
	}

	//Calls the correct spell function based on the user input
	if(user_input == 0)
	{
		buffy_spell(num_vampires, num_stakes, buffy_dead);
	}
	else if(user_input == 1)
	{
		willow_spell(num_vampires, buffy_dead);
	}
	else if(user_input == 2)
	{
		xander_spell(num_vampires, buffy_dead);
	}
} 

void buffy_spell(int &num_vampires, int &num_stakes, bool &buffy_dead)
{
	//Checks if the user has enough stakes and if the vampire is 
	//killed or if Buffy died
	if(stake_check(num_stakes, 1))
	{}
	else
	{
		if((rand()%10 + 1) <= 2)
		{
			num_vampires--;
			cout << "Vampire killed!" << endl;
		}
		if((rand()%10 + 1) <= 3)
		{
			buffy_died(buffy_dead);
		}
		num_stakes = num_stakes-1;
	}
}

void willow_spell(int &num_vampires, bool &buffy_dead)
{
	//Determines if the vampire is killed or if Buffy dies
	if((rand()%10 + 1) <= 7)
		{
			num_vampires--;
			cout << "Vampire killed!" << endl;
		}
		if((rand()%10 + 1) <= 4)
		{
			buffy_died(buffy_dead);
		}
}

void xander_spell(int &num_vampires, bool &buffy_dead)
{
	//Determines if the vampire is killed or if Buffy dies
	if((rand()%10 + 1) <= 1)
		{
			num_vampires--;
			cout << "Vampire killed!" << endl;
		}
		if((rand()%10 + 1) <= 2)
		{
			buffy_died(buffy_dead);
		}
}

void run_away(int &num_stakes, bool &buffy_dead)
{
	//Determines if Buffy dies, and adds a stake
	if((rand()%10 +1) <= 1)
	{
		buffy_died(buffy_dead);
	}
	num_stakes++;
	cout << "OK, everyone runs!" << endl;
}

void buffy_died(bool &buffy_dead)
{
	//Kills Buffy
	buffy_dead = true;
}

void status_print(int num_vampires, int num_stakes, bool buffy_dead)
{
	//Prints out the states of each variable and determines if the user 
	//has lost the game or won the game.
	cout << endl;
	cout << "There are " << num_vampires << " vampires left." << endl;
	cout << "There are " << num_stakes << " stakes left." << endl;
	if(buffy_dead == false)
	{
		cout << "And Buffy is alive." << endl;
	}
	else
	{
		cout << "And Buffy is dead." << endl;
		cout << endl;
		cout << "Buffy has died! You have lost the battle!" << endl;
	}
	if((num_stakes == 0) && (num_vampires != 0))
	{
		cout << "You have ran out of stakes! You have lost the battle!" 
		<< endl;
	}
	cout << endl;
	if((num_vampires == 0) && (buffy_dead == false))
	{
		cout << "Congratulations! You have defeated the vampires and "
		<< "saved the day!" << endl;
		cout << endl;
	}
}