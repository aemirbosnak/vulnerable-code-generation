//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 100

typedef struct Graph {
    int **adj;
    int numVertices;
} Graph;

void graphColoring(Graph *graph) {
    int **color = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = -1;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->adj[i][0]; j++) {
            if (color[graph->adj[i][j]] != -1) {
                if (color[graph->adj[i][j]] == color[i]) {
                    printf("Graph coloring failed.\n");
                    return;
                }
            }
        }
        color[i] = 0;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d colored with color %d.\n", i, color[i]);
    }
    printf("Graph coloring complete.\n");
}

int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adj = (int **)malloc(graph->numVertices * sizeof(int *));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adj[i] = (int *)malloc(sizeof(int *) * 2);
    }

    graph->adj[0][0] = 1;
    graph->adj[0][1] = 2;
    graph->adj[1][0] = 0;
    graph->adj[1][1] = 3;
    graph->adj[2][0] = 1;
    graph->adj[2][1] = 3;
    graph->adj[3][0] = 2;
    graph->adj[3][1] = 4;
    graph->adj[4][0] = 3;
    graph->adj[4][1] = 4;

    graphColoring(graph);

    return 0;
}