//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Edge {
    int src, dest;
    char *label;
} Edge;

typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge **edges;
} Graph;

Graph *createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->edges = NULL;
    return graph;
}

void addEdge(Graph *graph, int src, int dest, char *label) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->label = label;

    graph->edges = (Edge **)realloc(graph->edges, (graph->numEdges + 1) * sizeof(Edge *));
    graph->edges[graph->numEdges++] = edge;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numEdges; i++) {
        Edge *edge = graph->edges[i];
        printf("%d -> %d (%s)\n", edge->src, edge->dest, edge->label);
    }
}

int main() {
    Graph *graph = createGraph();

    addEdge(graph, 0, 1, "Hello");
    addEdge(graph, 1, 2, "World");
    addEdge(graph, 2, 3, "!");

    printGraph(graph);

    return 0;
}