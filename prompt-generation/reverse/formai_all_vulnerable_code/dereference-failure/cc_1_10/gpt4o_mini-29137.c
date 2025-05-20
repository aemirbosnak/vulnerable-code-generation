//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

// A structure to represent a graph
struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0; // Initialize with no edges
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices) {
        fprintf(stderr, "Error: Attempting to add an edge to a non-existent vertex.\n");
        return;
    }
    graph->adjacencyMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

// Function to display the graph's adjacency matrix
void displayGraph(struct Graph* graph) {
    printf("Adjacency Matrix of the graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to implement DFS recursively
void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true; // Mark the current node as visited
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        // If the vertex is adjacent and not visited
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to perform DFS traversal
void DFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // Initialize all vertices as not visited
    printf("Depth First Traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // Initialize all vertices as not visited
    int queue[MAX_VERTICES], front = -1, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex; // Enqueue the starting vertex
    front++;

    printf("Breadth First Traversal starting from vertex %d: ", startVertex);

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true; // Mark the vertex as visited
                queue[++rear] = i; // Enqueue the vertex
            }
        }
    }
    printf("\n");
}

// Function to free the graph's memory
void freeGraph(struct Graph* graph) {
    free(graph);
}

int main() {
    int vertices = 5;
    struct Graph* myGraph = createGraph(vertices);

    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 2);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 2, 4);
    
    displayGraph(myGraph);
    
    DFS(myGraph, 0);
    BFS(myGraph, 0);
    
    freeGraph(myGraph);

    return 0;
}