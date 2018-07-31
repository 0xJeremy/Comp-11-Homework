/*
* COMP11
* HW6
* Jeremy Kanovsky
* Signed off by Steven Song
*/

#include<iostream>
#include<string>
#include<fstream>
#include"board.h"
using namespace std;

const int win_tile = 2048;

class game {
	public:
		//Constructors and destructors
		game();
		~game();

		//Function to print the board
		void print_board();

		//Functions to return score and if the game is won
		int get_score();
		bool game_won();

	private:
		//Board object is made private
		board curr_board[int rows, int columns];

		//Variable used to keep track of game score
		int score;
};