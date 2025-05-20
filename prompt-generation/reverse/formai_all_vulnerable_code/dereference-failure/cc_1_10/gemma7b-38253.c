//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 1000

typedef struct Vertex {
    int index;
    struct Vertex **neighbors;
    char **data;
} Vertex;

typedef struct Graph {
    Vertex **vertices;
    int numVertices;
    int **adjacencyList;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->vertices = malloc(numVertices * sizeof(Vertex));
    graph->numVertices = numVertices;
    graph->adjacencyList = malloc(numVertices * numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i] = malloc(sizeof(Vertex));
        graph->vertices[i]->index = i;
        graph->vertices[i]->neighbors = NULL;
        graph->vertices[i]->data = NULL;
    }
    return graph;
}

void addVertex(Graph *graph, int index) {
    graph->vertices[index] = malloc(sizeof(Vertex));
    graph->vertices[index]->index = index;
    graph->vertices[index]->neighbors = NULL;
    graph->vertices[index]->data = NULL;
    graph->numVertices++;
}

void addEdge(Graph *graph, int sourceIndex, int destinationIndex) {
    graph->adjacencyList[sourceIndex][destinationIndex] = 1;
    graph->adjacencyList[destinationIndex][sourceIndex] = 1;
}

void traverseGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyList[i][j] == 1) {
                printf("Edge between vertices %d and %d\n", i, j);
            }
        }
    }
}

int main() {
    Graph *graph = createGraph(5);
    addVertex(graph, 0);
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    addVertex(graph, 4);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    traverseGraph(graph);

    return 0;
}