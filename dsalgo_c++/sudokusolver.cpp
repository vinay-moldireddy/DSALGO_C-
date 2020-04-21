#include<iostream>
using namespace std;
bool isitok(int sudoku[][9], int p, int r,int c)
{
	for(int i=0;i<9;i++)
	{
		if(sudoku[i][c]==p || sudoku[r][i]==p)
			return false;
	}
	int starti=(r/3)*3;
	int startj=(c/3)*3;
	for(int i=starti;i<starti+3;i++)
	{
		for(int j=startj;j<startj+3;j++)
		{
				if(sudoku[i][j]==p)
				return false;
		}
	}
	return true;
}
bool solvesudoku(int sudoku[][9], int i, int j)
{
	//base case
	if(i==9)
		{return true;}
	//recursive case
	if(j==9)
	{
		return solvesudoku(sudoku,i+1,0);
	}
	if(sudoku[i][j]!=0)
	{
		cout<<i<<" "<<j<<endl;
		return solvesudoku(sudoku,i,j+1);
	}
	for(int p=1;p<=9;p++)
	{
		if(isitok(sudoku,p,i,j))
		{
		sudoku[i][j]=p;
		if(solvesudoku(sudoku,i,j+1))
			{return true;}
		sudoku[i][j]=0;

		}
	}
		return false;
}

int main()
{
	int sudoku[9][9]=
		{{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};
	bool solved=solvesudoku(sudoku,0,0);
	cout<<solved<<endl<<endl;
		for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<sudoku[i][j];
		}
		cout<<endl;
	}
}