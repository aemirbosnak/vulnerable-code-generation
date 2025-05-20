//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    int num_nodes;
    node *nodes[MAX_NODES];
} graph;

// Create a new graph
graph *create_graph() {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        g->nodes[i] = NULL;
    }
    return g;
}

// Add a new node to the graph
void add_node(graph *g, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    g->nodes[g->num_nodes++] = new_node;
}

// Add an edge between two nodes in the graph
void add_edge(graph *g, int node1, int node2) {
    node *n1 = g->nodes[node1];
    node *n2 = g->nodes[node2];
    if (n1 == NULL || n2 == NULL) {
        return;
    }
    node *new_edge = malloc(sizeof(node));
    new_edge->data = node2;
    new_edge->next = n1->next;
    n1->next = new_edge;
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *n = g->nodes[i];
        printf("%d: ", n->data);
        while (n->next != NULL) {
            printf("%d ", n->next->data);
            n = n->next;
        }
        printf("\n");
    }
}

// Free the graph
void free_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *n = g->nodes[i];
        while (n != NULL) {
            node *next = n->next;
            free(n);
            n = next;
        }
    }
    free(g);
}

int main() {
    // Create a new graph
    graph *g = create_graph();

    // Add some nodes to the graph
    add_node(g, 0);
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);

    // Add some edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);

    // Print the graph
    print_graph(g);

    // Free the graph
    free_graph(g);

    return 0;
}