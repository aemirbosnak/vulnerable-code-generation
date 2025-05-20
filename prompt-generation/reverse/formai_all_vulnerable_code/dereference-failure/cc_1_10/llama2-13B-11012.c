//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct {
    int num_vertices;
    int *edges;
} graph_t;

// Graph functions
graph_t *create_graph(int n) {
    graph_t *g = malloc(sizeof(graph_t));
    g->num_vertices = n;
    g->edges = malloc(n * n * sizeof(int));
    return g;
}

void add_edge(graph_t *g, int v1, int v2) {
    g->edges[v1 * g->num_vertices + v2] = 1;
}

int degree(graph_t *g, int v) {
    int deg = 0;
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->edges[v * g->num_vertices + i]) {
            deg++;
        }
    }
    return deg;
}

void print_graph(graph_t *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->edges[i * g->num_vertices + j]) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

int main() {
    graph_t *g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    print_graph(g);
    return 0;
}