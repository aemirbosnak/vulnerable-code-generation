//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_COLORS 10

// Graph data structure
typedef struct graph {
    int num_nodes;
    int num_edges;
    int adj_matrix[MAX_NODES][MAX_NODES];
} graph_t;

// Node data structure
typedef struct node {
    int id;
    int color;
    int adj_list[MAX_NODES];
    int num_adj_nodes;
} node_t;

// Graph coloring data structure
typedef struct graph_coloring {
    graph_t graph;
    node_t nodes[MAX_NODES];
    int num_colors;
    int colors[MAX_COLORS];
} graph_coloring_t;

// Function to create a new graph
graph_t *create_graph(int num_nodes, int num_edges) {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;

    // Initialize the adjacency matrix
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to a graph
void add_edge(graph_t *graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
}

// Function to create a new node
node_t *create_node(int id) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->id = id;
    node->color = -1;
    node->num_adj_nodes = 0;

    return node;
}

// Function to add a neighbor to a node
void add_neighbor(node_t *node, int neighbor) {
    node->adj_list[node->num_adj_nodes] = neighbor;
    node->num_adj_nodes++;
}

// Function to create a new graph coloring
graph_coloring_t *create_graph_coloring(graph_t *graph, int num_colors) {
    graph_coloring_t *graph_coloring = (graph_coloring_t *)malloc(sizeof(graph_coloring_t));
    graph_coloring->graph = *graph;
    graph_coloring->num_colors = num_colors;

    // Initialize the colors array
    for (int i = 0; i < num_colors; i++) {
        graph_coloring->colors[i] = 0;
    }

    // Create the nodes
    for (int i = 0; i < graph->num_nodes; i++) {
        graph_coloring->nodes[i] = *create_node(i);
    }

    return graph_coloring;
}

// Function to check if a node is safe to color with a given color
int is_safe_to_color(graph_coloring_t *graph_coloring, node_t *node, int color) {
    // Check if any of the node's neighbors have the same color
    for (int i = 0; i < node->num_adj_nodes; i++) {
        node_t *neighbor = &graph_coloring->nodes[node->adj_list[i]];
        if (neighbor->color == color) {
            return 0;
        }
    }

    return 1;
}

// Recursive function to color a graph
int color_graph(graph_coloring_t *graph_coloring, int node_index) {
    // Base case: all nodes have been colored
    if (node_index == graph_coloring->graph.num_nodes) {
        return 1;
    }

    node_t *node = &graph_coloring->nodes[node_index];

    // Try all possible colors for the node
    for (int i = 0; i < graph_coloring->num_colors; i++) {
        // Check if it is safe to color the node with the current color
        if (is_safe_to_color(graph_coloring, node, graph_coloring->colors[i])) {
            // Color the node
            node->color = graph_coloring->colors[i];

            // Recursively color the remaining nodes
            if (color_graph(graph_coloring, node_index + 1)) {
                return 1;
            }

            // If the remaining nodes could not be colored, uncolor the node
            node->color = -1;
        }
    }

    return 0;
}

// Function to print the coloring of a graph
void print_graph_coloring(graph_coloring_t *graph_coloring) {
    for (int i = 0; i < graph_coloring->graph.num_nodes; i++) {
        node_t *node = &graph_coloring->nodes[i];
        printf("Node %d: color %d\n", node->id, node->color);
    }
}

// Main function
int main() {
    // Create a graph
    graph_t *graph = create_graph(4, 3);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);

    // Create a graph coloring
    graph_coloring_t *graph_coloring = create_graph_coloring(graph, 3);

    // Color the graph
    if (color_graph(graph_coloring, 0)) {
        // Print the coloring
        print_graph_coloring(graph_coloring);
    } else {
        printf("The graph cannot be colored with the given number of colors.\n");
    }

    return 0;
}