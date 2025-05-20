//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Alan Turing
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

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->adjacencyList = (Vertex**)malloc(MAX_VERTICES * sizeof(Vertex*));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addVertex(Graph* graph, int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;
    graph->adjacencyList[index] = vertex;
    graph->numVertices++;
}

void addEdge(Graph* graph, int srcIndex, int destIndex) {
    Vertex* source = graph->adjacencyList[srcIndex];
    Vertex* destination = graph->adjacencyList[destIndex];
    source->next = destination;
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph, 0);
    addVertex(graph, 1);
    addVertex(graph, 2);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->adjacencyList[i];
        while (vertex) {
            printf("%d ", vertex->index);
            vertex = vertex->next;
        }
        printf("\n");
    }
    return 0;
}