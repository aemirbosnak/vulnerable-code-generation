//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Graph {
    int **adjList;
    int numVertices;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(MAX_VERTS * sizeof(int*));
    graph->numVertices = 0;

    for (int i = 0; i < MAX_VERTS; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjList[u] = (int*)realloc(graph->adjList[u], (graph->numVertices + 1) * sizeof(int));
    graph->adjList[u][graph->numVertices] = v;
    graph->numVertices++;
}

void graphColoring(Graph* graph) {
    int* colors = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    int currentColor = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int available = 1;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] != -1 && colors[j] == currentColor) {
                available = 0;
            }
        }

        if (available) {
            colors[i] = currentColor;
        } else {
            currentColor++;
            colors[i] = currentColor;
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    free(colors);
}

int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    graphColoring(graph);

    free(graph);

    return 0;
}