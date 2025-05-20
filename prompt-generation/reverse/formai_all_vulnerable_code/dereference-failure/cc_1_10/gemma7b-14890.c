//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    int index;
    struct Vertex** neighbors;
} Vertex;

Vertex** createGraph(int numVertices) {
    Vertex** graph = (Vertex**)malloc(numVertices * sizeof(Vertex));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = (Vertex*)malloc(sizeof(Vertex));
        graph[i]->index = i;
        graph[i]->neighbors = NULL;
    }
    return graph;
}

void addEdge(Vertex** graph, int u, int v) {
    Vertex* neighbor = (Vertex*)malloc(sizeof(Vertex));
    neighbor->index = v;
    neighbor->neighbors = NULL;
    graph[u]->neighbors = neighbor;
}

void traverseGraph(Vertex** graph, int currentVertex) {
    printf("Vertex %d: ", currentVertex);
    for (Vertex* neighbor = graph[currentVertex]->neighbors; neighbor; neighbor = neighbor->neighbors) {
        printf("-> Vertex %d ", neighbor->index);
    }
    printf("\n");
}

int main() {
    int numVertices = 5;
    Vertex** graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    traverseGraph(graph, 0);
    traverseGraph(graph, 1);
    traverseGraph(graph, 2);

    return 0;
}