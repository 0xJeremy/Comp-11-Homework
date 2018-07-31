/*
* COMP 11
* Homework 7
* Jeremy Kanovsky
*/

//Include statements
#include<iostream>
#include<string>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include"board.h"
using namespace std;

//Board constructor
board::board()
{
	//Assigns a dynamically allocated array for the board
	game_board = NULL;
	board_size = 0;
	score = 0;

	//Lets the user choose a board size
 	while(board_size > 10 || board_size < 4)
	{
		cout << "How large would you like the board to be?" << endl;
		cout << "Please enter a number between 4 and 10)" << endl;
		cin >> board_size;
		if(board_size > 10 || board_size < 4)
		{
			cout << "Please choose a different board size (between 4 and 10)" << endl;
		}
	}

	//Initalizes a new board
	game_board = new int *[board_size];
	for(int i = 0; i < board_size; i++)
	{
		game_board[i] = new int[board_size];
	}
	for(int j = 0; j < board_size; j++)
	{
		for(int k = 0; k < board_size; k++)
		{
			game_board[j][k] = 0;
		}
	}
}

//Board destructor
board::~board()
{
	for(int i = 0; i < board_size; ++i)
	{
		delete [] game_board[i];
	}
	delete []game_board;
}

//Generates a random tile in an empty location
void board::rand_tile()
{
	srand(time(NULL));
	int x = rand() % 10;
	if(x == 0)
	{
		bool flag = true;
		while(flag)
		{
			int rand_row = rand() % board_size;
			int rand_column = rand() % board_size;
			if(game_board[rand_row][rand_column] == 0)
			{
				game_board[rand_row][rand_column] = 4;
				flag = false;
			}
		}
	}
	else
	{
		bool flag = true;
		while(flag)
		{
			int rand_row = rand() % board_size;
			int rand_column = rand() % board_size;
			if(game_board[rand_row][rand_column] == 0)
			{
				game_board[rand_row][rand_column] = 2;
				flag = false;
			}
		}
	}
}

//Moves the board up
void board::up()
{
	move_up();
	update_up();
	move_up();
}

//Moves tiles up
void board::move_up()
{
	for(int i = 0; i < board_size; i++)
	{
		for(int j = 0; j < board_size; j++)
		{
			if(game_board[j][i] == 0)
			{
				for(int k = j+1; k < board_size; k++)
				{
					if(game_board[k][i] != 0)
					{
						game_board[j][i] = game_board[k][i];
						game_board[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

//Consolidates tiles up
void board::update_up()
{
	game_lost = 1;
	for(int i = 0; i < board_size; i++)
	{
		for(int j = 0; j < board_size-1; j++)
		{
			if(game_board[j][i] && game_board[j][i] == game_board[j+1][i])
			{
				game_board[j][i] = game_board[j][i]+game_board[j+1][i];
				game_board[j+1][i] = 0;
				game_lost = 0;
				score = score + game_board[j][i];
			}
		}
	}
}

//Moves the board down
void board::down()
{
	move_down();
	update_down();
	move_down();
}

//Moves the tiles down
void board::move_down()
{
	for(int i = 0; i < board_size; i++)
	{
		for(int j = board_size-1; j >= 0; j--)
		{
			if(game_board[j][i] == 0)
			{
				for(int k = j-1; k >= 0; k--)
				{
					if(game_board[k][i] != 0)
					{
						game_board[j][i] = game_board[k][i];
						game_board[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

//Consolidates the tiles down
void board::update_down()
{
	game_lost = 1;
	for(int i = 0; i < board_size; i++)
	{
		for(int j = board_size-1; j > 0; j--)
		{
			if(game_board[j][i] && game_board[j][i] == game_board[j-1][i])
			{
				game_board[j][i] = game_board[j][i] + game_board[j-1][i];
				game_board[j-1][i] = 0;
				game_lost = 0;
				score = score + game_board[j][i];
			}
		}
	}
}

//Moves the board left
void board::left()
{
	move_left();
	update_left();
	move_left();
}

//Moves the tiles left
void board::move_left()
{
	for(int i = 0; i < board_size; i++)
	{
		for(int j = 0; j < board_size; j++)
		{
			if(game_board[j][i] == 0)
			{
				for(int k = j+1; k < board_size; k++)
				{
					if(game_board[i][k] != 0)
					{
						game_board[i][j] = game_board[i][k];
						game_board[i][k] = 0;
						break;
					}
				}
			}
		}
	}	
}

//Consolidates the tiles left
void board::update_left()
{
	game_lost = 1;
	for(int i = 0; i < board_size; i++)
	{
		for(int j = 0; j < board_size-1; j++)
		{
			if(game_board[i][j] && game_board[i][j] == game_board[i][j+1])
			{
				game_board[i][j] = game_board[i][j] + game_board[i][j+1];
				game_board[i][j+1] = 0;
				game_lost = 0;
				score = score + game_board[i][j];
			}
		}
	}
}

//Moves the board right
void board::right()
{
	move_right();
	update_right();
	move_right();
}

//Moves the tiles right
void board::move_right()
{
	for(int i = 0; i < board_size; i++)
	{
		for(int j = board_size-1; j >= 0; j--)
		{
			if(game_board[i][j] == 0)
			{
				for(int k = j-1; k >= 0; k--)
				{
					if(game_board[i][k] != 0)
					{
						game_board[i][j] = game_board[i][k];
						game_board[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

//Consolidates the tiles right
void board::update_right()
{
	game_lost = 1;
	for(int i = 0; i < board_size; i++)
	{
		for(int j = board_size-1; j > 0; j--)
		{
			if(game_board[i][j] && game_board[i][j] == game_board[i][j-1])
			{
				game_board[i][j] = game_board[i][j]+game_board[i][j-1];
				game_board[i][j-1] = 0;
				game_lost = 0;
				score = score + game_board[i][j];
			}
		}
	}
}

//Checks if the user has lost the game
bool board::check_loss()
{
	bool check_full = true;
	for(int i = 0; i < board_size; i++)
	{
		for(int j = 0; j < board_size; j++)
		{
			if(game_board[i][j] == 0)
			{
				check_full = false;
			}
		}
	}
	if((game_lost == 1) && check_full)
	{
		cout << "Sorry! You have lost the game 2048!" << endl;
		cout << "Better luck next time!" << endl;
		return true;
	}
	return false;
}

//Loops through all values to find the largest tile
int board::max_tile()
{
	int max_tile = 0;
	for(int i = 0; i < board_size; i++)
	{
		for(int j = 0; j < board_size; j++)
		{
			if(game_board[i][j] > max_tile)
			{
				max_tile = game_board[i][j];
			}
		}
	}
	return max_tile;
}

//Displays the board and controls
void board::print_board()
{
	system("clear");
	cout << "The controls are as follows:" << endl;
	cout << "	[w] to go up" << endl;
	cout << "	[a] to go left" << endl;
	cout << "	[s] to go down" << endl;
	cout << "	[d] to go right" << endl;
	cout << "	[q] to quit the game" << endl;
	cout << "	[h] to view high scores" << endl;
	cout << endl;
	cout << "Score: " << score << endl;
	for(int i = 0; i < board_size; i++)
	{
		for(int j = 0; j < board_size; j++)
		{
			if(game_board[i][j] == 0)
				cout << "X";
			else
				cout << game_board[i][j];
			cout << "    ";
		}
		cout << endl;
		cout << endl;
	}
}

//Returns the players score (for the score class)
int board::get_score()
{
	return score;
}