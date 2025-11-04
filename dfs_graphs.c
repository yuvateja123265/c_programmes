#include <stdio.h> 
#include <stdlib.h> 
#define MAX 100 
int i; 
// Structure for adjacency list node 
struct Node 
{ 
	int vertex; 
	struct Node* next; 
}; 
// Structure for the graph 
struct Graph 
{ 
	int numVertices; 	
	struct Node** adjLists; 
	int* visited; 
}; 
// Create a node 
struct Node* createNode(int vertex) 
{ 
    struct Node* newNode = malloc(sizeof(struct Node)); 
    newNode->vertex = vertex; 
    newNode->next = NULL; 
    return newNode; 
} 
// Create a graph 
struct Graph* createGraph(int vertices) 
{ 
	struct Graph* graph = malloc(sizeof(struct Graph)); 
    graph->numVertices = vertices;  
    graph->adjLists = malloc(vertices * sizeof(struct Node*)); 
    graph->visited = malloc(vertices * sizeof(int)); 
    for (i = 0; i < vertices; i++) 
	{ 
        graph->adjLists[i] = NULL; 
        graph->visited[i] = 0; 
    } 
    return graph; 
} 
// Add edge (undirected) 
void addEdge(struct Graph* graph, int src, int dest) 
{ 
    // Add edge from src to dest 
    struct Node* newNode = createNode(dest); 
    newNode->next = graph->adjLists[src]; 
    graph->adjLists[src] = newNode;  
    // Add edge from dest to src (since it's undirected) 
    newNode = createNode(src); 
    newNode->next = graph->adjLists[dest]; 
    graph->adjLists[dest] = newNode; 
} 
// DFS function 
void DFS(struct Graph* graph, int vertex) 
{ 
    struct Node* adjList = graph->adjLists[vertex]; 
    struct Node* temp = adjList;  
    graph->visited[vertex] = 1; 
    printf("%d ", vertex); 
    while (temp != NULL) 
	{ 
        int connectedVertex = temp->vertex; 
        if (!graph->visited[connectedVertex]) 
		{ 
            DFS(graph, connectedVertex); 
        } 
        temp = temp->next; 
    } 
}  
int main() 
{ 
    int vertices, edges, src, dest, start;  
    printf("Enter number of vertices: "); 
    scanf("%d", &vertices); 
    struct Graph* graph = createGraph(vertices); 
    printf("Enter number of edges: "); 
    scanf("%d", &edges); 
    printf("Enter edges (src dest):\n"); 
    for (i = 0; i < edges; i++) 
	{ 
        scanf("%d %d", &src, &dest); 
        addEdge(graph, src, dest); 
    } 
    printf("Enter starting vertex for DFS: "); 
    scanf("%d", &start); 
    printf("DFS traversal starting from vertex %d: ", start); 
    DFS(graph, start); 
	return 0; 
} 
