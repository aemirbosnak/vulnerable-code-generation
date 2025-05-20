//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Edge {
    int src, dst;
    struct Edge* next;
} Edge;

void createGraph(Vertex**, Edge**, int*, int*);

void printGraph(Vertex*, Edge*);

int main() {
    Vertex* vertices = NULL;
    Edge* edges = NULL;
    int numVertices = 0, numEdges = 0;

    createGraph(&vertices, &edges, &numVertices, &numEdges);

    printGraph(vertices, edges);

    return 0;
}

void createGraph(Vertex** vertices, Edge** edges, int* numVertices, int* numEdges) {
    *numVertices = MAX_VERTICES;
    *numEdges = MAX_EDGES;

    *vertices = (Vertex*)malloc(*numVertices * sizeof(Vertex));
    *edges = (Edge*)malloc(*numEdges * sizeof(Edge));

    for (int i = 0; i < *numVertices; i++) {
        (*vertices)[i].index = i;
        (*vertices)[i].next = NULL;
    }

    for (int i = 0; i < *numEdges; i++) {
        (*edges)[i].src = 0;
        (*edges)[i].dst = 0;
        (*edges)[i].next = NULL;
    }
}

void printGraph(Vertex* vertices, Edge* edges) {
    for (Vertex* v = vertices; v; v = v->next) {
        printf("Vertex %d: ", v->index);
        for (Edge* e = edges; e; e = e->next) {
            if (e->src == v->index) {
                printf("-> Edge to Vertex %d ", e->dst);
            }
        }
        printf("\n");
    }
}