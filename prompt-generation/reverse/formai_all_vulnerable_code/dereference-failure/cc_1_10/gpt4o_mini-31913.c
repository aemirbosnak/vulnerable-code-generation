//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure to represent a graph
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int numVertices; // Number of vertices
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Error: Invalid edge (%d, %d)\n", src, dest);
        return;
    }
    graph->adjMatrix[src][dest] = 1; // Directed edge from src to dest
    graph->adjMatrix[dest][src] = 1; // Uncomment for undirected graph
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search (DFS) helper function
void dfsUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;  // Mark the current node as visited
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

// Function to perform DFS traversal
void DFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Initialize visited array
    printf("DFS starting from vertex %d:\n", startVertex);
    dfsUtil(graph, startVertex, visited);
    printf("\n");
}

// Main function to demonstrate the graph
int main() {
    int numVertices = 7;
    Graph* graph = createGraph(numVertices);

    // Surprised by the number of edges we can add
    printf("Adding edges to the graph...\n");
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);
    
    // Surprised again at the graph representation
    printGraph(graph);
    
    // Quite amazed by how we can explore the graph
    DFS(graph, 0);

    // Freeing memory to avoid leaks
    free(graph);
    printf("Graph successfully cleaned up!\n");

    return 0;
}