//using recursion
//n* n matrix with n queens such that every queen is safe 

#include<iostream>
using namespace std;
bool isitsafeto(int matrix[][10],int i,int j,int n)
{
	//check for column j
	for(int row=0;row<i;row++)
		{if(matrix[row][j]==1)
			return false;
		}
	//for left diagonal 
		int x=i;
		int y=j;
	while (x>=0 && y>=0)
	{
		if(matrix[x][y]==1)
			return false;
		x--;y--;
	}
	x=i;
	y=j;
	while (x>=0 && y<n)
	{
		if(matrix[x][y])
			return false;
		x--;y ++;
	}
	//now position is safe if we reach here
	return true;
}
bool nqueen(int matrix[][10],int n,int i)
{
	//base case
	if(i==n)
	{
		//print matrix 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<matrix[i][j]<<" ";

			}
			cout<<endl;
		}
		return true;
	}

	//recursive case
	//place the queen in current row 
	for(int j=0;j<n;j++)
	{
		if(isitsafeto(matrix,i,j,n))
		{
			matrix[i][j]=1;
			cout<<matrix[i][j]<<endl;
			if(nqueen(matrix,n,i+1))
				return true;
		}

		//if we reach here it means we are not able to place in this row 
		matrix[i][j]=0;
	}
	//you have tried all positon s in current row 
 return false;
}
int main()
{
	int n;
	cout<<"enter number of queens= ";
	cin>>n;
	int matrix[10][10]={0};
	bool ans=nqueen(matrix,n,0);
}