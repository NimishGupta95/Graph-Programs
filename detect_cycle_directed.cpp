#include<stdio.h>
#include<list>
#include<iostream>

using namespace std;
/* Time Complexity = o(V+E) */

class Graph{
	int V;
	list<int> *adj;
	bool isCycleUtil(int,int*,int*);
	public:
		Graph(int);
		void addEdge(int,int);
		bool isCycle();
};

Graph::Graph(int v){
	this->V= v;
	adj = new list<int>[v];
}

void Graph::addEdge(int src,int dest){
	adj[src].push_back(dest);
}

bool Graph::isCycle(){
	int i;
     int *visited = new int[V];
     int *recStack = new int[V];
     
     for(i=0;i<V;i++){
     	visited[i] = 0;
     	recStack[V] = 0;
     }
     
     for(i=0;i<V;i++){
     	if(isCycleUtil(i,visited,recStack))
     	return true;
     }
     return false;
}

bool Graph::isCycleUtil(int v,int* visited,int* recStack){
	if(!visited[v]){
		visited[v] = 1;
		recStack[v] = 1;
		
		list<int>::iterator it;
		for(it = adj[v].begin(); it!= adj[v].end(); it++){
			if(!visited[*it] && isCycleUtil(*it,visited,recStack))
			return true;
			else if(recStack[*it])
			return true;
		}
	}
	recStack[v] = 0;
	return false;
}

int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    if(g.isCycle())
    printf("Cycle Is Present...");
    else
    printf("Cycle is Not Present..");
	return 0;
}




