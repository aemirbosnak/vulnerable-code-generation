//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct {
    int num_vertices;
    int *edges;
} graph_t;

// Graph operations
graph_t *graph_create(int num_vertices) {
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->num_vertices = num_vertices;
    g->edges = (int *)malloc(num_vertices * sizeof(int));
    return g;
}

void graph_add_edge(graph_t *g, int v1, int v2) {
    g->edges[v1] = v2;
}

int graph_get_edge(graph_t *g, int v1, int v2) {
    return g->edges[v1];
}

void graph_free(graph_t *g) {
    free(g->edges);
    free(g);
}

// Graph traversal
void graph_traverse(graph_t *g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        printf("Vertice %d:", i);
        for (j = 0; j < g->edges[i]; j++) {
            printf(" %d", g->edges[i * g->num_vertices + j]);
        }
        printf("\n");
    }
}

int main() {
    graph_t *g = graph_create(5);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);
    graph_traverse(g);
    graph_free(g);
    return 0;
}