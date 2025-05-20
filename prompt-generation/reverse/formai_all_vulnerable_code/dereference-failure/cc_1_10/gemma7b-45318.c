//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 100

typedef struct Graph {
    int numVertices;
    int **adjList;
} Graph;

void graphColor(Graph *graph) {
    int i, j, k, color, degree[MAX_VERTS], available[MAX_VERTS];
    color = 0;
    for (i = 0; i < graph->numVertices; i++) {
        degree[i] = 0;
        available[i] = 1;
    }

    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->adjList[i]; j++) {
            degree[j]++;
        }
    }

    for (i = 0; i < graph->numVertices; i++) {
        for (k = degree[i]; k > 0; k--) {
            available[i] = 0;
        }
    }

    for (i = 0; i < graph->numVertices; i++) {
        if (available[i]) {
            color++;
            available[i] = 0;
        }
    }

    printf("The number of colors used is: %d\n", color);
}

int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adjList = (int **)malloc(graph->numVertices * sizeof(int *));
    graph->adjList[0] = 2;
    graph->adjList[1] = 3;
    graph->adjList[2] = 4;
    graph->adjList[3] = 2;
    graph->adjList[4] = 1;

    graphColor(graph);

    return 0;
}