#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
	map<T,list<T> > adjList;

public:
	Graph()
	{

	}
	void initialize(T v)
	{
		for (int i = 0;i < v; ++i)
		{
			list<T> x;
			adjList[i]=x;
		}
	}
	void addEdge(T u,T v, bool bidir=false)
	{
		adjList[u].push_back(v);
		if(bidir)
		{
			adjList[v].push_back(u);
		}
	}

	void printGraph()
	{
		for(auto i: adjList)
		{
			cout << i.first <<"-->";
			for(auto v:i.second)
				cout << v << ",";
			cout <<endl;
		}
	} 
	void topoSortKahns()//uses BFS
	{
		queue<T> q;
		map<T,bool> visited;
		map<T,int> indegree;

		for(auto i: adjList)
		{
			T node=i.first;
			visited[node]=false;
			indegree[node]=0;
		}

		//init the indegrees of all the nodes
		for(auto i:adjList)
		{
			T u=i.first;
			for(auto v:adjList[u])
			{
				indegree[v]++;
			}
		}
		//find out all the nodes with 0 indegree
		for(auto i : adjList)
		{
			T node=i.first;
			if(indegree[node]==0)
			{
				q.push(node);
			}
		}
		//start with algo
		while(!q.empty())
		{
			T node=q.front();
			q.pop();
			cout <<node<<"-->";
			for(T neighbour:adjList[node])
			{
				indegree[neighbour]--;
				if(indegree[neighbour]==0)
				{
					q.push(neighbour);
				}
			}

		}
	}
};

int main()
{
	int v;
	cin >> v;
	Graph<int> g;
	g.initialize(v);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(0,3);
	g.addEdge(3,6);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.addEdge(2,7);
	g.addEdge(6,7);
	g.addEdge(4,8);
	g.addEdge(7,8);
	g.addEdge(5,8);
	g.printGraph();
	g.topoSortKahns();
}
