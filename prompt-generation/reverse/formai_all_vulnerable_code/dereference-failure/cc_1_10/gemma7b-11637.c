//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 50

typedef struct Edge {
    int src, dest;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int num;
    struct Vertex* neighbours;
} Vertex;

Vertex* createVertex(int num) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->num = num;
    v->neighbours = NULL;
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
    e->next = v->neighbours;
    v->neighbours = e;
}

void traverseGraph(Vertex* v) {
    printf("Vertex: %d\n", v->num);
    for (Edge* e = v->neighbours; e; e) {
        printf("  Neighbour: %d\n", e->dest);
    }
}

int main() {
    Vertex* graph[MAX_VERTICES];
    Edge* edges[MAX_EDGES];

    // Create vertices
    graph[0] = createVertex(0);
    graph[1] = createVertex(1);
    graph[2] = createVertex(2);

    // Create edges
    edges[0] = createEdge(0, 1);
    edges[1] = createEdge(0, 2);
    edges[2] = createEdge(1, 2);

    // Add edges to vertices
    addEdge(graph[0], edges[0]);
    addEdge(graph[0], edges[1]);
    addEdge(graph[1], edges[2]);

    // Traverse the graph
    traverseGraph(graph[0]);

    return 0;
}