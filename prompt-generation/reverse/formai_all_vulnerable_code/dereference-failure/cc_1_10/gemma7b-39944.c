//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Graph {
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

void graphColoring(Graph *graph) {
    int i, j, k;
    int *color = (int *)malloc(graph->numVertices * sizeof(int));
    for (i = 0; i < graph->numVertices; i++) {
        color[i] = -1;
    }
    for (i = 0; i < graph->numEdges; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && color[j] == -1) {
                for (k = 0; k < graph->numVertices; k++) {
                    if (graph->adjList[i][k] && color[k] != -1 && color[k] == color[j]) {
                        color[j] = -1;
                    }
                }
            }
        }
    }
    for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d has color %d\n", i, color[i]);
    }
    free(color);
}

int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->numEdges = 5;
    graph->adjList = (int **)malloc(graph->numVertices * sizeof(int *));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjList[i] = (int *)malloc(graph->numVertices * sizeof(int));
    }
    graph->adjList[0][1] = 1;
    graph->adjList[0][2] = 1;
    graph->adjList[1][2] = 1;
    graph->adjList[2][3] = 1;
    graph->adjList[3][4] = 1;
    graphColoring(graph);
    return 0;
}