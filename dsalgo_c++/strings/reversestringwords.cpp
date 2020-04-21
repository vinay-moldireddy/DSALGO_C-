#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	int n;
	cout<<"test cases: ";cin>>n;
	
	string s,t,temp="";
	cin.get();
for(int i=0;i<n;i++){
	temp="";
	getline(cin,s);
	stringstream x(s);
	while(getline(x,t,'.'))
	{
		temp="."+t+temp;
	}
	temp.erase(0,1);
	cout<<temp<<endl;
}

}