//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Define structure for Graph
typedef struct Graph {
    int V;      // Total number of vertices
    int **adj;  // Adjacency matrix
} Graph;

// Function to create a graph with given vertices
Graph *createGraph(int V) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (int **) malloc(V * sizeof(int *));

    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *) calloc(V, sizeof(int));
    }

    return graph;
}

// Function to add an edge between two vertices
void addEdge(Graph *graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

// Function to print the adjacency matrix
void printGraph(Graph *graph) {
    printf("Adjacency matrix representation of the graph:\n");

    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search
void DFSUtil(int v, bool visited[], Graph *graph) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] == 1 && visited[i] == false)
            DFSUtil(i, visited, graph);
    }
}

// Function to perform DFS traversal
void DFS(Graph *graph) {
    bool *visited = (bool *) calloc(graph->V, sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        if (visited[i] == false) {
            DFSUtil(i, visited, graph);
            printf("\n");
        }
    }

    free(visited);
}

// Driver code
int main() {
    int V = 5;
    Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    printf("\nDepth First Traversal:\n");
    DFS(graph);

    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

    return 0;
}