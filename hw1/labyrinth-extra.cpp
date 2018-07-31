/*
* COMP11
* Homework 1
* Problem 3
* Jeremy Kanovsky
*/

#include<iostream>
#include<string>
using namespace std;

int main() 
{
	cout << "What do they call you?" << endl;
	string name;
	int points = 0;
	cin >> name;
	cout << "Welcome to the Labrinth, " << name << ".";
	cout << "Please answer questions with '1', '2', or '3' depending on the options given." << endl;
	cout << endl;
	cout << "You are in a dark passage. There are three forks ahaead of you. Passage 1 has heat eminating from it. Passage 2 is dark, cold, and a little slimy. Passage 3 has no floor." << endl;
	cout << "Do you choose passage 1, 2, or 3?" << endl;
	int choice_one;
	cin >> choice_one;
	if(cin.fail() || (choice_one > 3 || choice_one < 1)) {
		cout << "You lose. Game Over." << endl;
	}
	if(choice_one == 1)
	{
		cout << "You walk down passage 1. As you walk you find yourself growing sweaty and tired." << endl;
		cout << "You continue to walk until you come across a small man sleeping on the floor." << endl;
		cout << "Do you (1) choose to attack the man, (2) ignore the man, or (3) wake him and ask for help?" << endl;
		int choice_two;
		points++;
		cin >> choice_two;
		if(cin.fail() || (choice_two > 3 || choice_two < 1))
			cout << "You lose. Game Over." << endl;
		if(choice_two == 1)
		{
			cout << "The man wakes before you have a chance to attack and stabs you with a knife he kept conceled beneath him. You lose. Game Over." << endl;
		}
		if(choice_two == 2)
		{
			cout << "You step gingerly over the man. He does not wake up. As you reach the end of the hallway you a large beast confronts you." << endl;
			cout << name << "! You have trespassed within this Labyrinth for far too long. Fight me or lose your brother, Toby!" << endl;
			cout << "What do you do? (1) Fight the monster, (2) Flee, or (3) Try talking calmly to him." << endl;
			int choice_three;
			points += 2;
			cin >> choice_three;
			if(cin.fail() || (choice_three > 3 || choice_three < 1))
				cout << "You lose. Game Over." << endl;
			if(choice_three == 1)
			{
				cout << "You are torn apart by the monster as you rush forward. You lose. Game Over." << endl;
			}
			if(choice_three == 2)
			{
				cout << "You try to flee, and are caught and eaten by the monster. You lose. Game Over." << endl;
			}
			if(choice_three == 3)
			{
				cout << "You speak calmly to the monster about how much you miss your brother. By the end the monster is nearly in tears, and agrees to help you to free your brother. Congratulations! You Win! Tune in next time for part 2!" << endl;
				points += 3;
			}
		}
		if(choice_two ==3)
		{
			cout << "The man wakes as you prod him gently. He greets you, and after hearing your story agrees to help you free your brother." << endl;
			cout << "As you reach the end of the hallway you a large beast confronts you." << endl;
			cout << name << "! You have trespassed within this Labyrinth for far too long. Fight me or lose your brother, Toby!" << endl;
			cout << "What do you do? (1) Fight the monster, (2) Flee, or (3) Try talking calmly to him." << endl;
			int choice_three;
			points += 2;
			cin >> choice_three;
			if(cin.fail() || (choice_three > 3 || choice_three < 1))
				cout << "You lose. Game Over." << endl;
			if(choice_three == 1)
			{
				cout << "You are torn apart by the monster as you rush forward. He also consumes your new friend. You lose. Game Over." << endl;
			}
			if(choice_three == 2)
			{
				cout << "You try to flee, and are caught and eaten by the monster. He also consumes your new friend. You lose. Game Over." << endl;
			}
			if(choice_three == 3)
			{
				cout << "You speak calmly to the monster about how much you miss your brother. By the end the monster is nearly in tears, and agrees to help you to free your brother. Congratulations! You Win! Tune in next time for part 2!" << endl;
				points += 3;
			}
		}
	}
	if(choice_one == 2)
	{
		cout << "You talk down passage 2. You are a little cold, but soon adjust to the temperature. The slime continues, but you dare not touch it." << endl;
		cout << "You continue to walk until you come across a small man sleeping on the floor." << endl;
		cout << "Do you (1) choose to attack the man, (2) ignore the man, or (3) wake him and ask for help?" << endl;
		int choice_two;
		points+= 2;
		cin >> choice_two;
		if(cin.fail() || (choice_two > 3 || choice_two < 1))
			cout << "You lose. Game Over." << endl;
		if(choice_two == 1)
		{
			cout << "The man wakes before you have a chance to attack and stabs you with a knife he kept conceled beneath him. You lose. Game Over." << endl;
		}
		if(choice_two == 2)
		{
			cout << "You step gingerly over the man. He does not wake up. As you reach the end of the hallway you a large beast confronts you." << endl;
			cout << name << "! You have trespassed within this Labyrinth for far too long. Fight me or lose your brother, Toby!" << endl;
			cout << "What do you do? (1) Fight the monster, (2) Flee, or (3) Try talking calmly to him." << endl;
			int choice_three;
			points += 3;
			cin >> choice_three;
			if(cin.fail() || (choice_three > 3 || choice_three < 1 ))
				cout << "You lose. Game Over." << endl;
			if(choice_three == 1)
			{
				cout << "You are torn apart by the monster as you rush forward. You lose. Game Over." << endl;
			}
			if(choice_three == 2)
			{
				cout << "You try to flee, and are caught and eaten by the monster. You lose. Game Over." << endl;
			}
			if(choice_three == 3)
			{
				cout << "You speak calmly to the monster about how much you miss your brother. By the end the monster is nearly in tears, and agrees to help you to free your brother. Congratulations! You Win! Tune in next time for part 2!" << endl;
				points += 3;
			}
		}
		if(choice_two ==3)
		{
			cout << "The man wakes as you prod him gently. He greets you, and after hearing your story agrees to help you free your brother." << endl;
			cout << "As you reach the end of the hallway you a large beast confronts you." << endl;
			cout << name << "! You have trespassed within this Labyrinth for far too long. Fight me or lose your brother, Toby!" << endl;
			cout << "What do you do? (1) Fight the monster, (2) Flee, or (3) Try talking calmly to him." << endl;
			int choice_three;
			points += 4;
			cin >> choice_three;
			if(cin.fail() || (choice_three > 3 || choice_three < 1))
				cout << "You lose. Game Over." << endl;
			if(choice_three == 1)
			{
				cout << "You are torn apart by the monster as you rush forward. He also consumes your new friend. You lose. Game Over." << endl;
			}
			if(choice_three == 2)
			{
				cout << "You try to flee, and are caught and eaten by the monster. He also consumes your new friend. You lose. Game Over." << endl;
			}
			if(choice_three == 3)
			{
				cout << "You speak calmly to the monster about how much you miss your brother. By the end the monster is nearly in tears, and agrees to help you to free your brother. Congratulations! You Win! Tune in next time for part 2!" << endl;
				cout << "As a bonus, you have also chosen the best path through the labyrinth and scored the highest score possible! Congratulations!" << endl;
				points += 6;
			}
		}
	}
	if(choice_one == 3)
	{
		cout << "You take a hesitant step into passage 3. As you place your foot in the empty air you lose your balance and fall into the abyss. Your body is never found." << endl;
		cout << "You lose. Game over." << endl;
	}
	cout << "You have scored " << points << " points!" << endl;
}
