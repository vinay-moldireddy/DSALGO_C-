//Thia is 3rd type of three graphs 3.Adjacency list
//for integer data

#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class graph
{
	int v;
	list<int> *l;
	void showlist(list <int> lu)
	{
		list<int> :: iterator it;
		for(it= lu.begin();it!=lu.end();it++)
		{
			cout<<*it<<",";
		}
	}
public:
	graph(int V)
	{
		v=V;
		l=new list<int>[v];   //we are implimenting this using array since we are working with key of integer, array is best.
								// if we use any other data type like string or char we should go with 

	}
	void addedge(int u,int v,bool bidirectional=true)
	{
		l[u].push_back(v);
		if(bidirectional){
			l[v].push_back(u);
		}

	}
	void printadjlist(){
		for(int i=0;i<v;i++)
		{
			cout<<i<<"->";
				showlist(l[i]);
			cout<<endl;
		}
	}
};

int main()
{
	graph adj(6);
	adj.addedge(0,1, false);
	adj.addedge(1,2, false);
	adj.addedge(5,3);
	adj.printadjlist();
}