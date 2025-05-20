//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct Graph {
    int numVertices;
    int numEdges;
    int **adjMatrix;
} Graph;

// Create a new graph with n vertices
Graph *createGraph(int n) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->numEdges = 0;
    graph->adjMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph->adjMatrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void addEdge(Graph *graph, int u, int v) {
    if (u < 0 || u >= graph->numVertices || v < 0 || v >= graph->numVertices) {
        printf("Invalid vertices\n");
        return;
    }
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
    graph->numEdges++;
}

// Print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Free the graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Driver code
int main() {
    // Create a graph
    Graph *graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Free the graph
    freeGraph(graph);

    return 0;
}