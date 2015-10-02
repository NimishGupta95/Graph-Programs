#include<stdio.h>
#include<iostream>
#include<list>
#include<queue>

using namespace std;

class QueueEntry{
	public:
	int vertex;
	int distance;
};

int minimumDiceThrown(int* board,int N){
	int i,vertex1;
	bool *visited = new bool[N];
	for(i=0;i<N;i++)
	visited[i] = false;
	queue<QueueEntry> q;
	
	QueueEntry s;
	s.vertex = 0;
	s.distance = 0;
	visited[0] = true;
	q.push(s);
	
	QueueEntry qe;
	while(!q.empty()){
		qe = q.front();
		vertex1 = qe.vertex;
		if(vertex1 == N-1)
		break;
		q.pop();
		for(i = (vertex1+1);i<=(vertex1+6) && i<N;i++){
			QueueEntry cell;
			cell.distance = qe.distance+1;
			visited[i] = true;
			if(board[i] != -1)
			cell.vertex = board[i];
			else
			cell.vertex = i;
			q.push(cell);
		}
	}
	return qe.distance;
}


int main(){
	
	int N = 30;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
    cout<<minimumDiceThrown(moves,N);
    
    return 0;

}
