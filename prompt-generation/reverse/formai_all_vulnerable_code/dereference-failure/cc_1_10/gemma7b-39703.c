//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10
#define MAX_EDGES 20

typedef struct Vertex {
    char name[20];
    struct Vertex* neighbors;
} Vertex;

typedef struct Edge {
    Vertex* source;
    Vertex* destination;
    int weight;
} Edge;

Vertex* createVertex(char* name) {
    Vertex* vertex = malloc(sizeof(Vertex));
    strcpy(vertex->name, name);
    vertex->neighbors = NULL;
    return vertex;
}

Edge* createEdge(Vertex* source, Vertex* destination, int weight) {
    Edge* edge = malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;
    edge->weight = weight;
    return edge;
}

void printGraph(Vertex* vertex) {
    printf("%s: ", vertex->name);
    for (Edge* edge = vertex->neighbors; edge; edge++) {
        printf("%s (w=%d) ", edge->destination->name, edge->weight);
    }
    printf("\n");
}

int main() {
    Vertex* graph = createVertex("A");
    graph->neighbors = createVertex("B");
    graph->neighbors->neighbors = createVertex("C");
    graph->neighbors->neighbors->neighbors = createVertex("D");

    Edge* edge1 = createEdge(graph, graph->neighbors, 10);
    Edge* edge2 = createEdge(graph->neighbors, graph->neighbors->neighbors, 20);
    Edge* edge3 = createEdge(graph->neighbors->neighbors, graph->neighbors->neighbors->neighbors, 30);

    printGraph(graph);

    return 0;
}