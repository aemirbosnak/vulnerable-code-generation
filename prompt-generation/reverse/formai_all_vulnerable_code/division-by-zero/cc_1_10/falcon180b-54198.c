//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_COLORS 10

typedef struct {
    int node;
    int color;
} Edge;

typedef struct {
    int n;
    int m;
    int *color;
    Edge *graph;
} Graph;

void create_graph(Graph *g) {
    int i, j, k;
    srand(time(NULL));
    g->n = rand() % MAX_NODES + 1;
    g->m = rand() % (g->n * (g->n - 1) / 2) + 1;
    g->color = (int *)malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++) {
        g->color[i] = rand() % MAX_COLORS;
    }
    g->graph = (Edge *)malloc(g->m * sizeof(Edge));
    for (i = 0; i < g->m; i++) {
        g->graph[i].node = rand() % g->n;
        g->graph[i].color = rand() % MAX_COLORS;
    }
}

int is_valid_color(Graph *g, int node, int color) {
    int i;
    for (i = 0; i < g->n; i++) {
        if (i!= node && g->color[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(Graph *g, int node, int color) {
    g->color[node] = color;
}

int color_graph(Graph *g) {
    int i, j;
    for (i = 0; i < g->n; i++) {
        g->color[i] = rand() % MAX_COLORS;
    }
    for (i = 0; i < g->m; i++) {
        if (!is_valid_color(g, g->graph[i].node, g->graph[i].color)) {
            return 0;
        }
        color_node(g, g->graph[i].node, g->graph[i].color);
    }
    return 1;
}

int main() {
    Graph g;
    int i, j;
    create_graph(&g);
    if (color_graph(&g)) {
        printf("Graph colored successfully!\n");
        for (i = 0; i < g.n; i++) {
            printf("Node %d is colored %d\n", i, g.color[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", g.m);
    }
    return 0;
}