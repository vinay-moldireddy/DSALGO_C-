//top down approach and bottom up approach.
#include<iostream>
using namespace std;
int minimumcoinstopdown(int a,int coins[],int n,int ans[])
{
	if(a==0)
	{
		return 0;
	}
	if(ans[a]!=0)
	{
		return ans[a];
	}
	int min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(a-coins[i]>-1)
		{		
			int temp=minimumcoinstopdown((a-coins[i]),coins,n,ans);
			if(temp<min)
				min=temp;
		}
	}
	ans[a]=min+1;
	return min+1;
}
int minimumcoinsbottomup(int a,int coins[],int n)
{
	int arr[a+1];
	arr[0]=0;
	for(int i=1;i<=a;i++)
	{
		int min=INT_MAX;
		for(int j=0;j<n;j++)
		{
			if((i-coins[j])>=0 && arr[i-coins[j]]<min)
				min=arr[i-coins[j]];
		}
		arr[i]=min+1;
	}
	return arr[a];
}
int main()
{
	int a;
	cin>>a;
	int coins[4]={1,7,10,5};
	int ans[1000000]={0};
	int m=minimumcoinstopdown(a,coins,4,ans);
	cout<<endl<<"minimum coins are"<<m<<endl;
	 int n=minimumcoinsbottomup(a,coins,4);
	 cout<<"minimum coins are"<<n<<endl;
	return 0;
}