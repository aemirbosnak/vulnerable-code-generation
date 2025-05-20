//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Graph {
    int **adjList;
    int numVertices;
} Graph;

void graphColor(Graph *graph) {
    int *colors = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->adjList[i][0]; j++) {
            if (colors[graph->adjList[i][j]] != -1) {
                colors[i] = -1;
            }
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = 0;
    }

    int count = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int color = colors[i];
        if (color == -1) {
            color = colors[i] = ++count;
        }
    }

    printf("The number of colors used is: %d\n", count);
}

int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = MAX_VERTS;
    graph->adjList = (int **)malloc(graph->numVertices * sizeof(int *));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjList[i] = (int *)malloc(sizeof(int) * 2);
    }

    graphColor(graph);

    return 0;
}