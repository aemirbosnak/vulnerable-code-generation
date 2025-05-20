//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_NUM_VERTICES 10
#define MAX_NUM_EDGES 20

typedef struct Edge {
    int src, dest;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int index;
    Edge* edges;
} Vertex;

Vertex* createVertex(int index) {
    Vertex* v = malloc(sizeof(Vertex));
    v->index = index;
    v->edges = NULL;
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
    e->next = v->edges;
    v->edges = e;
}

int main() {
    int numVertices = 5;
    Vertex** graph = malloc(numVertices * sizeof(Vertex*));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = createVertex(i);
    }

    addEdge(graph[0], createEdge(0, 1));
    addEdge(graph[0], createEdge(0, 2));
    addEdge(graph[1], createEdge(1, 2));
    addEdge(graph[1], createEdge(1, 3));
    addEdge(graph[2], createEdge(2, 3));
    addEdge(graph[2], createEdge(2, 4));
    addEdge(graph[3], createEdge(3, 4));

    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: ", graph[i]->index);
        for (Edge* e = graph[i]->edges; e; e = e->next) {
            printf("Edge to Vertex %d ", e->dest);
        }
        printf("\n");
    }

    return 0;
}