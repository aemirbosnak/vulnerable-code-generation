//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>

// A node in a graph
typedef struct node {
    int value;
    struct node *next;
} node_t;

// A graph
typedef struct graph {
    int num_nodes;
    node_t *nodes;
} graph_t;

// Create a new graph
graph_t *create_graph() {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_nodes = 0;
    graph->nodes = NULL;
    return graph;
}

// Add a node to a graph
void add_node(graph_t *graph, int value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = graph->nodes;
    graph->nodes = new_node;
    graph->num_nodes++;
}

// Print a graph
void print_graph(graph_t *graph) {
    node_t *current = graph->nodes;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Free a graph
void free_graph(graph_t *graph) {
    node_t *current = graph->nodes;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(graph);
}

// A decentralized data structure
typedef struct dds {
    graph_t *graph;
    int num_nodes;
} dds_t;

// Create a new decentralized data structure
dds_t *create_dds() {
    dds_t *dds = malloc(sizeof(dds_t));
    dds->graph = create_graph();
    dds->num_nodes = 0;
    return dds;
}

// Add a node to a decentralized data structure
void add_node_to_dds(dds_t *dds, int value) {
    add_node(dds->graph, value);
    dds->num_nodes++;
}

// Print a decentralized data structure
void print_dds(dds_t *dds) {
    print_graph(dds->graph);
}

// Free a decentralized data structure
void free_dds(dds_t *dds) {
    free_graph(dds->graph);
    free(dds);
}

// Example usage
int main() {
    dds_t *dds = create_dds();
    add_node_to_dds(dds, 1);
    add_node_to_dds(dds, 2);
    add_node_to_dds(dds, 3);
    print_dds(dds);
    free_dds(dds);
    return 0;
}