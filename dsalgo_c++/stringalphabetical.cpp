
#include<iostream>
#include<string>
using namespace std;
bool jisgreater(string a,string b,int n)
{
	if(a[n]>b[n])
	{
		return true;
	}
	if(a[n]<b[n])
	{
		return false;
	}
	return jisgreater(a,b,n+1);
}

void alphbSort(string *s,int n)
{
	string temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(jisgreater(s[j],s[j+1],0))
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
}

int main()
{
	cout<<".";
	string s[10];
	int n;
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++)
	{
		getline(cin,s[i]);
	}
	alphbSort(s,n);
	for(int i=0;i<n;i++)
	{
		cout<<endl<<s[i];
	}
	return 0;
}
