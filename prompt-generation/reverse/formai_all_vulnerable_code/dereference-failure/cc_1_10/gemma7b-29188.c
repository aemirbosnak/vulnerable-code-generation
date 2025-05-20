//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100

typedef struct Graph {
    int **adj;
    int numVertices;
} Graph;

Graph* graphCreate(int numVertices) {
    Graph* g = malloc(sizeof(Graph));
    g->numVertices = numVertices;
    g->adj = malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        g->adj[i] = malloc(numVertices * sizeof(int));
    }
    return g;
}

void graphAddEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
}

int graphColor(Graph* g) {
    int* color = malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        color[i] = -1;
    }
    int chromaticNumber = 0;
    for (int i = 0; i < g->numVertices; i++) {
        int available = 1;
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adj[i][j] && color[j] != -1) {
                if (color[j] == color[i]) {
                    available = 0;
                }
            }
        }
        if (available) {
            color[i] = chromaticNumber++;
        }
    }
    return chromaticNumber;
}

int main() {
    Graph* g = graphCreate(5);
    graphAddEdge(g, 0, 1);
    graphAddEdge(g, 0, 2);
    graphAddEdge(g, 1, 2);
    graphAddEdge(g, 2, 3);
    graphAddEdge(g, 3, 4);
    graphAddEdge(g, 4, 0);

    int chromaticNumber = graphColor(g);

    printf("Chromatic number of the graph: %d\n", chromaticNumber);

    return 0;
}