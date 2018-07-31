/*
* COMP 11
* Homework 7
* Jeremy Kanovsky
*/

//Include Statements
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include"score.h"
#include"board.h"
using namespace std;

//Function Headers
void starting_text();
bool ask_to_continue();
void play_turn(board &, score &, bool &);
void help_menu();

int main()
{
	//Game start
	bool keep_playing = true;
	starting_text();

	//Runs the game over again
	while(keep_playing)
	{

		//Creates board and score objects and game state variable
		board b;
		score s;
		b.rand_tile();
		b.rand_tile();
		bool game_lost = false;

		//Has the user play a turn
		while(!game_lost)
		{
			//Prints the board and has the player make a move
			b.print_board();
			play_turn(b, s, game_lost);
			s.set_score(b.get_score());
			if(game_lost == true)
			{
				break;
			}
			b.rand_tile();
			game_lost = b.check_loss();
		}

		//Once game is over this portion activates
		cout << "Your largest tile was " << b.max_tile() << endl;
		cout << "Your score was " << b.get_score() << endl;

		//Sets the final score, gets the users name, records and shows scores
		s.set_score(b.get_score());
		s.get_user_name();
		s.add_score();
		s.print_high_scores();

		//Deletes board
		b.~board();

		//Asks if the user wants to continue
		keep_playing = ask_to_continue();
	}
	return 0;
}

void starting_text()
{
	//Shows controls for the game
	system("clear");
	cout << "Welcome to 2048!" << endl;
	cout << endl;
	cout << "The controls are as follows:" << endl;
	cout << "	[w] to go up" << endl;
	cout << "	[a] to go left" << endl;
	cout << "	[s] to go down" << endl;
	cout << "	[d] to go right" << endl;
	cout << "	[q] to quit the game" << endl;
	cout << "	[h] to view high scores" << endl;
}

bool ask_to_continue()
{
	//Asks if the user wants to keep playing
	string keep_playing = "";
	while(keep_playing != "Y" && keep_playing != "N")
	{
		cout << "Do you wish to play another game? (Y/N)" << endl;
		cin >> keep_playing;
		if(keep_playing == "Y")
			return true;
		else
			return false;
	}
	return false;
}

void play_turn(board &b, score &s, bool &game_lost)
{
	//Gets user input and makes move accordingly
	string input;
	cin >> input;
	if(input == "w")
	{
		b.up();
	}
	else if(input == "a")
	{
		b.left();
	}
	else if(input == "s")
	{
		b.down();
	}
	else if(input == "d")
	{
		b.right();
	}

	//Ends the game
	else if(input == "q")
	{
		game_lost = true;
	}

	//Activates high score class
	else if(input == "h")
	{
		s.get_high_scores();
		s.print_high_scores();
		string hide_high_scores;
		cout << "Press any key to continue." << endl;
		cin >> hide_high_scores;
	}
}