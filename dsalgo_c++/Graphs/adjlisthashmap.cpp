//Thia is 3rd type of three graphs 3.Adjacency list
//for any type generic data
#include<iostream>
#include<list>
#include<map>
#include<string>
#include<iterator>
#include<queue>
using namespace std;
template <typename T>
class graph
{
	map<T, list <T> > l;
public:
	graph()     //we are not passing any length because we are using hash map 
	{

	}
	void addedge(T u,T v,bool bidirectional=false)
	{
		l[u].push_back(v);
		if(bidirectional){
			l[v].push_back(u);
		}
	}

	// void printadjlist(){
	// 	for(auto it:l)
	// 	{
	// 		cout<<it.first<<"->";
	// 			for(T p:it.second)
	// 				cout<<p<<", ";
	// 		cout<<endl;
	// 	}
	// }

	void bfs(T edg){
		queue<T> q;
		map<T,int> len;
		
		q.push(edg);

		for(auto p:l)
		{
			len[p.first]= INT_MAX;
		}
		len[edg]=0;
		while(!q.empty())
		{		
			T node=q.front();
			cout<<node<<" ";
			q.pop();
			for(T neighbour:l[node])
			{	
				if(len[neighbour]==INT_MAX)
				{
					q.push(neighbour);
					len[neighbour]=len[node]+1;
				}
			}	
		}

		for(auto i:l)
		{
			T node=i.first;
			cout<<"distance of node " << node <<" is"<<len[node]<<endl;
		}		
	}
};

int main()
{
	graph<string> adj;
	adj.addedge("vinay","utkarsh",true);
	adj.addedge("utkarsh","rithik");
	adj.addedge("rithik","satyajeeth",true);
	adj.addedge("vinay","rithik",true);
	adj.addedge("vinay","kumar",true);
	adj.addedge("kumar","reddy",true);
	adj.addedge("rashi","abhinav",true);
	adj.addedge("kumar","rashi",true);
	cout<<endl;
	adj.bfs("vinay");
}