//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 50

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
} Vertex;

typedef struct Graph {
    Vertex** vertices;
    int numVertices;
    int numEdges;
    int** edges;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = (Vertex**)malloc(numVertices * sizeof(Vertex));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->edges[i] = (int*)malloc(numVertices * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int srcVertex, int destVertex) {
    graph->edges[srcVertex][destVertex] = 1;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->vertices[i];
        printf("Vertex %d: ", vertex->index);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->edges[vertex->index][j] == 1) {
                printf("Connected to Vertex %d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5, 5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    traverseGraph(graph);
    return 0;
}