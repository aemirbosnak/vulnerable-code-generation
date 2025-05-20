//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

// Graph structure
typedef struct {
    int n; // number of nodes
    int m; // number of edges
    int *edges; // array of edges (source, destination, weight)
} Graph;

// Graph initialization
Graph* graph_init(int n, int m) {
    Graph* g = malloc(sizeof(Graph));
    g->n = n;
    g->m = m;
    g->edges = malloc(m * 3 * sizeof(int));
    return g;
}

// Graph traversal
void graph_traverse(Graph* g) {
    int i, j, k;
    for (i = 0; i < g->n; i++) {
        printf("%d: ", i);
        for (j = 0; j < g->m; j++) {
            k = g->edges[j * 3 + 1];
            if (k != -1) {
                printf(" -> %d (%d)", k, g->edges[j * 3 + 2]);
            }
        }
        printf("\n");
    }
}

// Graph addition
void graph_add_edge(Graph* g, int u, int v, int w) {
    int i, j;
    for (i = 0; i < g->m; i++) {
        if (g->edges[i * 3 + 0] == u && g->edges[i * 3 + 1] == v) {
            g->edges[i * 3 + 2] = w;
            return;
        }
    }
    g->edges = realloc(g->edges, (g->m + 1) * 3 * sizeof(int));
    g->edges[g->m * 3 + 0] = u;
    g->edges[g->m * 3 + 1] = v;
    g->edges[g->m * 3 + 2] = w;
    g->m++;
}

// Graph removal
void graph_remove_edge(Graph* g, int u, int v) {
    int i, j;
    for (i = 0; i < g->m; i++) {
        if (g->edges[i * 3 + 0] == u && g->edges[i * 3 + 1] == v) {
            for (j = i; j < g->m - 1; j++) {
                g->edges[j * 3 + 0] = g->edges[j * 3 + 2];
                g->edges[j * 3 + 1] = g->edges[j * 3 + 1];
                g->edges[j * 3 + 2] = -1;
            }
            g->m--;
            return;
        }
    }
}

int main() {
    Graph* g = graph_init(6, 8);
    graph_add_edge(g, 0, 1, 2);
    graph_add_edge(g, 0, 2, 3);
    graph_add_edge(g, 1, 3, 4);
    graph_add_edge(g, 2, 4, 5);
    graph_add_edge(g, 3, 5, 6);
    graph_add_edge(g, 4, 6, 7);
    graph_add_edge(g, 5, 7, 8);

    graph_traverse(g);

    return 0;
}