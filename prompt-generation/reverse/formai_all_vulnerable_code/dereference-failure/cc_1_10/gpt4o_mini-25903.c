//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int start, int end) {
    if (start >= graph->numVertices || end >= graph->numVertices || start < 0 || end < 0) {
        printf("Invalid edge!\n");
        return;
    }
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1; // Uncomment this line for directed graph.
}

void removeEdge(Graph* graph, int start, int end) {
    if (start >= graph->numVertices || end >= graph->numVertices || start < 0 || end < 0) {
        printf("Invalid edge!\n");
        return;
    }
    graph->adjMatrix[start][end] = 0;
    graph->adjMatrix[end][start] = 0; // Uncomment this line for directed graph.
}

void printGraph(Graph* graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    free(graph);
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("Removing edge between vertex 1 and 3...\n");
    removeEdge(graph, 1, 3);
    printGraph(graph);

    freeGraph(graph);

    // Creating and using a new graph
    int newVertices = 6;
    Graph* newGraph = createGraph(newVertices);
    
    addEdge(newGraph, 0, 1);
    addEdge(newGraph, 0, 2);
    addEdge(newGraph, 1, 3);
    addEdge(newGraph, 1, 4);
    addEdge(newGraph, 2, 5);

    printf("New graph adjacency matrix:\n");
    printGraph(newGraph);
    
    freeGraph(newGraph);

    return 0;
}