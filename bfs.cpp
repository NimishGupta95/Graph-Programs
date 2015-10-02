#include<stdio.h>
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int);
		void addEdge(int,int);
		void BFS(int);
};

Graph::Graph(int v){
	this->V= v;
	adj = new list<int>[v];
}

void Graph::addEdge(int src,int dest){
	adj[src].push_back(dest);
}

void Graph::BFS(int v){
	int i;
	int *visited = new int[V];
	for(i=0;i<V;i++){
		visited[i] = 0;
	}
	
	list<int> queue;
	visited[v] = 1;
	queue.push_back(v);
	list<int>::iterator it;
	
	while(!queue.empty()){
		v = queue.front();
		cout << v << " ";
		queue.pop_front();
		for(it=adj[v].begin();it!=adj[v].end();it++){
			if(!(visited[*it])){
				visited[*it] = 1;
			    queue.push_back(*it);
		}
		}
		
	}
	
}

int main(){
	Graph g(4);
     g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	g.BFS(2);
	return 0;
}

