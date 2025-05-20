//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct graph {
    int vertices;
    int edges;
    int **adj;
} graph;

void create_graph(graph *g, int v, int e) {
    g->vertices = v;
    g->edges = e;
    g->adj = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++) {
        g->adj[i] = (int *)malloc(e * sizeof(int));
    }
}

void add_edge(graph *g, int v, int u, int w) {
    g->adj[v][g->edges] = u;
    g->adj[u][g->edges] = v;
    g->edges++;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("Vertex %d:\n", i);
        for (int j = 0; j < g->edges; j++) {
            printf("(%d, %d) -> %d\n", g->adj[i][j], j, g->adj[i][j]);
        }
    }
}

int main() {
    int v = 5, e = 10;
    graph g;
    create_graph(&g, v, e);

    add_edge(&g, 0, 1, 1);
    add_edge(&g, 0, 2, 2);
    add_edge(&g, 0, 3, 3);
    add_edge(&g, 0, 4, 4);
    add_edge(&g, 1, 2, 1);
    add_edge(&g, 1, 3, 1);
    add_edge(&g, 1, 4, 1);
    add_edge(&g, 2, 3, 1);
    add_edge(&g, 2, 4, 1);
    add_edge(&g, 3, 4, 1);

    print_graph(&g);

    return 0;
}