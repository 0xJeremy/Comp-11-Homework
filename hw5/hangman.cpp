/*
* COMP11
* Homework 5
* Problem 1
* Jeremy Kanovsky
*/

//Include Libraries
#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<fstream>
#include "print.h"
using namespace std;

//Declare prototypes
string random_words();
void game_initialize(string, int &);
char user_guess();
void guess(string*, string, int &);
bool continue_playing();
bool check_win(string*, string, int &);
void lose_game(string, int);

int main()
{
	//Initialize for a random number function later
	srand(time(NULL));

	//Declare and initalize variables
	bool flag = true;
	string words[5];
	int counter = 0;
	int win_counter = 0;

	//Loop to keep the game playing while the user wants to
	while(flag)
	{
		//Gets five words from the dictionary. Repeats every 5 games
		if((counter%5) == 0)
		{
			for(int i = 0; i < 5; i++)
			{
				words[i] = random_words();
			}
		}

		//Starts game
		game_initialize(words[counter%5], win_counter);

		//Counts how many games have been played
		counter++;

		//Checks if the user wants to keep playing
		flag = continue_playing();
	}

	return 0;
}


//Gets 5 random words from the dictionary
string random_words()
{

	//Opens the dictionary and checks to make sure it opened
	ifstream infile;
	infile.open("dictionary.txt");
	if(!infile.is_open())
	{
		cout << "Unable to open the file." << endl;
	}

	//Gives a random position within the dictionary file
	int position = rand()%19912;
	string randLine = "";
	string line;
	int linecount = 0;

	//Goes to the random line and gets the entry there
	for(int i = 0; getline(infile, line); i++)
	{
		linecount++;
		if(linecount == position)
		{
			//Closes the file and returns the entry
			randLine = line;
			infile.close();
			return randLine;
		}
	}

	//Closes file and returns the entry
	infile.close();
	return randLine;
}


//Starts the game
void game_initialize(string word, int &win_counter)
{

	//Gives output to the player
	cout << "The length of the word is " << word.length() << "." 
		<< endl;

	//Creates a new string of just spaces
	string *spots = new string[(word.length())];
	for(int i = 0; i < (int)word.length(); i++)
	{
		spots[i] = "_ ";
		cout << spots[i];
	} 
	cout << endl;

	//Lets the user begin guessing the word
	guess(spots, word, win_counter);
}

char user_guess()
{
	char guess;
	int guess_int = 0;
		while(!(guess_int > 96) || !(guess_int < 123))
		{
			cout << "Enter a letter to guess: ";
			cin >> guess;
			guess = tolower(guess);
			guess_int = (int)guess;
		}
	return guess;
}

void guess(string* spots, string word, int &win_counter)
{
	//Variables to keep track of wins and the number of guesses
	int num_guesses = 0;
	bool flag = false;
	bool win_game = false;

	//A loop to let the player keep entering letters
	while((num_guesses != 8) && (win_game == false))
	{

			//Calls a function to get user input
			char guess = user_guess();

			//Checks if the letter is in the word
			for(int q = 0; q < (int)word.length(); q++)
			{
				if(guess == word.at(q))
				{
					spots[q] = guess;
					flag = true;
				}
			}

			//Lets the user know if the letter is not in the word
			if(flag == false)
			{
				num_guesses++;
				print_body_parts(num_guesses);
				cout << "That letter is not in the word." 
					<< endl;
				cout << "You've guessed " << num_guesses 
					<< " letters incorrectly." << endl;
			}

			//Prints out the hangman picture
			else
			{
				print_body_parts(num_guesses);
			}
			flag = false;

			//Prints out the spaces with letters in them
			for(int j = 0; j < (int)word.length(); j++)
			{
				cout << spots[j];
			}
			cout << endl;

			//Checks if the user has won the game
			win_game = check_win(spots, word, win_counter);
	}

	//If the player lost, ends the game
	if(win_game == false)
	{
		lose_game(word, win_counter);
	}
}

//Function checks if the user wishes to continue playing
bool continue_playing()
{
	string continue_playing = "";
	while((continue_playing != "Y") && (continue_playing != "N"))
	{
		cout << "Do you want to continue playing? (Y/N)" << endl;
		cin >> continue_playing;
		if(continue_playing == "Y")
		{
			return true;
		}
		else if(continue_playing == "N")
		{
			return false;
		}
	}
	return true;
}


//Checks if the user has won the game
bool check_win(string* spots, string word, int &win_counter)
{
	bool check_win = true;

	//Determines if there are any blank spots left in the word
	for(int i = 0; i < (int)word.length(); i++)
	{
		if(spots[i] == "_ ")
		{
			check_win = false;
		}
	}

	//Prints out if the user won the game
	if(check_win == true)
	{
		win_counter++;
		cout << "Congratulations! The word was " << word 
			<< "!" << endl;
		cout << "You have won " << win_counter << " games!" 
			<< endl;
		cout << endl;
	}
	return check_win;
}

//Output for when the user has lost the game
void lose_game(string word, int win_counter)
{
	cout << "You lose. The word was " << word  << "." << endl;
	cout << "You have won " << win_counter << " games." << endl;
}