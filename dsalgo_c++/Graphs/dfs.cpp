	
//first we inpliment graph using adjlist hashmap in greric method 
//depth first search
//in bfs we go from one edge through its neighbours and so on by adding in a queue, likewe do in trees level order traversal
//in dfs we go from one edge through its neighbour(only one neighbour) and mark it visited
//1.we need recursive call on the unvisited node
//2.array/map to maintain whether a node is visited or not
#include<iostream>
#include<map>
#include<list>
#include<iterator>
#include<vector>
using namespace std;
template<typename T>
class graph{
	map<T, list<T> > mp;
public:
	graph()
	{}
	void addedge(T a,T b,bool bidirectional=false)  //a is key, b is value to be mapped 
	{
		mp[a].push_back(b);
		if(bidirectional)
		{
			mp[b].push_back(a);
		}
	}
	void printgraph()
	{	
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			cout<<(it->first)<<"->";
		    for(auto p:it->second)
				cout<<p<<", ";
			cout<<endl;
		}
	}
	void helperdfs(T node,map<T,bool> &visited)
	{
		visited[node]=true;
		cout<<node<<" ";
		for(auto neighbour:mp[node]){
			if(!visited[neighbour])
				helperdfs(neighbour,visited);
		}
	}
	void dfs(T src)
	{
		map<T, bool> visited; 
		helperdfs(src,visited);
	}
};	 
int main()
{	
	graph<int> g;
	g.addedge(1,0);
	g.addedge(0,2);
	g.addedge(0,3);
	g.addedge(0,4);
	g.addedge(2,3,true);
	g.addedge(3,4,true);
	g.printgraph();
	g.dfs(1);
}	