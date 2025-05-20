//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct {
    int num_vertices;
    int *edges;
} graph_t;

// Graph creation function
graph_t *create_graph(int n) {
    graph_t *g = malloc(sizeof(graph_t));
    g->num_vertices = n;
    g->edges = malloc(n * n * sizeof(int));
    return g;
}

// Graph traversal function
void traverse(graph_t *g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        printf("%d:", i);
        for (j = 0; j < g->edges[i]; j++) {
            printf(" %d", g->edges[i * g->num_vertices + j]);
        }
        printf("\n");
    }
}

// Graph addition function
void add_edge(graph_t *g, int v1, int v2) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        if (g->edges[i * g->num_vertices + v1] == 0) {
            g->edges[i * g->num_vertices + v1] = 1;
            g->edges[v1 * g->num_vertices + i] = 1;
            break;
        }
    }
}

int main() {
    graph_t *g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    traverse(g);
    return 0;
}