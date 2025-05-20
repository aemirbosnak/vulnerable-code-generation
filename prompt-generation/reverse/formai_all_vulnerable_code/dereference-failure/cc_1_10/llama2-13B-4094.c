//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Graph structure
typedef struct node {
    int label; // node label
    struct node *next; // next node in the graph
    struct node *prev; // previous node in the graph
    int weight; // edge weight
} Node;

// Graph representation
typedef struct graph {
    Node *nodes; // array of nodes
    int num_nodes; // number of nodes in the graph
    int num_edges; // number of edges in the graph
} Graph;

// Function to create a new graph
Graph *create_graph(int size) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->nodes = (Node *) malloc(size * sizeof(Node));
    g->num_nodes = size;
    g->num_edges = 0;
    return g;
}

// Function to add a node to the graph
void add_node(Graph *g, int label) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->label = label;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->weight = 0;
    if (g->num_nodes == 0) {
        g->nodes[0] = *new_node;
        g->num_nodes = 1;
    } else {
        g->nodes[g->num_nodes] = *new_node;
        g->num_nodes++;
    }
}

// Function to add an edge to the graph
void add_edge(Graph *g, int from, int to, int weight) {
    Node *from_node = g->nodes + from;
    Node *to_node = g->nodes + to;
    from_node->weight = weight;
    to_node->prev = from_node;
    from_node->next = to_node;
    g->num_edges++;
}

// Function to print the graph
void print_graph(Graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        Node *node = g->nodes + i;
        printf("Node %d: label %d, weight %d\n", i, node->label, node->weight);
        if (node->next != NULL) {
            print_graph(node->next);
        }
    }
}

int main() {
    // Create a new graph
    Graph *g = create_graph(5);

    // Add some nodes
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);
    add_node(g, 5);

    // Add some edges
    add_edge(g, 1, 2, 10);
    add_edge(g, 1, 3, 20);
    add_edge(g, 2, 4, 30);
    add_edge(g, 3, 4, 40);
    add_edge(g, 4, 5, 50);

    // Print the graph
    print_graph(g);

    return 0;
}