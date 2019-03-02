#include "pch.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int n = 0, row = 0, col = 0;
int score = 0, total_score = 0;
char playboard[9][9];
void instructions()
{
	cout << "This is the multiplication board game." << endl;
	cout << " A random number will be displayed and the player will have to choose 2 numbers" << endl;
	cout << "in form of row and column that will  multiply to give that number." << endl;
	cout << "A correct answer will fetch +10 points and a wrong answer will fetch -5 points." << endl;
	cout << "The total score will be displayed at the end of 10 rounds." << endl;
	cout << "ALL The Best" << endl;
}
void draw_board()
{
	for (int i = 1; i < 10; i++)
	{
		cout << "   " << i;
	}
	cout << endl;
	for (int i = 1; i < 10; i++)
	{
		cout << i << "  ";
		for (int j = 1; j < 10; j++)
		{
			cout << "[ ]" << " ";
		}
		cout << endl;
	}
}
void randomize()
{
	srand(time(NULL));
	n = rand() % 9+1;
}
void questions()
{
	cout << "Enter the row and columns as two numbers that will multiply to " << n << endl;
}
void user_input()
{
	cout << "Enter the row number:" << endl;
	cin >> row;
	cout << "Enter the column number:" << endl;
	cin >> col;
}
void check_answer()
{
	if ((row * col) == n)
	{
		cout << "Correct!" << endl;
		score = 10;
		cout << "The score is " << score << endl;
	}
	else if ((row * col) != n)
	{
		cout << "Wrong!" << endl;
		score = -5;
		cout << "The score is " << score << endl;
	}
	total_score += score;
}
void printboard()
{
	if ((row * col) == n)
	{
		for (int i = 1; i < 10; i++)
		{
			cout << "   " << i;
		}
		cout << endl;
		for (int i = 1; i < 10; i++)
		{
			cout << i << " ";
			for (int j = 1; j < 10; j++)
			{
				if (playboard[row][col] = playboard[i][j])
					playboard[row][col] = '*';
				else
					playboard[row][col] = ' ';
				cout << "[" << playboard[i][j] << "]" << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "Wrong answer!" << endl;
}
int main()
{
	instructions();
	int c = 0;
	while (1)
	{
		cout << "This is the new board:" << endl;
		draw_board();
		randomize();
		questions();
		user_input();
		check_answer();
		cout << "This is the point where the row and the column meets to give the sum:" << endl;
		printboard();
		c++;
		if (c == 10)
		{
			cout << "Game Over!" << endl;
			cout << "The total score is:" << total_score << endl;
			break;
		}
	}
	return 0;
}