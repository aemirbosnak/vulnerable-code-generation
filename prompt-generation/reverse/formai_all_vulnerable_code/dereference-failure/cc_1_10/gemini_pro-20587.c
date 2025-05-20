//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of nodes in the graph
#define MAX_NODES 100

// Define the maximum number of edges in the graph
#define MAX_EDGES 1000

// Define the data structure for a node in the graph
typedef struct node {
    int value;
    struct node *next;
} node;

// Define the data structure for an edge in the graph
typedef struct edge {
    int weight;
    struct node *source;
    struct node *destination;
} edge;

// Define the data structure for the graph
typedef struct graph {
    int num_nodes;
    int num_edges;
    node *nodes[MAX_NODES];
    edge *edges[MAX_EDGES];
} graph;

// Create a new graph
graph *create_graph() {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = 0;
    g->num_edges = 0;
    return g;
}

// Add a node to the graph
void add_node(graph *g, int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    g->nodes[g->num_nodes++] = n;
}

// Add an edge to the graph
void add_edge(graph *g, int source, int destination, int weight) {
    edge *e = malloc(sizeof(edge));
    e->weight = weight;
    e->source = g->nodes[source];
    e->destination = g->nodes[destination];
    g->edges[g->num_edges++] = e;
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *n = g->nodes[i];
        printf("Node %d: ", n->value);
        while (n->next != NULL) {
            printf("%d -> ", n->next->value);
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
    for (int i = 0; i < g->num_edges; i++) {
        edge *e = g->edges[i];
        free(e);
    }
    free(g);
}

// Main function
int main() {
    // Create a new graph
    graph *g = create_graph();

    // Add some nodes to the graph
    for (int i = 0; i < 10; i++) {
        add_node(g, i);
    }

    // Add some edges to the graph
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            add_edge(g, i, j, rand() % 10);
        }
    }

    // Print the graph
    print_graph(g);

    // Free the graph
    free_graph(g);

    return 0;
}