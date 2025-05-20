//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Edge {
    int source, destination;
    struct Edge* next;
} Edge;

Vertex* createVertex(int index) {
    Vertex* vertex = malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;
    return vertex;
}

Edge* createEdge(int source, int destination) {
    Edge* edge = malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;
    edge->next = NULL;
    return edge;
}

void mapTopology(Vertex* vertices, Edge* edges) {
    for (Vertex* vertex = vertices; vertex; vertex = vertex->next) {
        printf("Vertex %d: ", vertex->index);
        for (Edge* edge = edges; edge; edge = edge->next) {
            if (edge->source == vertex->index) {
                printf("Connected to Vertex %d ", edge->destination);
            }
        }
        printf("\n");
    }
}

int main() {
    Vertex* vertices = createVertex(0);
    vertices = createVertex(1);
    vertices = createVertex(2);
    vertices = createVertex(3);

    Edge* edges = createEdge(0, 1);
    edges = createEdge(1, 2);
    edges = createEdge(2, 3);

    mapTopology(vertices, edges);

    return 0;
}