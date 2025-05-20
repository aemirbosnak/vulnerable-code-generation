//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Graph node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Graph edge structure
typedef struct edge {
    int src;
    int dest;
    int weight;
} edge_t;

// Graph structure
typedef struct graph {
    int num_nodes;
    int num_edges;
    node_t **nodes;
    edge_t **edges;
} graph_t;

// Function to create a new graph
graph_t *create_graph(int num_nodes, int num_edges) {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->nodes = (node_t **)malloc(sizeof(node_t *) * num_nodes);
    graph->edges = (edge_t **)malloc(sizeof(edge_t *) * num_edges);
    return graph;
}

// Function to add a node to a graph
void add_node(graph_t *graph, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    graph->nodes[graph->num_nodes++] = new_node;
}

// Function to add an edge to a graph
void add_edge(graph_t *graph, int src, int dest, int weight) {
    edge_t *new_edge = (edge_t *)malloc(sizeof(edge_t));
    new_edge->src = src;
    new_edge->dest = dest;
    new_edge->weight = weight;
    graph->edges[graph->num_edges++] = new_edge;
}

// Function to print a graph
void print_graph(graph_t *graph) {
    printf("Nodes:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d ", graph->nodes[i]->data);
    }
    printf("\nEdges:\n");
    for (int i = 0; i < graph->num_edges; i++) {
        printf("(%d, %d, %d) ", graph->edges[i]->src, graph->edges[i]->dest, graph->edges[i]->weight);
    }
    printf("\n");
}

// Function to free the memory allocated for a graph
void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    for (int i = 0; i < graph->num_edges; i++) {
        free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph);
}

// Main function
int main() {
    // Create a new graph
    graph_t *graph = create_graph(5, 6);

    // Add nodes to the graph
    add_node(graph, 0);
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);

    // Add edges to the graph
    add_edge(graph, 0, 1, 1);
    add_edge(graph, 0, 2, 2);
    add_edge(graph, 1, 2, 3);
    add_edge(graph, 1, 3, 4);
    add_edge(graph, 2, 3, 5);
    add_edge(graph, 3, 4, 6);

    // Print the graph
    print_graph(graph);

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}