//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int vertices; // number of vertices
    int edges[10]; // array of edges (vertex indices)
} graph_t;

// Graph operations
void add_edge(graph_t* g, int v1, int v2) {
    if (g->vertices >= 10) {
        printf("Error: graph is full\n");
        return;
    }
    g->edges[g->vertices++] = v2;
}

int degree(graph_t* g, int v) {
    int deg = 0;
    for (int i = 0; i < g->vertices; i++) {
        if (g->edges[i] == v) deg++;
    }
    return deg;
}

void print_graph(graph_t* g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->edges[i]; j++) {
            printf(" %d", g->edges[i*10 + j]);
        }
        printf("\n");
    }
}

int main() {
    graph_t* g = malloc(sizeof(graph_t));
    g->vertices = 4;
    g->edges[0] = 1;
    g->edges[1] = 2;
    g->edges[2] = 3;
    g->edges[3] = 4;

    add_edge(g, 1, 3);
    add_edge(g, 2, 4);

    print_graph(g);

    return 0;
}