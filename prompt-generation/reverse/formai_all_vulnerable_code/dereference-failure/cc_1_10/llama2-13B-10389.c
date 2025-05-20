//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define GRAPH_MAX_NODES 1024
#define GRAPH_MAX_EDGES 1024

typedef struct {
    int nodes;
    int edges;
    int *adjacency_list;
} graph_t;

void graph_init(graph_t *g, int nodes, int edges) {
    g->nodes = nodes;
    g->edges = edges;
    g->adjacency_list = calloc(nodes, sizeof(int));
}

void graph_add_node(graph_t *g, int node) {
    if (g->nodes >= GRAPH_MAX_NODES) {
        printf("Error: Graph has reached maximum size\n");
        return;
    }
    g->nodes++;
    g->adjacency_list[node] = g->edges;
    g->edges += 2;
}

void graph_add_edge(graph_t *g, int node1, int node2) {
    if (g->edges >= GRAPH_MAX_EDGES) {
        printf("Error: Graph has reached maximum size\n");
        return;
    }
    g->adjacency_list[node1]++;
    g->adjacency_list[node2]++;
    g->edges++;
}

void graph_print(graph_t *g) {
    int i, j;
    for (i = 0; i < g->nodes; i++) {
        printf("%d: ", i);
        for (j = 0; j < g->adjacency_list[i]; j++) {
            printf("%d ", g->adjacency_list[i * GRAPH_MAX_EDGES + j]);
        }
        printf("\n");
    }
}

int main() {
    graph_t g;
    graph_init(&g, 10, 20);
    graph_add_node(&g, 1);
    graph_add_node(&g, 2);
    graph_add_node(&g, 3);
    graph_add_edge(&g, 1, 2);
    graph_add_edge(&g, 1, 3);
    graph_add_edge(&g, 2, 3);
    graph_print(&g);
    return 0;
}