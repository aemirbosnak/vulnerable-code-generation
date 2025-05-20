//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Edge {
    int src, dst;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
} Vertex;

Vertex* createVertex(int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->neighbors = NULL;
    return vertex;
}

Edge* createEdge(int src, int dst) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->src = src;
    edge->dst = dst;
    edge->next = NULL;
    return edge;
}

void addEdge(Vertex* vertex, Edge* edge) {
    edge->next = vertex->neighbors;
    vertex->neighbors = edge;
}

void traverseGraph(Vertex* vertex) {
    printf("Vertex: %d ", vertex->index);
    Edge* edge = vertex->neighbors;
    while (edge) {
        printf("-> Edge to Vertex: %d ", edge->dst);
        edge = edge->next;
    }
    printf("\n");
}

int main() {
    Vertex* vertices[MAX_Vertices];
    Edge* edges[MAX_Edges];

    for (int i = 0; i < MAX_Vertices; i++) {
        vertices[i] = createVertex(i);
    }

    for (int i = 0; i < MAX_Edges; i++) {
        edges[i] = createEdge(i, i + 1);
    }

    addEdge(vertices[0], edges[0]);
    addEdge(vertices[1], edges[1]);
    addEdge(vertices[2], edges[2]);

    traverseGraph(vertices[0]);
    traverseGraph(vertices[1]);
    traverseGraph(vertices[2]);

    return 0;
}