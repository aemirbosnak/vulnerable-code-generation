//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 100

typedef struct Edge {
    int src, dest;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int num;
    struct Vertex* neighbors;
} Vertex;

Vertex* createVertex(int num) {
    Vertex* v = malloc(sizeof(Vertex));
    v->num = num;
    v->neighbors = NULL;
    return v;
}

Edge* createEdge(int src, int dest) {
    Edge* e = malloc(sizeof(Edge));
    e->src = src;
    e->dest = dest;
    e->next = NULL;
    return e;
}

void addEdge(Vertex* v, Edge* e) {
    e->next = v->neighbors;
    v->neighbors = e;
}

void printTopology(Vertex* v) {
    printf("Vertex %d: ", v->num);
    for (Edge* e = v->neighbors; e; e) {
        printf("-> Vertex %d", e->dest);
    }
    printf("\n");
}

int main() {
    Vertex* vertices = NULL;
    Edge* edges = NULL;

    // Create vertices
    vertices = createVertex(0);
    vertices = createVertex(1);
    vertices = createVertex(2);

    // Create edges
    edges = createEdge(0, 1);
    edges = createEdge(1, 2);

    // Add edges to vertices
    addEdge(vertices, edges);

    // Print topology
    printTopology(vertices);

    return 0;
}