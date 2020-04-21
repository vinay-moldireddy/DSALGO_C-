#include<iostream>
#include<string>
using namespace std;
void permute(string s,int l,int p)
{
	if(p==l)
	{
		cout<<s<<endl;
	}
	else
	{
	    for(int i=l;i<=p;i++)
	   {
		  swap(s[l],s[i]);
		  permute(s,l+1,p);
		  swap(s[l],s[i]);
	   }
    }
}
int main()
{
	cout<<"main started: ";
	string a;
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		permute(a,0,a.size()-1);
	}
	return 0;
}