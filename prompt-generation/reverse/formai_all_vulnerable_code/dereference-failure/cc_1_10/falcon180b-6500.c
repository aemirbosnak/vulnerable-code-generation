//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 2000

typedef struct {
    int vertex1;
    int vertex2;
    double weight;
} Edge;

typedef struct {
    int numVertices;
    int numEdges;
    Edge edges[MAX_EDGES];
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    return graph;
}

void addEdge(Graph* graph, int vertex1, int vertex2, double weight) {
    Edge edge = {vertex1, vertex2, weight};
    graph->edges[graph->numEdges++] = edge;
}

void printGraph(Graph* graph) {
    printf("Graph with %d vertices and %d edges:\n", graph->numVertices, graph->numEdges);
    for (int i = 0; i < graph->numEdges; i++) {
        printf("%d -- %d (weight: %.2f)\n", graph->edges[i].vertex1, graph->edges[i].vertex2, graph->edges[i].weight);
    }
}

int main() {
    Graph* graph = createGraph(MAX_VERTICES);
    int numVertices = 5;
    int numEdges = 6;

    addEdge(graph, 0, 1, 2.5);
    addEdge(graph, 0, 2, 3.5);
    addEdge(graph, 1, 2, 1.5);
    addEdge(graph, 2, 3, 1.2);
    addEdge(graph, 3, 4, 2.1);
    addEdge(graph, 2, 4, 2.8);

    printGraph(graph);

    return 0;
}