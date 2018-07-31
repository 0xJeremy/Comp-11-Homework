/*
* COMP 11
* Homework 7
* Jeremy Kanovsky
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#ifndef BOARD_H_
#define BOARD_H_

//const int max_board_size = 10;

class board {
	public:
		//Constructors and destructors
		board();
		~board();

		//Move functions
		void up();
		void move_up();
		void update_up();

		void down();
		void move_down();
		void update_down();

		void left();
		void move_left();
		void update_left();

		void right();
		void move_right();
		void update_right();

		//Check for win or loss
		bool check_loss();

		//Returns the largest tile
		int max_tile();

		//Function to print the board
		void print_board();

		//Function to create and place a random tile
		void rand_tile();

		//Returns the score of the game
		int get_score();

	private:
		//Private variables to create and initialize the
		//game board and score and determine if the game
		//has been lost
		int **game_board;
		int board_size;
		int game_lost;
		int score;
};

#endif