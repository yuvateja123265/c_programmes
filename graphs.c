//BFS Implementation
#include <stdio.h>
#define MAX 10
int graph[MAX][MAX];      // Adjacency matrix
int visited[MAX];         // Visited array for BFS
int queue[MAX];           // Queue for BFS
int front = -1, rear = -1;
// Function to add an edge (undirected)
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}
// Queue operations for BFS
void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}
int isEmpty() {
    return front == -1 || front > rear;
}
// BFS using array
void BFS(int start, int n) {
	int i;
    for (i = 0; i < n; i++) 
		visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    while (!isEmpty()) {
    	int i;
        int current = dequeue();
        printf("%d ", current);
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
// Main function
int main() {
    int vertices,i,j;
    char ch;
    printf("Enter number of vertices:");
	scanf("%d",&vertices);
	for(i=0;i<vertices;i++)
	{
		for(j=i+1;j<vertices;j++)
		{
			printf("Do you want edge from %d to %d:",i,j);
			scanf(" %c",&ch);
			if(ch=='Y'||ch=='y')
			addEdge(i,j);
		}
	}
    printf("\n\nBFS starting from vertex 0:\n");
    BFS(0, vertices);
    return 0;
}
