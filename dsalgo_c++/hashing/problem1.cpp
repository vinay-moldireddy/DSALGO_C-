//find if any subarray sum is zero or not
//prefix sum based approach using hashing unordered_set
#include<iostream>
#include<unordered_set>
using namespace std;
bool checkifsubarrayiszero(int *arr,int n)
{
	unordered_set<int> s;
	int pre=0;
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		if(pre==0 || s.find(pre)!=s.end())
		{
			return true;
		}
	s.insert(pre);
	}
	return false;
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
	bool b=checkifsubarrayiszero(arr,n);

	if(b==0)
		cout<<"NO";
	else 
		cout<<"YES";
}