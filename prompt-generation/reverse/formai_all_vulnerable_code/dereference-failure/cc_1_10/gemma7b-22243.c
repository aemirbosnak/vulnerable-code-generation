//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Edge {
    int src, dst;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
    struct Edge* edges;
} Vertex;

Vertex* createVertex(int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->neighbors = NULL;
    vertex->edges = NULL;
    return vertex;
}

void addEdge(Vertex* source, Vertex* destination) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->src = source->index;
    edge->dst = destination->index;
    edge->next = source->edges;
    source->edges = edge;
}

void traverseGraph(Vertex* vertex) {
    printf("Vertex: %d ", vertex->index);
    printf("Neighbors: ");
    for (Vertex* neighbor = vertex->neighbors; neighbor; neighbor = neighbor->neighbors) {
        printf("%d ", neighbor->index);
    }
    printf("\n");

    for (Edge* edge = vertex->edges; edge; edge = edge->next) {
        printf("Edge: %d-%d\n", edge->src, edge->dst);
    }
    printf("\n");
}

int main() {
    Vertex* graph = createVertex(0);
    graph->neighbors = createVertex(1);
    graph->neighbors->neighbors = createVertex(2);
    graph->neighbors->neighbors->neighbors = createVertex(3);

    addEdge(graph, graph->neighbors);
    addEdge(graph->neighbors, graph->neighbors->neighbors);
    addEdge(graph->neighbors->neighbors, graph->neighbors->neighbors->neighbors);

    traverseGraph(graph);

    return 0;
}