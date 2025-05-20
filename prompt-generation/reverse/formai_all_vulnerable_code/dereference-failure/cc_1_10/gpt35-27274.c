//FormAI DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Graph structure
struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Function to create graph with n vertices
struct Graph *createGraph(int n) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjMatrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->adjMatrix[i] = (int*) calloc(n, sizeof(int));
    }
    return graph;
}

// Function to add edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Check if vertices are out of bounds
    if ((src >= 0 && src < graph->numVertices) && (dest >= 0 && dest < graph->numVertices)) {
        // Add edge to the adjacency matrix
        graph->adjMatrix[src][dest] = weight;
        graph->adjMatrix[dest][src] = weight;
    }
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix: \n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 1);
    printGraph(graph);
    return 0;
}