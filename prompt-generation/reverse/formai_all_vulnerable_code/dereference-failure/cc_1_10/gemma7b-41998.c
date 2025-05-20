//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 10

typedef struct Graph {
    int **adj;
    int **color;
    int numVertices;
} Graph;

void graphColor(Graph *g) {
    int i, j, k, color = 0;
    g->color = (int *)malloc(g->numVertices * sizeof(int));
    for (i = 0; i < g->numVertices; i++) {
        g->color[i] = -1;
    }
    for (i = 0; i < g->numVertices; i++) {
        for (j = 0; j < g->numVertices; j++) {
            if (g->adj[i][j] && g->color[i] == g->color[j]) {
                color = 0;
            }
        }
        if (color) {
            g->color[i] = color;
        } else {
            color++;
            g->color[i] = color;
        }
    }
}

int main() {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertices = MAX_V;
    g->adj = (int **)malloc(g->numVertices * sizeof(int *));
    for (int i = 0; i < g->numVertices; i++) {
        g->adj[i] = (int *)malloc(g->numVertices * sizeof(int));
    }
    g->adj[0][1] = 1;
    g->adj[1][2] = 1;
    g->adj[2][3] = 1;
    g->adj[3][4] = 1;
    g->adj[4][5] = 1;
    graphColor(g);
    printf("The coloring of the graph is:\n");
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertex %d has color %d\n", i, g->color[i]);
    }
    return 0;
}