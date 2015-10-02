#include<stdio.h>
#include<iostream>
#include<list>
#include<queue>
#define V 9

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

int printSolution(int dist[])
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

void dijkshtra(int graph[V][V],int src){
	int i,u,v;
	int dist[V];
	bool sptSet[V];
	for(i=0;i<V;i++){
		dist[i] = 9999;
		sptSet[i] = false;	
	}
	
	dist[src] = 0;
	
	for(i=0; i<V-1; i++){
		u = minKey(dist,sptSet);
		sptSet[u] = true;
		for(v=0; v<V; v++){
			if(graph[u][v] && sptSet[v] == false && graph[u][v] + dist[u]< dist[v] && dist[u]!= 9999){
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	
	printSolution(dist);
}

int main(){
	  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
      dijkshtra(graph,0);               
}

