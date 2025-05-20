//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct Graph {
    int **adj;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adj = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adj[i] = (int*)malloc(numVertices * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
}

void graphColoring(Graph* graph) {
    int* colors = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    int chromaticNumber = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int availableColors = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adj[i][j] && colors[j] != -1) {
                availableColors++;
            }
        }
        colors[i] = availableColors;
        chromaticNumber = fmax(chromaticNumber, colors[i]);
    }

    printf("The chromatic number of the graph is: %d\n", chromaticNumber);
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    graphColoring(graph);

    return 0;
}