#include<stdio.h>
#include<list>
#include<iostream>

using namespace std;
/* Time Complexity = o(V+E) */

class Graph{
	int V;
	list<int> *adj;
	bool isCycleUtil(int,int*,int);
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
	adj[dest].push_back(src);
}

bool Graph::isCycle(){
	int i;
     int *visited = new int[V];
     
     for(i=0;i<V;i++){
     	visited[i] = 0;
     }
     
     for(i=0;i<V;i++){
     	if(!visited[i])
     	 if(isCycleUtil(i,visited,-1))
     	  return true;
     }
     return false;
}

bool Graph::isCycleUtil(int v,int* visited,int parent){
	
		visited[v] = 1;
		
		list<int>::iterator it;
		for(it = adj[v].begin(); it!= adj[v].end(); it++){
			if(!visited[*it]){
			if(isCycleUtil(*it,visited,v))
			return true;
		}
			else if(*it != parent)
			return true;
		}
	return false;
}





int main(){
	Graph g1(4);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    if(g1.isCycle())
    printf("Cycle Is Present...\n");
    else
    printf("Cycle is Not Present..\n");
    
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    if(g2.isCycle())
    printf("Cycle Is Present...\n");
    else
    printf("Cycle is Not Present..\n");    
	return 0;
}
