#include "pch.h"
#include<iostream>
using namespace std;
int board[3][3] ;
char playboard[3][3];
int n1 = 0, n2 = 0;
void user_input()
{
	cout << "Enter two pairs of numbers:" << endl;
	cin >> n1 >> n2;
}
void draw()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[n1][n2] == 1)
				user_input();
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[n1][n2] == 0)
			{
				board[n1][n2] = 1;
				board[i - n1][j - n2] = 0;
			}
			    cout << board[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int c = 0;
	while (c<=1)
	{
		user_input();
		draw();
		c++;
	}
	return 0;
}