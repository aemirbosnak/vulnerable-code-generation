//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10
#define MAX_COLORS 5

typedef struct Graph {
    int numVertices;
    int numEdges;
    int **adjList;
    int **colorList;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    graph->colorList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int*)malloc(numVertices * sizeof(int));
        graph->colorList[i] = (int*)malloc(MAX_COLORS * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjList[u][v] = 1;
}

void graphColoring(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        int availableColors = MAX_COLORS;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && graph->colorList[j][0] != 0) {
                availableColors--;
            }
        }
        graph->colorList[i][0] = availableColors;
    }
}

int main() {
    Graph* graph = createGraph(5, 5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    graphColoring(graph);
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d has %d available colors\n", i, graph->colorList[i][0]);
    }
    return 0;
}