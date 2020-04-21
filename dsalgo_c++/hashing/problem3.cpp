//tofind max subarray with sum k

#include<iostream>
#include<unordered_map>
using namespace std;
int subarraywithsumk(int *arr,int n,int k)
{
	int pre=0,len=0;
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		if(pre==k && i==0)
			len=1;
		if(pre==k)
			len=i+1;
		if(m.find(pre-k)!=m.end())
			len=max(len,i-m[pre-k]);
		else 
			m[pre]=i;
	}
return len;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[10];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"sum-";
	int k;
	cin>>k;
	int a=subarraywithsumk(arr,n,k);
	cout<<a<<endl;
}