//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Edge {
    int src, dest;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int num;
    struct Vertex* neighbors;
} Vertex;

Vertex* createVertex(int num) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->num = num;
    v->neighbors = NULL;
    return v;
}

Edge* createEdge(int src, int dest) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->src = src;
    e->dest = dest;
    e->next = NULL;
    return e;
}

void addEdge(Vertex* v, Edge* e) {
    e->next = v->neighbors;
    v->neighbors = e;
}

void mapTopology(Vertex* v) {
    printf("Vertex %d: ", v->num);
    for (Edge* e = v->neighbors; e; e) {
        printf("(%d)", e->dest);
    }
    printf("\n");
}

int main() {
    Vertex* vertices[MAX_VERTICES];
    Edge* edges[MAX_EDGES];

    for (int i = 0; i < MAX_VERTICES; i++) {
        vertices[i] = createVertex(i);
    }

    for (int i = 0; i < MAX_EDGES; i++) {
        edges[i] = createEdge(i, i + 1);
    }

    for (int i = 0; i < MAX_VERTICES; i++) {
        addEdge(vertices[i], edges[i]);
    }

    for (int i = 0; i < MAX_VERTICES; i++) {
        mapTopology(vertices[i]);
    }

    return 0;
}