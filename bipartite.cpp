#include<stdio.h>
#include<list>
#include<queue>
#include<iostream>

using namespace std;
/* Time Complexity = o(V+E) */

class Graph{
	int V;
	list<int> *adj;
	bool test(int,int);
	public:
		Graph(int);
		void addEdge(int,int);
		bool isBipartite(int);
};

Graph::Graph(int v){
	this->V= v;
	adj = new list<int>[v];
}

void Graph::addEdge(int src,int dest){
	adj[src].push_back(dest);
}

bool Graph::test(int src,int dest)
{
	bool temp = false;
	list<int>::iterator it;
	for(it = adj[src].begin();it!=adj[src].end();it++)
	{
		if(dest == *it)
		temp = true;
	}
	return temp;
	
}

bool Graph::isBipartite(int src){
	int u,b;
	int i;
	int *colorArr = new int[V];
	
	for(i=0;i<V;i++)
	colorArr[i] = -1;
	
	colorArr[src] = 1;
	
	list<int> q;
	q.push_back(src);
	while(!q.empty()){
		u = q.front();
		q.pop_front();
		for(b = 0;b<V;b++){
			if(test(u,b) && colorArr[b] == -1)
			colorArr[b] = 1 - colorArr[b];
			else if(test(u,b) && colorArr[b] == colorArr[u])
			return false;
		}	
	}
	return true;
	
}

int main(){
	Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    if(g.isBipartite(0))
    cout<<"Yes";
    else
    cout<<"No";
	return 0;
}
