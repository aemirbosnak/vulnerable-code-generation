//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

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

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = (Vertex**)malloc(numVertices * sizeof(Vertex));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->edges = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->edges[i] = (int*)malloc(numVertices * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 1;
    graph->numEdges++;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->vertices[i];
        printf("Vertex %d: ", vertex->index);
        for (Vertex* neighbor = vertex->neighbors; neighbor; neighbor = neighbor->neighbors) {
            printf("Neighbor %d ", neighbor->index);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    traverseGraph(graph);
    return 0;
}