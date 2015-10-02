#include<stdio.h>
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void DFSUtil(int,int*);
	public:
		Graph(int);
		void addEdge(int,int);
		void DFS(int);
};

Graph::Graph(int v){
	this->V= v;
	adj = new list<int>[v];
}

void Graph::addEdge(int src,int dest){
	adj[src].push_back(dest);
}

void Graph::DFSUtil(int v,int* visited){
	visited[v] = 1;
	cout << v <<" ";
	list<int>::iterator it;
	for(it = adj[v].begin();it!=adj[v].end();it++){
		if(!visited[*it])
		DFSUtil(*it,visited);
	}
}


void Graph::DFS(int v){
	int i;
	int* visited = new int[V];
	for(i=0;i<V;i++){
		visited[i] = 0;
	}
	
	for(int i = 0; i < V; i++)
        if(visited[i] == false)
	      DFSUtil(v,visited);	
}

int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	g.DFS(2);
	return 0;
}

