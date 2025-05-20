//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a node in the graph
typedef struct node {
    int value;
    struct node *next;
} node_t;

// Define a graph as an array of nodes
typedef struct graph {
    int num_nodes;
    node_t **nodes;
} graph_t;

// Create a new graph
graph_t *create_graph(int num_nodes) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_nodes = num_nodes;
    graph->nodes = malloc(sizeof(node_t *) * num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = NULL;
    }

    return graph;
}

// Add an edge to the graph
void add_edge(graph_t *graph, int node1, int node2) {
    // Create a new node for node1
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = node2;
    new_node->next = graph->nodes[node1];

    // Add the new node to the adjacency list for node1
    graph->nodes[node1] = new_node;
}

// Print the graph
void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        node_t *node = graph->nodes[i];
        printf("%d: ", i);
        while (node != NULL) {
            printf("%d -> ", node->value);
            node = node->next;
        }
        printf("\n");
    }
}

// Free the graph
void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        node_t *node = graph->nodes[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node);
            node = next;
        }
    }

    free(graph->nodes);
    free(graph);
}

int main() {
    // Create a new graph
    graph_t *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    // Free the graph
    free_graph(graph);

    return 0;
}