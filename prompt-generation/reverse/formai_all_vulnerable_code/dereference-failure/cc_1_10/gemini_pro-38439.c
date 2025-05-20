//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    int num_nodes;
    node *nodes[MAX_NODES];
} graph;

graph *create_graph() {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        g->nodes[i] = NULL;
    }
    return g;
}

void add_node(graph *g, int data) {
    if (g->num_nodes >= MAX_NODES) {
        printf("Error: cannot add more nodes to graph.\n");
        return;
    }

    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    g->nodes[g->num_nodes++] = new_node;
}

void add_edge(graph *g, int source, int destination) {
    if (source >= g->num_nodes || destination >= g->num_nodes) {
        printf("Error: invalid source or destination node.\n");
        return;
    }

    node *new_edge = malloc(sizeof(node));
    new_edge->data = destination;
    new_edge->next = g->nodes[source]->next;

    g->nodes[source]->next = new_edge;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: ", i);
        node *current = g->nodes[i];
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    graph *g = create_graph();

    add_node(g, 0);
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    print_graph(g);

    return 0;
}