//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

typedef struct Vertex {
    int index;
    struct Vertex* adjacentVertices;
} Vertex;

void insertVertex(Vertex** graph, int index) {
    *graph = malloc(sizeof(Vertex) * MAX_Vertices);
    (*graph)->index = index;
    (*graph)->adjacentVertices = NULL;
}

void insertEdge(Vertex* vertex, int targetIndex) {
    Vertex* newVertex = malloc(sizeof(Vertex));
    newVertex->index = targetIndex;
    newVertex->adjacentVertices = NULL;

    vertex->adjacentVertices = newVertex;
}

void traverseGraph(Vertex* vertex) {
    printf("Vertex %d: ", vertex->index);

    for (Vertex* neighbor = vertex->adjacentVertices; neighbor; neighbor = neighbor->adjacentVertices) {
        printf("-> Neighbor %d ", neighbor->index);
    }

    printf("\n");
}

int main() {
    Vertex** graph = NULL;

    insertVertex(&graph, 0);
    insertVertex(&graph, 1);
    insertVertex(&graph, 2);
    insertVertex(&graph, 3);
    insertVertex(&graph, 4);

    insertEdge(graph[0], 1);
    insertEdge(graph[0], 2);
    insertEdge(graph[1], 2);
    insertEdge(graph[1], 3);
    insertEdge(graph[2], 3);
    insertEdge(graph[3], 4);

    traverseGraph(graph[0]);
    traverseGraph(graph[1]);
    traverseGraph(graph[2]);
    traverseGraph(graph[3]);
    traverseGraph(graph[4]);

    return 0;
}