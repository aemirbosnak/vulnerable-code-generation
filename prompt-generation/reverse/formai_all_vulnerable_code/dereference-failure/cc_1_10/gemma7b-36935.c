//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
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
    int source, destination;
    struct Edge* next;
} Edge;

void createVertex(Vertex** vertexList, int index) {
    *vertexList = malloc(sizeof(Vertex));
    (*vertexList)->index = index;
    (*vertexList)->neighbors = NULL;
}

void createEdge(Edge** edgeList, int source, int destination) {
    *edgeList = malloc(sizeof(Edge));
    (*edgeList)->source = source;
    (*edgeList)->destination = destination;
    (*edgeList)->next = NULL;
}

void drawTopology(Vertex* vertexList, Edge* edgeList) {
    for (Vertex* v = vertexList; v; v = v->neighbors) {
        for (Edge* e = edgeList; e; e = e->next) {
            if (e->source == v->index) {
                printf("Edge: %d -> %d\n", v->index, e->destination);
            }
        }
    }
}

int main() {
    Vertex* vertexList = NULL;
    Edge* edgeList = NULL;

    createVertex(&vertexList, 0);
    createVertex(&vertexList, 1);
    createVertex(&vertexList, 2);
    createVertex(&vertexList, 3);

    createEdge(&edgeList, 0, 1);
    createEdge(&edgeList, 1, 2);
    createEdge(&edgeList, 2, 3);

    drawTopology(vertexList, edgeList);

    return 0;
}