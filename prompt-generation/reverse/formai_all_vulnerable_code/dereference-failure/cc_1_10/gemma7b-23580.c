//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex** vertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->vertices = (Vertex**)malloc(numVertices * sizeof(Vertex));

    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i] = NULL;
    }

    return graph;
}

void addVertex(Graph* graph, int index) {
    Vertex* vertex = malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;

    if (graph->vertices[index] == NULL) {
        graph->vertices[index] = vertex;
    } else {
        graph->vertices[index]->next = vertex;
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->vertices[i];
        printf("Vertex %d: ", i);
        while (vertex) {
            printf("%d ", vertex->index);
            vertex = vertex->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addVertex(graph, 0);
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    addVertex(graph, 4);

    printGraph(graph);

    return 0;
}