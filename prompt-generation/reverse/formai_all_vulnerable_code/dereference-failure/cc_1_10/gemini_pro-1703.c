//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node_struct {
    int data;
    struct node_struct *next;
} node;

typedef struct graph_struct {
    int num_nodes;
    node **nodes;
    bool **adj_matrix;
} graph;

graph *create_graph(int num_nodes) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->nodes = (node **)malloc(sizeof(node *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        g->nodes[i] = NULL;
    }
    g->adj_matrix = (bool **)malloc(sizeof(bool *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        g->adj_matrix[i] = (bool *)malloc(sizeof(bool) * num_nodes);
        for (int j = 0; j < num_nodes; j++) {
            g->adj_matrix[i][j] = false;
        }
    }
    return g;
}

void add_edge(graph *g, int source, int destination) {
    g->adj_matrix[source][destination] = true;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d:\n", i);
        for (int j = 0; j < g->num_nodes; j++) {
            if (g->adj_matrix[i][j]) {
                printf("  - %d\n", j);
            }
        }
    }
}

int main() {
    graph *g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);
    print_graph(g);
    return 0;
}