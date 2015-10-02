#include<stdio.h>
#include<list>
#include<stack>
#include<iostream>

using namespace std;
/* Time Complexity = o(V+E) */

class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int,int*,stack<int> &s);
	public:
		Graph(int);
		void addEdge(int,int);
		void topologicalSort();
};

Graph::Graph(int v){
	this->V= v;
	adj = new list<int>[v];
}

void Graph::addEdge(int src,int dest){
	adj[src].push_back(dest);
}

void Graph::topologicalSort(){
	int i;
	stack<int> s;
	int *visited = new int[V];
	for(i=0;i<V;i++)
	visited[i] = 0;
	
	for(i=0;i<V;i++){
		if(!visited[i])
		topologicalSortUtil(i,visited,s);
	}
	
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
}

void Graph::topologicalSortUtil(int v,int* visited,stack<int> &s){
	visited[v] = 1;
	
	list<int>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++){
		if(!visited[v])
		topologicalSortUtil(*it,visited,s);
	}
	s.push(v);
}



int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    g.topologicalSort();   
	return 0;
}
