//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 100

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

void addEdge(Vertex* vertex, Edge* edge) {
    vertex->neighbors = edge;
}

void printTopology(Vertex* vertex) {
    Edge* edge = vertex->neighbors;
    while (edge) {
        printf("(%d, %d) ", vertex->index, edge->dest);
        edge = edge->next;
    }
    printf("\n");
}

int main() {
    Vertex* vertices[MAX_VERTICES];
    Edge* edges[MAX_EDGES];

    // Create vertices
    for (int i = 0; i < MAX_VERTICES; i++) {
        vertices[i] = createVertex(i);
    }

    // Create edges
    for (int i = 0; i < MAX_EDGES; i++) {
        edges[i] = createEdge(rand() % MAX_VERTICES, rand() % MAX_VERTICES);
    }

    // Add edges to vertices
    for (int i = 0; i < MAX_EDGES; i++) {
        addEdge(vertices[edges[i]->src], edges[i]);
    }

    // Print topology
    for (int i = 0; i < MAX_VERTICES; i++) {
        printTopology(vertices[i]);
    }

    return 0;
}