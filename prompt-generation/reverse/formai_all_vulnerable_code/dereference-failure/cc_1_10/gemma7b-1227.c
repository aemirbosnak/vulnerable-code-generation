//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex** adjacencyList;
} Graph;

void insertVertex(Graph* graph) {
    graph->numVertices++;
    graph->adjacencyList = (Vertex**)realloc(graph->adjacencyList, graph->numVertices * sizeof(Vertex*));
    graph->adjacencyList[graph->numVertices - 1] = malloc(sizeof(Vertex));
    graph->adjacencyList[graph->numVertices - 1]->index = graph->numVertices - 1;
    graph->adjacencyList[graph->numVertices - 1]->next = NULL;
}

void insertEdge(Graph* graph, int src, int dest) {
    Vertex* vertex = graph->adjacencyList[src];
    Vertex* newVertex = malloc(sizeof(Vertex));
    newVertex->index = dest;
    newVertex->next = NULL;
    vertex->next = newVertex;
}

int main() {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->adjacencyList = NULL;

    insertVertex(graph);
    insertVertex(graph);
    insertVertex(graph);

    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);

    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->adjacencyList[i];
        printf("Vertex %d: ", vertex->index);
        while (vertex) {
            printf("-> Vertex %d ", vertex->next->index);
            vertex = vertex->next;
        }
        printf("\n");
    }

    free(graph);
    return 0;
}