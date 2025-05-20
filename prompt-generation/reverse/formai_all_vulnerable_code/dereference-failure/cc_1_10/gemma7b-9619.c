//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int **adjList;
    int numVertices;
} Graph;

void graphColoring(Graph *graph) {
    int *colors = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    int currentColor = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int neighbors = graph->adjList[i][0];
        for (int j = 0; j < neighbors; j++) {
            if (colors[graph->adjList[i][j]] == currentColor) {
                currentColor++;
            }
        }
        colors[i] = currentColor;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    free(colors);
}

int main() {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adjList = (int **)malloc(graph->numVertices * sizeof(int *));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjList[i] = (int *)malloc(2 * sizeof(int));
    }

    graph->adjList[0][0] = 1;
    graph->adjList[0][1] = 2;
    graph->adjList[1][0] = 2;
    graph->adjList[1][1] = 3;
    graph->adjList[2][0] = 3;
    graph->adjList[2][1] = 4;
    graph->adjList[3][0] = 4;
    graph->adjList[3][1] = 5;
    graph->adjList[4][0] = 5;

    graphColoring(graph);

    return 0;
}