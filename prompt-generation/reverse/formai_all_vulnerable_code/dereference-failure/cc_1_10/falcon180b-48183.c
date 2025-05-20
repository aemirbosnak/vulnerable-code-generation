//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200

// Graph representation using adjacency matrix
typedef struct {
    int numVertices;
    int** adjacencyMatrix;
} Graph;

// Create a new graph with n vertices
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->adjacencyMatrix = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(n*sizeof(int));
        memset(graph->adjacencyMatrix[i], 0, n*sizeof(int));
    }
    return graph;
}

// Add an edge between two vertices
void addEdge(Graph* graph, int u, int v) {
    graph->adjacencyMatrix[u][v] = 1;
    graph->adjacencyMatrix[v][u] = 1;
}

// Check if there is an edge between two vertices
bool hasEdge(Graph* graph, int u, int v) {
    return graph->adjacencyMatrix[u][v] == 1;
}

// Print the adjacency matrix
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Free the memory used by the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    Graph* graph = createGraph(n);

    printf("Enter the edges (u v): ");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("The graph representation:\n");
    printGraph(graph);

    freeGraph(graph);

    return 0;
}