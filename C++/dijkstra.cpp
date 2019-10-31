#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Graph
{
	unordered_map<T,list<pair<T,int> > > m;

public:
	void initialize(T v)
	{
		list<pair<T,int> >x;
		for (int i = 0; i < v; ++i)
		{
			m[i]=x;
		}
	}
	void addEdge(T u,T v,int dist,bool bidir=true)
	{
		m[u].push_back(make_pair(v,dist));
		if(bidir)
			m[v].push_back(make_pair(u,dist));
	}

	void printAdj()
	{
		for(auto i : m)
		{
			cout << i.first <<"->";
			for(auto v : i.second)
			{
				cout <<"("<<v.first<<","<<v.second <<"),";
			}
			cout <<endl;
		}
	}
	void dijkstraSSSP(T src)
	{
		unordered_map<T,int> dist;

		for(auto i:m)
		{
			dist[i.first]=INT_MAX;
		}

		set<pair<int, T> > s;
		dist[src]=0;
		s.insert(make_pair(0,src));

		while(!s.empty())
		{
			auto p=*(s.begin());
			T node=p.second;
			int nodeDist=p.first;
			s.erase(s.begin());

			for(auto childPair : m[node])
			{
				if(nodeDist+childPair.second < dist[childPair.first])
				{
					T dest=childPair.first;
					auto f=s.find(make_pair(dist[dest],dest));
					if(f!=s.end())
					{
						s.erase(f);
					}
					dist[dest]=nodeDist+childPair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}		
		for(auto d:dist)
		{
			cout << d.first << "is located at a distance of "<<d.second<<endl;
		}

	}

};

int main()
{
	Graph<int> g;
	g.initialize(4);
	g.addEdge(0,1,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(1,2,1);
	g.addEdge(2,3,2);
	g.printAdj();
	g.dijkstraSSSP(0);

}
