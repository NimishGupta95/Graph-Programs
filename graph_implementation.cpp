#include<stdio.h>
#include<list>
#include<stdlib.h>


typedef struct graph{
	int v;
	int e;
	struct listNode** adj;
}graph;

typedef struct listNode{
	int vertexNumber;
	struct listNode* next; 
}list;

graph* createGraph();
void printGraph(graph*);

int main(){
	graph* G = createGraph();
    printGraph(G); 
	return 0;
}

graph* createGraph(){
	int u,v,i;
	graph* G = (graph*)malloc(sizeof(graph));
	printf("Enter No Of Vertax...\n");
	scanf("%d",&G->v);
	printf("Enter The No Of Edes...\n");
	scanf("%d",&G->e);
	G->adj = (list**)malloc(sizeof(list*) * G->v);
	for(i=0;i<G->v;i++){
		G->adj[i] = (list*)malloc(sizeof(list));
		G->adj[i]->vertexNumber = i;
		G->adj[i]->next = NULL;	
	}
	for(i=0; i<G->e ;i++){
		scanf("%d %d",&u,&v);
		list* newNode1 = (list*)malloc(sizeof(list));
		newNode1->vertexNumber = v;
		newNode1->next = G->adj[u]->next;
        G->adj[u]->next = newNode1;
        
        list* newNode2 = (list*)malloc(sizeof(list));
        newNode2->vertexNumber = u;
        newNode2->next = G->adj[v]->next;
        G->adj[v]->next = newNode2;
	}
	return G;
	
}

void printGraph(graph* G){
	int i;
	struct listNode* ptr;
	for(i=0; i < G->v; i++){
		ptr = G->adj[i]->next;
		printf("%d -> ",i);	
		while(ptr!=NULL){
			printf("%d ",ptr->vertexNumber);
			ptr = ptr->next;	
		}
		printf("\n");
	}
} 
