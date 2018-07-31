/*
* COMP11
* Homework 2
* Problem 2
* Jeremy Kanovsky
*
* Input: zebra, yammer, xanadu
* Output: xanadu, yammer, zebra
*
* Input: apple, citrus, banana
* Output: apple, banana, citrus
*
* Input: cake, jake, make
* Output: cake, jake, make
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
	cout << "Please enter 3 words." << endl;
	string input1;
	string input2;
	string input3;
	cin >> input1;
	cin >> input2;
	while(input2 == input1) {
		cout << "Those are the same word. Please enter a different one." << endl;
		cin >> input2;
	}
	cin >> input3;
	while((input3 == input1) || (input3 == input2)) {
		cout << "Those are the same word. Please enter a different one." << endl;
		cin >> input3;
	}
	cout << "\n\nIn order the words are:" << endl;
	if(input1 < input2){
		if(input2 < input3) {
			cout << input1 << " " << input2 << " " << input3 << endl;
		}
		else if(input1 < input3) {
			cout << input1 << " " << input3 << " " << input2 << endl;
		}
		else {
			cout << input3 << " " << input1 << " " << input2 << endl;
		}
	}
	else {
		if(input2 < input3) {
			if(input1 < input3) {
				cout << input2 << " " << input1 << " " << input3 << endl;
			}
			else {
				cout << input2 << " " << input3 << " " << input1 << endl;
			}
		}
		else {
			cout << input3 << " " << input2 << " " << input1 << endl;
		}
	}	
}
