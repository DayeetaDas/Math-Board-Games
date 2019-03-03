#include "pch.h"
#include<iostream>
#include <cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
int board[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
char playboard[4][4] = { '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' };
int n1 = 0, n2 = 0;
int arr[10];
int cn1=0, cn2=0;
int p = 1;
int score = 0, total_score=0;
int cscore = 0, ctotal_score=0;
void instructions()
{
	cout << "This is a board game in which the user chooses two numbers between 0 and 5" << endl;
	cout << "such that the product of those two numbers results to a number on the playboard." << endl;
	cout << "The computer also chooses two numbers between 0 and 5." << endl;
	cout << "The number gets displayed on the playboard." << endl;
	cout << "If the product of the two numbers chosen by the user is greater than that of the numbers chosen by the computer" << endl;
	cout << "the user gets +10 points and the computer gets -5 points and the vice versa." << endl;
	cout << "The winner is declared at the end of 5 rounds." << endl;
	cout << endl;
}
void draw_board()
{
	cout << "1   2    3   4" << endl;
	cout << "5   6    7   8" << endl;
	cout << "9   10   11  12 " << endl;
	cout << "13  14   15  16" << endl;
}
void user_input()
{
	
	do
	{
		cout << "Enter a number between 0 and 5:" << endl;
		cin >> n1;
		cout << "Enter another number:" << endl;
		cin >> n2;
	} while (((n1*n2) == (cn1*cn2)) || (n1>4 && n2>4) || (n1<0 && n2<0));
}
void computer()
{
	srand(time(NULL));
	cn1 = rand() % 3+1;
	cn2 = rand() % 3 + 1;
}
void new_board_human()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == (n1*n2))
				playboard[i][j] = '*';
			cout << playboard[i][j] << " ";
		}
		cout << endl;
	}
}
void new_board_computer()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j]==(cn1*cn2))
				playboard[i][j] = '*';
			cout << playboard[i][j] << " ";
		}
		cout << endl;
	}
}
void check()
{
	if ((n1*n2) > (cn1*cn2))
	{
		cout << "The computer chose :" << (cn1*cn2) << endl;
		cout << "The number you have as product is:" <<(n1*n2)<< endl;
		score = 10;
		cscore = -5;
		cout << "You score " << score << endl;
		cout << "The computer scores " << cscore << endl;
	}
	else
	{
		cout << "The computer chose :" << (cn1*cn2) << endl;
		cout << "The number you have as product is:" << (n1*n2) << endl;
		score = -5;
		cscore = 10;
		cout << "You score " << score << endl;
		cout << "The computer scores " << cscore << endl;
	}
	total_score += score;
	ctotal_score+=cscore;
}
int main()
{
	instructions();
	int c = 0;
	while (c < 5)
	{
		draw_board();
		user_input();
		computer();
		cout << "This is your board:" << endl;
		new_board_human();
		cout << endl;
		cout << "This is the computer's board:" << endl;
		new_board_computer();
		check();
		c++;
		if (c == 5)
		{
			cout << "Your total score is " << total_score << endl;
			cout << "The computer's total score is " << ctotal_score << endl;
			if (total_score > ctotal_score)
				cout << "You won the game!" << endl;
			else
				cout << "The computer won the game!" << endl;
			break;
		}
	}
	return 0;
}