#include<stdio.h>
#include<iostream>
#include<list>
#include<queue>
#define V 5

using namespace std;

int minKey(int* key,bool* mstSet){
	int min = 9999,minIndex = 0,i;
	for(i=0;i<V;i++){
		if(mstSet[i] == false && key[i] < min){
			min = key[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void printMst(int* parent,int graph[V][V]){
	int i;
	printf(" Edge   Weight\n");
	for(i=1;i<V;i++){
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
	}
}

void primMst(int graph[V][V]){
	int i,u,v;
	int parent[V];
	int key[V];
	bool mstSet[V];
	for(i=0;i<V;i++){
		key[i] = 9999;
		mstSet[i] = false;	
	}
	
	key[0] = 0;
	parent[0] = -1;
	
	for(i=0; i<V-1; i++){
		u = minKey(key,mstSet);
		mstSet[u] = true;
		for(v=0; v<V; v++){
			if(graph[u][v] && mstSet[v] == false && graph[u][v]<key[v]){
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
	
	printMst(parent,graph);
}

int main(){
	  int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
      primMst(graph);               
}

