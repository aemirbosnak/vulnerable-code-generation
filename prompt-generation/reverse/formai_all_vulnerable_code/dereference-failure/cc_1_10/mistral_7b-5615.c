//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct {
    int vertex;
    int color;
    struct adj_list *next;
} edge;

typedef struct adj_list {
    int vertex;
    edge *next;
} adj_list;

typedef struct graph {
    int V;
    int E;
    adj_list **adj;
} graph;

void add_edge(graph *g, int u, int v) {
    edge *e = (edge *) malloc(sizeof(edge));
    e->vertex = v;
    e->color = -1;
    e->next = g->adj[u];
    g->adj[u] = e;

    edge *f = (edge *) malloc(sizeof(edge));
    f->vertex = u;
    f->color = -1;
    f->next = g->adj[v];
    g->adj[v] = f;

    g->E++;
}

bool is_safe(graph *g, int v, int c) {
    for (edge *e = g->adj[v]; e != NULL; e = e->next) {
        if (e->color == c)
            return false;
    }

    return true;
}

bool graph_coloring_util(graph *g, int m, int v, int color[]) {
    if (v == g->V) {
        return true;
    }

    for (int c = 0; c < m; c++) {
        if (is_safe(g, v, c)) {
            color[v] = c;
            if (graph_coloring_util(g, m, v + 1, color))
                return true;
            color[v] = -1;
        }
    }

    return false;
}

bool graph_coloring(graph *g, int m) {
    int *color = (int *) calloc(g->V, sizeof(int));

    if (graph_coloring_util(g, m, 0, color)) {
        for (int i = 0; i < g->V; i++)
            printf("Vertex %d is colored with %d\n", i, color[i]);
        free(color);
        return true;
    }

    free(color);
    return false;
}

int main() {
    int V = 5, E = 6, m;
    graph *g = (graph *) malloc(sizeof(graph));
    g->V = V;
    g->E = E;
    g->adj = (adj_list **) calloc(V, sizeof(adj_list *));

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 1);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    m = 3;

    if (graph_coloring(g, m))
        return 0;

    printf("Graph cannot be colored with %d colors\n", m);

    return 0;
}