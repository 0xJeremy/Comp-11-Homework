/*
* COMP11
* Homework 2
* Problem 3
* Jeremy Kanovsky
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	const char MASTER_PEG_0 = 'b';
	const char MASTER_PEG_1 = 'o';
	const char MASTER_PEG_2 = 'y';
	const char MASTER_PEG_3 = 'r';

	cout << "Welcome to MASTERMIND!" << endl;
	cout << "The computer has chosen a secret code of four pegs, using the colors red, orange, yellow, green, blue, and violet." << endl;
	cout << "It may have used repeats." << endl;
	cout << "Enter your guesses using r, o, y, g, b, or v." << endl;
	char peg0 = ' ';
	char peg1 = ' ';
	char peg2 = ' ';
	char peg3 = ' ';

	int wpegs = 0;
	int bpegs=0;

	while(!((peg0 == MASTER_PEG_0) && (peg1 == MASTER_PEG_1) && (peg2 == MASTER_PEG_2) && (peg3 == MASTER_PEG_3))) {

		cout << "Please enter Peg 1: ";
		cin >> peg0;
		while((peg0 != 'r') && (peg0 != 'o') && (peg0 != 'y') && (peg0 != 'g') && (peg0 != 'b') && (peg0 != 'v')) {
			cout << "Please enter a valid peg color." << endl;
			cin >> peg0;
		}

		cout << "Please enter Peg 2: ";
		cin >> peg1;
		while((peg1 != 'r') && (peg1 != 'o') && (peg1 != 'y') && (peg1 != 'g') && (peg1 != 'b') && (peg1 != 'v')) {
			cout << "Please enter a valid peg color." << endl;
			cin >> peg1;
		}

		cout << "Please enter Peg 3: ";
		cin >> peg2;
		while((peg2 != 'r') && (peg2 != 'o') && (peg2 != 'y') && (peg2 != 'g') && (peg2 != 'b') && (peg2 != 'v')) {
			cout << "Please enter a valid peg color." << endl;
			cin >> peg2;
		}

		cout << "Please enter Peg 4: ";
		cin >> peg3;
		while((peg3 != 'r') && (peg3 != 'o') && (peg3 != 'y') && (peg3 != 'g') && (peg3 != 'b') && (peg3 != 'v')) {
			cout << "Please enter a valid peg color." << endl;
			cin >> peg3;
		}
		bpegs = 0;
		wpegs = 0;

		if(peg0 == MASTER_PEG_0) {
			bpegs++;
		}
		if(peg1 == MASTER_PEG_1) {
			bpegs++;
		}
		if(peg2 == MASTER_PEG_2) {
			bpegs++;
		}
		if(peg3 == MASTER_PEG_3) {
			bpegs++;
		}

		if((peg0 == MASTER_PEG_1) || (peg0 == MASTER_PEG_2) || (peg0 == MASTER_PEG_3)) {
			wpegs++;
		}
		if(((peg1 == MASTER_PEG_0) || (peg1 == MASTER_PEG_2) || (peg1 == MASTER_PEG_3)) && !(peg0 == peg1)) {
			wpegs++;
		}
		if(((peg2 == MASTER_PEG_0) || (peg2 == MASTER_PEG_1) || (peg2 == MASTER_PEG_3)) && !((peg0 == peg2) || (peg1 == peg2))) {
			wpegs++;
		}
		if(((peg3 == MASTER_PEG_0) || (peg3 == MASTER_PEG_1) || (peg3 == MASTER_PEG_2)) && !((peg3 == peg0) || (peg3 == peg1) || (peg3 == peg2))) {
			wpegs++;
		}
		if(bpegs == 4) {
			cout << "Congratulations! You have won MasterMind!" << endl;
			break;
		}

		cout << "You have " << bpegs << " black pegs and " << wpegs << " white pegs." << endl;
		cout << "Do you want to keep playing? (y/n)" << endl;
		char keep_playing;
		cin >> keep_playing;
		if(keep_playing == 'n')
			break;
	}	
}
