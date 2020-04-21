
#include<iostream>
#include<string>
using namespace std;
int main()
{

	int n;cin>>n;cin.get();
	for(int i=0;i<n;i++)
	{
	string s;
	cin>>s;
	int r=-1;
	int z=s.size();
	for(int i=0;i<z-1;i++)
	{
		if(s[i]==s[i+1])
		{
			if(r==-1) r=i;
			if(i+2==z+1 || s[i]!=s[i+2])
			{
				s.erase(r,i+1-r+1);
				r=-1;
			}
		}
	}
	cout<<s<<endl;
}
}
