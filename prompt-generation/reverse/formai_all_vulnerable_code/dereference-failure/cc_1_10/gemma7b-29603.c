//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 10

typedef struct Graph {
    int **adj;
    int V;
} Graph;

Graph* graph_create(int V) {
    Graph* g = malloc(sizeof(Graph));
    g->V = V;
    g->adj = malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        g->adj[i] = malloc(V * sizeof(int));
    }
    return g;
}

void graph_add_edge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
}

void graph_coloring(Graph* g) {
    int* color = malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        color[i] = -1;
    }

    int i = 0;
    for (int v = 0; v < g->V; v++) {
        int available = 1;
        for (int u = 0; u < g->V; u++) {
            if (g->adj[u][v] && color[u] == color[v]) {
                available = 0;
            }
        }
        color[v] = available ? i++ : -1;
    }

    int max_color = i;
    printf("The maximum number of colors is: %d\n", max_color);

    free(color);
}

int main() {
    Graph* g = graph_create(5);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);
    graph_add_edge(g, 4, 0);

    graph_coloring(g);

    return 0;
}