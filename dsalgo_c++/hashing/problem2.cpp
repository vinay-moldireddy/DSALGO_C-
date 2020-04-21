//to find longest such sub array wiht sum zero
//to find this we use unordered map and store index and prefix sum simultaniously
#include<iostream>
#include<unordered_map>
using namespace std;
int longests(int *arr,int n)
{
	unordered_map<int,int> m;
	int pre=0,max_length=0;
	for(int i=0; i<n ;i++)
	{
		pre+=arr[i];
		if(arr[i]==0 && max_length==0) max_length=1;
		if(pre==0) max_length = max(max_length, i+1);
		if(m.find(pre)!=m .end())
			max_length=max(max_length,i-m[pre]);
		else
			m[pre]=i;
	}
	cout<<max_length<<endl;
	return max_length;
}
int main(int argc, char const *argv[])
{
    int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0; i<n ; i++)
	{
		cin>>arr[i];
	}
	//int arr[]={1,-1,2,-2};int n=4;
	cout<<".....";
	int p=longests(arr,n);
	cout<<p<<endl;
}