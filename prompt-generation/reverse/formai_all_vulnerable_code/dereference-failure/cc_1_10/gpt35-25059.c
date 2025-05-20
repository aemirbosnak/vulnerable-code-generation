//FormAI DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct {
    int numberOfVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* instantiateGraph(int numberOfVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numberOfVertices = numberOfVertices;
    int i, j;
    for (i = 0; i < numberOfVertices; i++) {
        for (j = 0; j < numberOfVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int sourceVertex, int destinationVertex) {
    graph->adjacencyMatrix[sourceVertex][destinationVertex] = 1;
}

void removeEdge(Graph* graph, int sourceVertex, int destinationVertex) {
    graph->adjacencyMatrix[sourceVertex][destinationVertex] = 0;
}

void printGraph(Graph* graph) {
    int i, j;
    printf("Adjacency Matrix Representation of Graph:\n");
    for (i = 0; i < graph->numberOfVertices; i++) {
        for (j = 0; j < graph->numberOfVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {

    Graph* graph = instantiateGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    removeEdge(graph, 0, 1);

    printGraph(graph);

    return 0;
}