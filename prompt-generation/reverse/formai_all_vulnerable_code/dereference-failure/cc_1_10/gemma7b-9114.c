//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 100

typedef struct Graph {
    int numVertices;
    int **adjList;
} Graph;

Graph* graphCreate(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int*)malloc(numVertices * sizeof(int));
    }
    return graph;
}

void graphAddEdge(Graph* graph, int u, int v) {
    graph->adjList[u][v] = 1;
}

int graphColor(Graph* graph) {
    int* colors = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    int chromaticNumber = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int availableColors = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && colors[j] != -1) {
                availableColors++;
            }
        }
        colors[i] = availableColors;
        chromaticNumber = fmax(chromaticNumber, colors[i]);
    }

    free(colors);
    return chromaticNumber;
}

int main() {
    Graph* graph = graphCreate(5);
    graphAddEdge(graph, 0, 1);
    graphAddEdge(graph, 0, 2);
    graphAddEdge(graph, 1, 2);
    graphAddEdge(graph, 2, 3);
    graphAddEdge(graph, 3, 4);
    graphAddEdge(graph, 4, 0);

    int chromaticNumber = graphColor(graph);

    printf("Chromatic number of the graph: %d\n", chromaticNumber);

    return 0;
}