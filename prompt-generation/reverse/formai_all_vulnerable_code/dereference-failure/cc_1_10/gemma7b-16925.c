//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 20

typedef struct Graph {
    int **adj;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adj = malloc(sizeof(int*) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        graph->adj[i] = malloc(sizeof(int) * numVertices);
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
}

void graphColoring(Graph* graph) {
    int* colors = malloc(sizeof(int) * graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    int currentColor = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int usedColors = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adj[i][j] && colors[j] != -1) {
                usedColors++;
            }
        }
        colors[i] = currentColor - usedColors;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d colored with color %d\n", i, colors[i]);
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    graphColoring(graph);

    return 0;
}