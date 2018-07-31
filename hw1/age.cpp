/*
* COMP11
* Homework 1
* Problem 2
* Jeremy Kanovsky
*
* Test input: 42
* Expected output: 504 months old, 15330 days old, 367920 hours old
*
* Test input: 144
* Expected output: 1728 months old, 52560 days old, 1261440 hours old
*
* Test input: 256
* Expected output: 3072 months old, 93440 days old, 2242560 hours old
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int MONTHS_PER_YEAR = 12;
	const int DAYS_PER_YEAR = 365;
	const int HOURS_PER_DAY = 24;

	cout << "How old are you in years?" << endl;
	int age;
	cin >> age;

	int months_old = age*MONTHS_PER_YEAR;
	int days_old = age*DAYS_PER_YEAR;
	int hours_old = days_old*HOURS_PER_DAY;

	cout << "You are: " << months_old << " months old, " << days_old << " days old, " << hours_old << " hours." << endl;
}
