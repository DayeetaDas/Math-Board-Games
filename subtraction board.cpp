#include "pch.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int n1 = 0, n2 = 0, row = 0, col = 0;
int score = 0, total_score = 0;
char playboard[9][9];
void instructions()
{
	cout << "This is the subtraction board game." << endl;
	cout << "The computer will generate questions. Eg: 10-8." << endl;
	cout << "The player will have to choose two numbers and give them" << endl;
	cout << "as input in form of row and column such that the 2 numbers" << endl;
	cout << "will add up to give the result of the question( that is the difference of the two numbers." << endl;
	cout << "A correct answer will fetch +10 points and a wrong answer will fetch -5 points." << endl;
	cout << "The computer will plot the correct answer in the board." << endl;
	cout << "If the answer is 0 it will not be displayed on the board because it lies on the origin." << endl;
	cout << "Also the points lying on the x axis and the y axis will not be displayed." << endl;
	cout << "The total score will be displayed after 10 rounds." << endl;
	cout << "ALL THE BEST!!" << endl;
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
	n1 = rand() % 16 + 2;
	do
	{
		n2 = rand() % 16+1;
	} while (n1<n2);
}
void questions()
{
	cout << "Enter the row and columns as two numbers that will add up to " << n1<<"-"<<n2 << endl;
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
	if ((row + col) == (n1-n2))
	{
		cout << "Correct!" << endl;
		score = 10;
		cout << "The score is " << score << endl;
	}
	else if ((row + col) != (n1-n2))
	{
		cout << "Wrong!" << endl;
		score = -5;
		cout << "The score is " << score << endl;
	}
	total_score += score;
}
void printboard()
{
	if ((row + col) == (n1-n2))
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
				if (playboard[row][col] == playboard[i][j])
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