/*
* COMP11
* HW6
* Jeremy Kanovsky
* Signed off by Steven Song
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int max_board_size = 10;

class board {
	public:
		//Constructors and destructors
		board();
		board(int rows, int columns);
		~board();

		//Function to initialize board
		void prompt_for_size();

		//Move functions
		void up();
		void down();
		void left();
		void right();

		//Check for win or loss
		bool check_loss();
		bool check_win();

		//Returns the row and column (for debugging later)
		int[] get_row(int row);
		int[] get_column(int column);

	private:
		//Function to create and place a random tile
		void rand_tile();

		//Variables for the game board, and the
		//number of rows and columns
		int game_board[][];
		int num_rows;
		int num_columns;
};