//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

struct node {
    int id;
    char *name;
    int num_edges;
    int edges[MAX_EDGES];
};

struct graph {
    int num_nodes;
    struct node nodes[MAX_NODES];
};

struct graph *create_graph(int num_nodes) {
    struct graph *g = malloc(sizeof(struct graph));
    g->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        g->nodes[i].id = i;
        g->nodes[i].name = NULL;
        g->nodes[i].num_edges = 0;
    }
    return g;
}

void add_edge(struct graph *g, int node1, int node2) {
    g->nodes[node1].edges[g->nodes[node1].num_edges++] = node2;
    g->nodes[node2].edges[g->nodes[node2].num_edges++] = node1;
}

void print_graph(struct graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d (%s):", g->nodes[i].id, g->nodes[i].name);
        for (int j = 0; j < g->nodes[i].num_edges; j++) {
            printf(" %d", g->nodes[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    struct graph *g = create_graph(5);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    print_graph(g);

    return 0;
}