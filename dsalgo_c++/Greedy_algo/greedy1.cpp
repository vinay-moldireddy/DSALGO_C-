//coin problem using greedy algo
#include<iostream>
#include<algorithm>
using namespace std;
void make_change(int *coins,int n ,int money)
{
	int ans=0;
	while(money>0)
	{
		int idx=upper_bound(coins,coins+n,money) -1 -coins;
		cout<<coins[idx]<<" + ";
		money=money-coins[idx];
		ans++;
			}
		cout<<"="<<ans<<"coins"<<endl;
}

int main()
{
	int money;
	cin>>money;
	int coins[]={1,2,5,10,20,50,1000,500,2000};
	int n=sizeof(coins)/sizeof(coins[0]);
    make_change(coins,n,money);
}
