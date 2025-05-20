//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
} Vertex;

typedef struct Edge {
    int src, dst;
    struct Edge* next;
} Edge;

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

void mapTopology(Vertex* vertices, Edge* edges) {
    for (Vertex* vertex = vertices; vertex; vertex = vertex->neighbors) {
        printf("Vertex %d has neighbors:", vertex->index);
        for (Edge* edge = vertex->neighbors; edge; edge = edge->next) {
            printf(" Vertex %d", edge->dst);
        }
        printf("\n");
    }
}

int main() {
    Vertex* vertices = createVertex(0);
    vertices->neighbors = createVertex(1);
    vertices->neighbors->neighbors = createVertex(2);
    vertices->neighbors->neighbors->neighbors = createVertex(3);

    Edge* edges = createEdge(0, 1);
    edges->next = createEdge(1, 2);
    edges->next->next = createEdge(2, 3);

    mapTopology(vertices, edges);

    return 0;
}