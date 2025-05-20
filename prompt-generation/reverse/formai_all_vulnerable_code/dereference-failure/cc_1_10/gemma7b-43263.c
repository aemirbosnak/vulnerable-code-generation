//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    int index;
    struct Vertex* next;
    struct Edge* edges;
} Vertex;

typedef struct Edge {
    int targetVertexIndex;
    struct Edge* nextEdge;
} Edge;

Vertex* createVertex(int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;
    vertex->edges = NULL;
    return vertex;
}

Edge* createEdge(int targetVertexIndex) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->targetVertexIndex = targetVertexIndex;
    edge->nextEdge = NULL;
    return edge;
}

void addEdge(Vertex* vertex, Edge* edge) {
    vertex->edges = edge;
}

void printGraph(Vertex* vertex) {
    Edge* edge = vertex->edges;
    while (edge) {
        printf("Vertex %d -> Target Vertex %d\n", vertex->index, edge->targetVertexIndex);
        edge = edge->nextEdge;
    }
}

int main() {
    Vertex* vertexList[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        vertexList[i] = NULL;
    }

    vertexList[0] = createVertex(0);
    vertexList[1] = createVertex(1);
    vertexList[2] = createVertex(2);

    addEdge(vertexList[0], createEdge(1));
    addEdge(vertexList[0], createEdge(2));
    addEdge(vertexList[1], createEdge(2));

    printGraph(vertexList[0]);

    return 0;
}