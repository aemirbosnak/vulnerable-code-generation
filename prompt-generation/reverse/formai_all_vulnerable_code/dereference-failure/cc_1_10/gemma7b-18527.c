//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 100
#define MAX_Edges 1000

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Edge {
    int src, dst;
    struct Edge* next;
} Edge;

Vertex* createVertex(int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;
    return vertex;
}

Edge* createEdge(int src, int dst) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->src = src;
    edge->dst = dst;
    edge->next = NULL;
    return edge;
}

void mapTopology(Vertex* vertex, Edge* edge) {
    printf("Vertex %d: ", vertex->index);
    for (Edge* currentEdge = edge; currentEdge; currentEdge = currentEdge->next) {
        if (currentEdge->src == vertex->index) {
            printf("Edge to Vertex %d\n", currentEdge->dst);
        }
    }
}

int main() {
    Vertex* vertices = NULL;
    Edge* edges = NULL;

    // Create a few vertices
    vertices = createVertex(0);
    vertices = createVertex(1);
    vertices = createVertex(2);
    vertices = createVertex(3);

    // Create a few edges
    edges = createEdge(0, 1);
    edges = createEdge(1, 2);
    edges = createEdge(2, 3);

    // Map the topology
    mapTopology(vertices, edges);

    return 0;
}