//using normal method by checking each number whether it is ugly or not 
//in dp we find all ugly no. and store in array time/space complex is O(n)

#include<iostream>
using namespace std;
int maxdivide(int i,int d)
{
	while(i%d==0)
		i=i/d;
	cout<<i<<endl;
	return i;

}
int uglynumber(int no)
{
	cout<<".....";
	no=maxdivide(no,2);
	no=maxdivide(no,3);
    no=maxdivide(no,5) ;                                                                                                                    
	if(no==1)
		return 1;
	return 0;
}

int nthuglynumber(int n)
{
	int i=1;
	int count=1;
	while(n > count)
	{
		i++;
		cout<<i<<endl;
		if(uglynumber(i))
			count++;
	}
	return i;
}
int main()
{
	int n;
	cin>>n;
	cout<<nthuglynumber(10)<<endl;
	return 0;
}