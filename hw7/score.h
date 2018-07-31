/*
* COMP 11
* Homework 7
* Jeremy Kanovsky
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#ifndef SCORE_H_
#define SCORE_H_

class score {
	public:
		//Constructors
		score();

		//Uses File IO for previous top scores
		void get_high_scores();

		//Prints the high scores
		void print_high_scores();

		//Get the users name
		void get_user_name();

		//Sets current score
		void set_score(int);

		//Adds new score to High Score file
		void add_score();

		//Prints all the scores in the High Score File
		void print_all_scores();

	private:
		//Score variable
		int game_score;

		//User name
		string user_name;

		//High Scores
		string high_scores[10];
};

#endif