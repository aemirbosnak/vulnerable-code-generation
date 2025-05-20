//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10
#define MAX_Edges 50

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
} Vertex;

typedef struct Edge {
    int src, dest;
    struct Edge* next;
} Edge;

Vertex* createVertex(int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->neighbors = NULL;
    return vertex;
}

Edge* createEdge(int src, int dest) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->next = NULL;
    return edge;
}

void addNeighbor(Vertex* vertex, Edge* edge) {
    vertex->neighbors = edge;
}

void printGraph(Vertex* vertex) {
    Edge* edge = vertex->neighbors;
    while (edge) {
        printf("%d -> %d\n", vertex->index, edge->dest);
        edge = edge->next;
    }
}

int main() {
    Vertex* graph = createVertex(0);
    addNeighbor(graph, createEdge(0, 1));
    addNeighbor(graph, createEdge(0, 2));
    addNeighbor(graph, createEdge(1, 3));
    addNeighbor(graph, createEdge(2, 4));

    printGraph(graph);

    return 0;
}