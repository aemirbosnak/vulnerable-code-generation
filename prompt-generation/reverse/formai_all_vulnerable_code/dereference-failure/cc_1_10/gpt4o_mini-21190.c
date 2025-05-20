//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a new Graph
Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;

    // Initialize the adjacency matrix
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
    return g;
}

// Function to add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    g->adjacencyMatrix[src][dest] = 1;
    g->adjacencyMatrix[dest][src] = 1; // For undirected graph
}

// Function to display the adjacency matrix
void displayGraph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < g->numVertices; i++) {
        for(int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform DFS
void DFSUtil(Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for(int i = 0; i < g->numVertices; i++) {
        if(g->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

// Function to initiate DFS
void DFS(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS starting from vertex %d: ", startVertex);
    DFSUtil(g, startVertex, visited);
    printf("\n");
}

// Function to perform BFS
void BFS(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS starting from vertex %d: ", startVertex);
    while(front < rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for(int i = 0; i < g->numVertices; i++) {
            if(g->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Function to free the graph
void freeGraph(Graph* g) {
    free(g);
}

int main() {
    int vertices = 5;
    Graph* myGraph = createGraph(vertices);

    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 4);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 1, 4);
    addEdge(myGraph, 2, 3);
    addEdge(myGraph, 3, 4);

    displayGraph(myGraph);

    DFS(myGraph, 0);
    BFS(myGraph, 0);

    freeGraph(myGraph);
    return 0;
}