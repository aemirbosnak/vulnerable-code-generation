//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
} Vertex;

typedef struct Edge {
    int src, dst;
    struct Edge* next;
} Edge;

Vertex* CreateVertex(int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->neighbors = NULL;
    return vertex;
}

Edge* CreateEdge(int src, int dst) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->src = src;
    edge->dst = dst;
    edge->next = NULL;
    return edge;
}

void AddEdge(Vertex* vertex, Edge* edge) {
    vertex->neighbors = edge;
}

void PrintGraph(Vertex* vertex) {
    printf("Vertex %d: ", vertex->index);
    Edge* edge = vertex->neighbors;
    while (edge) {
        printf("-> Vertex %d ", edge->dst);
        edge = edge->next;
    }
    printf("\n");
}

int main() {
    Vertex* graph = CreateVertex(0);
    graph = CreateVertex(1);
    graph = CreateVertex(2);
    graph = CreateVertex(3);

    Edge* edge1 = CreateEdge(0, 1);
    Edge* edge2 = CreateEdge(1, 2);
    Edge* edge3 = CreateEdge(2, 3);

    AddEdge(graph, edge1);
    AddEdge(graph, edge2);
    AddEdge(graph, edge3);

    PrintGraph(graph);

    return 0;
}