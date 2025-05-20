//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1000

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
} Vertex;

typedef struct Graph {
    Vertex** vertices;
    int numVertices;
    int** adjacencyMatrix;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = (Vertex**)malloc(numVertices * sizeof(Vertex));
    graph->numVertices = numVertices;
    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(numVertices * sizeof(int));
    }
    return graph;
}

void addVertex(Graph* graph, int index) {
    graph->vertices[index] = (Vertex*)malloc(sizeof(Vertex));
    graph->vertices[index]->index = index;
    graph->vertices[index]->neighbors = NULL;
    graph->numVertices++;
}

void addEdge(Graph* graph, int sourceIndex, int destinationIndex) {
    graph->adjacencyMatrix[sourceIndex][destinationIndex] = 1;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->vertices[i];
        printf("Vertex %d: ", vertex->index);
        for (Vertex* neighbor = vertex->neighbors; neighbor; neighbor = neighbor->neighbors) {
            printf("Neighbor: %d ", neighbor->index);
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
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    traverseGraph(graph);

    return 0;
}