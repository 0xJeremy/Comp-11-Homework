/* COMP11
 * Fall 2017
 * HW3 (PIG game)
 * Starter Code
 * Jeremy Kanovsky
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Function prototype: check_for_win
int check_for_win(int, int);
// Function prototype: switch_turn
int switch_turn(int);
// Function prototype: announce_points
void announce_points(int, int);

// Number of points needed to win
const int THRESHOLD = 20;
// Players
const int PLAYER_ONE = 1;
const int PLAYER_TWO = 2;

int main () 
{
    // Seed the random variable
    srand(time(NULL));

    // Total number of points for each player.
    int pone_points = 0, ptwo_points = 0;

    // Whose turn it is. Player One always starts.
    int turn = PLAYER_ONE;

    // Is the game over yet
    bool game_over = false;

    // While loop for the game. A game comprises several rounds.
    while (!game_over)
    {
        // Announce whose turn it is
        cout << "Player " << turn << " is up!\n";

        // Round-specific variables
        bool round_over = false;
        int round_points = 0;

	/****************************************
	* YOUR CODE GOES HERE!             *
	 ****************************************/
	int roll;

	// Loop that runs while the round is going
	while(!round_over)
	{
		
		// Prints whose turn it is and asks for 
		// input choice to roll or not
		cout << "Player " << turn << 
			" : Enter 0 to roll or 1 to hold" << endl;
		char choice;
		cin >> choice;

		// If they choose to stand the turn is 
		// ended and the total points printed
		if(choice == '1')
		{
			round_over = true;
			cout << "Player " << turn << " got " << round_points 
				<< " this round" << endl;
		}

		// Else a number is rolled
		else
		{
			roll = rand() % 6 + 1;
			cout << "Player " << turn << " rolled a " 
				<< roll << endl;

			// If roll is 1 the turn is ended and 
			// no points earned
			if(roll == 1)
			{
				round_over = true;
				round_points = 0;
				cout << "Round over, no points!" << endl;
			}

			// Else the points are added to that turn
			else
			{
				round_points = round_points + roll;
			}

		}
	}

	// Add points for player 1 and 2 after turn
	if(turn == 1)
	{
		pone_points += round_points;
	}
	else
	{
		ptwo_points += round_points;
	}

	// Prints each players total points
	cout << "Player One total points: " <<
		pone_points << endl;
	cout << "Player Two total points: " << 
		ptwo_points << endl;

	// Switches turn and checks for win
	turn = switch_turn(turn);
	int win = check_for_win(pone_points, ptwo_points);

	if((win == 1) || (win == 2))
	{
		game_over = true;
	}
	

           
    } // end game while loop

    // Game is over. End the program.

    // Prints out who won the game
    if(pone_points >= THRESHOLD)
	{
		cout << "Player 1 wins with " << pone_points 
			<< "!" << endl;
	}
    else
	{
		cout << "Player 2 wins with " << ptwo_points 
			<< "!" << endl;
	}

    cout << "Thanks for playing!\n";
    return 0;
}






/****************************************
 * NO NEED TO MODIFY CODE BELOW THIS POINT    *
 ****************************************/

// FUNCTION DEFINITION
// Function check_for_win
// Arguments:
//  Player 1 and 2's points (ints)
// Returns:
//  0 is game is not over
//  1 if player one won
//  2 if player two won
// Does:
//  Compares each score to the threshold
int check_for_win(int pone_points, int ptwo_points)
{
    // Check the players' current points against the threshold
    if (pone_points >= THRESHOLD) 
    {           
        return PLAYER_ONE;
    }
    else if (ptwo_points >= THRESHOLD)
    {
        return PLAYER_TWO;
    }   
    
    // If we didn't meet either condition,
    // then nobody won
    return 0;
}

// FUNCTION DEFINITION
// Function switch_turn
// Arguments:
//  1. whose turn it is (int)
// Returns:
//  # of updated turn
// Does:
//  Switches whose turn it is
int switch_turn(int turn)
{
    if (turn == PLAYER_ONE)
    {
        return PLAYER_TWO;
    }
    else {
        return PLAYER_ONE;
    }

}

// FUNCTION DEFINITION
// Function announce_points
/// Arguments:
//      1. Player one's points (int)
//      2. Player two's points (int)
// Returns:
//      void
// Does:
//      Announces both players total points
void announce_points(int pone, int ptwo)
{
    cout << "Player One total points: " << pone << endl;
    cout << "Player Two total points: " << ptwo << endl;
}
