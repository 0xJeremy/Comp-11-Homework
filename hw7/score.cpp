/*
* COMP 11
* Homework 7
* Jeremy Kanovsky
*/

//Include statements
#include<iostream>
#include<string>
#include<fstream>
#include"score.h"
using namespace std;

//Score constructor
score::score()
{
	game_score = 0;
	user_name = "";
}

//Gets the top 5 highest scores in the score file
void score::get_high_scores()
{
	ifstream infile;
	infile.open("2048_high_scores.txt");
	if(!infile.is_open())
	{
		cout << "High score file failed to open." << endl;
	}
	for(int i = 0; i < 10; i++)
	{
		string high_score;
		infile >> high_score;
		high_scores[i] = high_score;
	}
	infile.close();
}

//Prints the high scores once get_high_scores() has been called
void score::print_high_scores()
{
	cout << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << high_scores[i];
		cout << " ";
		if(i % 2 == 1)
		{
			cout << endl;
		}
	}
	cout << endl;
}

//Asks for the users name and saves it
void score::get_user_name()
{
	cout << "What is your name? (This input will be used for the high score file)" << endl;
	cin >> user_name;
}

//Sets the current game_score variable
void score::set_score(int curr_score)
{
	game_score = curr_score;
}

//Adds a new entry to the high score file
void score::add_score()
{
	ifstream infile;
	infile.open("2048_high_scores.txt");
	if(!infile.is_open())
	{
		cout << "High score file did not open correctly." << endl;
	}
	string all_scores[100];
	string temp;
	int count = 0;
	while(!infile.eof())
	{
		infile >> temp;
		if(temp != "-1")
		{
			all_scores[count++] = temp;
		}
	}
	infile.close();
	ofstream outfile;
	outfile.open("2048_high_scores.txt");
	for(int i = 0; i < count; i++)
	{
		if(i % 2 == 0)
		{
			outfile << all_scores[i] << " ";
		}
		else
		{
			outfile << all_scores[i] << endl;
		}
	}
	outfile << user_name << " " << game_score << endl;
	outfile << -1;
	outfile.close();
}

//Prints all the scores in the high score file (used for debugging)
void score::print_all_scores()
{
	cout << endl;
	cout << "HIGH SCORES:" << endl;
	cout << endl;
	ifstream infile;
	infile.open("2048_high_scores.txt");
	if(!infile.is_open())
	{
		cout << "High score file did not open correctly." << endl;
	}
	string temp = "";
	int count = 0;
	while(temp != "-1")
	{
		infile >> temp;
		if(temp != "-1")
		{
			cout << temp << " ";
			if(count % 2 == 1)
			{
				cout << endl;
			}
		}
		count++;
	}
	infile.close();
	cout << endl;
}