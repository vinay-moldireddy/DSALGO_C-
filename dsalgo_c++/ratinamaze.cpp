//rat can move in a 2D matrix only right and down
//print all possible ways to reach destination
//count no.of possible ways
//shortest path.
#include<iostream>
using namespace std;

class maze{

	char ratmaze[100][100]={0};
	int ratpath[100][100]={0};
	int m;
public:
	int p=0;
	maze(int size)
	{
		m=size;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
			cin>>ratmaze[i][j];
			}
		}
	}
	void printmaze()
	{
		cout<<endl;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
			cout<<ratmaze[i][j]<<" ";
			}
			cout<<endl;
		}

	}
	void printpath()
	{
		cout<<endl;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
			cout<<ratpath[i][j]<<" ";
			}
			cout<<endl;
		}

	}
	bool path(int a=0, int b=0)
	{
		ratpath[a][b]=1;
		if(a==m-1 && b==m-1)
		{
			p++;
			return true;
		}
		if(ratmaze[a][b+1]=='o')
		{
			if(path(a,b+1))
				return true;
		}
		if(ratmaze[a+1][b]=='o')
		{		
			if(path(a+1,b))
				return true;
		}
		ratpath[a][b]=0;
     	return false;
	}
};
int main()
{
	int n;
	cout<<"enter size of matrix"; cin>>n;
	maze m(n);
	m.printmaze();
	bool exist=m.path();
	m.printpath();
	cout<<m.p<<endl;
}