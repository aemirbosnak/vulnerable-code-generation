//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct {
    int v;
    int w;
} Edge;

typedef struct {
    int nvertices;
    int nedges;
    Edge edges[MAX_VERTICES * (MAX_VERTICES - 1) / 2];
} Graph;

Graph* createGraph(int nvertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->nvertices = nvertices;
    graph->nedges = 0;

    return graph;
}

void addEdge(Graph* graph, int v, int w) {
    if(graph->nedges >= MAX_VERTICES * (MAX_VERTICES - 1) / 2) {
        printf("Error: maximum number of edges reached.\n");
        return;
    }

    graph->edges[graph->nedges].v = v;
    graph->edges[graph->nedges].w = w;
    graph->nedges++;
}

bool hasEdge(Graph* graph, int v, int w) {
    for(int i = 0; i < graph->nedges; i++) {
        if((graph->edges[i].v == v && graph->edges[i].w == w) || (graph->edges[i].v == w && graph->edges[i].w == v)) {
            return true;
        }
    }

    return false;
}

void printGraph(Graph* graph) {
    printf("Number of vertices: %d\n", graph->nvertices);
    printf("Number of edges: %d\n", graph->nedges);

    for(int i = 0; i < graph->nedges; i++) {
        printf("(%d, %d)\n", graph->edges[i].v, graph->edges[i].w);
    }
}

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("Has edge (2, 3): %d\n", hasEdge(graph, 2, 3));
    printf("Has edge (1, 4): %d\n", hasEdge(graph, 1, 4));
    printf("Has edge (0, 4): %d\n", hasEdge(graph, 0, 4));

    return 0;
}