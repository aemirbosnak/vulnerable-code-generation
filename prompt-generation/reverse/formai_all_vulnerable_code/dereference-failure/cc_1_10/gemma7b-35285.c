//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTS 100

typedef struct Graph {
    int **adjList;
    int numVertices;
} Graph;

void graphColoring(Graph *graph) {
    int *colors = (int *)malloc(graph->numVertices * sizeof(int));
    int i, j, k, color = 1, conflict = 0;

    for (i = 0; i < graph->numVertices; i++) {
        colors[i] = -1;
    }

    while (!conflict) {
        for (i = 0; i < graph->numVertices; i++) {
            if (colors[i] == -1) {
                for (j = 0; j < graph->numVertices; j++) {
                    if (i != j && graph->adjList[i][j] && colors[j] != -1) {
                        for (k = 1; k <= MAX_VERTS; k++) {
                            if (colors[j] == k) {
                                colors[i] = k;
                                break;
                            }
                        }
                    }
                }
                colors[i] = color++;
            }
        }
        conflict = 1;
        for (i = 0; i < graph->numVertices; i++) {
            if (colors[i] == -1) {
                conflict = 0;
            }
        }
    }

    for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }
    free(colors);
}

int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adjList = (int **)malloc(graph->numVertices * sizeof(int *));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjList[i] = (int *)malloc(graph->numVertices * sizeof(int));
    }

    graph->adjList[0][1] = 1;
    graph->adjList[0][2] = 1;
    graph->adjList[1][2] = 1;
    graph->adjList[1][3] = 1;
    graph->adjList[2][3] = 1;
    graph->adjList[3][4] = 1;

    graphColoring(graph);

    return 0;
}