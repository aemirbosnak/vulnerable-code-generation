//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 100

typedef struct Graph {
    int numVertices;
    int **adjList;
    int **color;
} Graph;

void graphColoring(Graph *graph) {
    int i, j, k, currentVertex, color, conflict;
    graph->color = (int *)malloc(graph->numVertices * sizeof(int));
    for (i = 0; i < graph->numVertices; i++) {
        graph->color[i] = -1;
    }
    for (i = 0; i < graph->numVertices; i++) {
        currentVertex = graph->adjList[i][0];
        for (j = 0; j < graph->adjList[i][1]; j++) {
            conflict = 0;
            for (k = 0; k < graph->numVertices; k++) {
                if (graph->color[k] == graph->color[currentVertex] && k != currentVertex) {
                    conflict = 1;
                }
            }
            if (!conflict) {
                graph->color[currentVertex] = k;
            }
        }
    }
}

int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
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
    graph->adjList[4][1] = 1;

    graphColoring(graph);

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d has color %d\n", i, graph->color[i]);
    }

    free(graph);
    return 0;
}