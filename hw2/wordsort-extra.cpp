/*
* COMP11
* Homework 2
* Problem 4 - Extra Credit
* Jeremy Kanovsky
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	cout << "How many words do you want to sort?" << endl;
	int num;
	cin >> num;
	cout << "Please enter the words." << endl;
	vector<string> words;
	for(int x = 0; x<num; x++) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}
	sort(words.begin(), words.end());
	cout << "\nThe sorted list is:" << endl; 
	for(int x = 0; x<num; x++) {
		cout << words.at(x) << endl;
	}
}
