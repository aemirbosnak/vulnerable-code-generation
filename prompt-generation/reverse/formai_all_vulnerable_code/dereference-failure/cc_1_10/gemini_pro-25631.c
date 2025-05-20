//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: relaxed
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
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        g->nodes[i] = NULL;
    }
    return g;
}

// Add a node to the graph
void add_node(graph *g, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    g->nodes[g->num_nodes++] = new_node;
}

// Add an edge to the graph
void add_edge(graph *g, int from, int to) {
    node *from_node = g->nodes[from];
    node *to_node = g->nodes[to];
    node *new_edge = (node *)malloc(sizeof(node));
    new_edge->data = to;
    new_edge->next = from_node->next;
    from_node->next = new_edge;
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *curr = g->nodes[i];
        printf("Node %d: ", i);
        while (curr != NULL) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Destroy the graph
void destroy_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *curr = g->nodes[i];
        while (curr != NULL) {
            node *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(g);
}

// Let's test our graph implementation!
int main() {
    graph *g = create_graph();
    add_node(g, 0);
    add_node(g, 1);
    add_node(g, 2);
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 0);
    print_graph(g);
    destroy_graph(g);
    return 0;
}