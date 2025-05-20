//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10
#define MAX_NODES 100

// Graph data structure
typedef struct Graph {
    int num_nodes;
    int num_edges;
    int adj_matrix[MAX_NODES][MAX_NODES];
    int colors[MAX_NODES];
} Graph;

// Function to create a new graph
Graph* create_graph(int num_nodes, int num_edges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;

    // Initialize the adjacency matrix to zero
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    // Initialize the colors array to -1
    for (int i = 0; i < num_nodes; i++) {
        graph->colors[i] = -1;
    }

    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
}

// Function to check if the graph is colorable
bool is_colorable(Graph* graph) {
    // Initialize the color array to -1
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->colors[i] = -1;
    }

    // Try to color the graph with each color
    for (int color = 0; color < MAX_COLORS; color++) {
        // Try to color each node with the current color
        for (int node = 0; node < graph->num_nodes; node++) {
            // Check if the node is already colored
            if (graph->colors[node] != -1) {
                continue;
            }

            // Check if the node can be colored with the current color
            bool can_color = true;
            for (int neighbor = 0; neighbor < graph->num_nodes; neighbor++) {
                // If the neighbor is adjacent to the node and has the same color, then the node cannot be colored with the current color
                if (graph->adj_matrix[node][neighbor] == 1 && graph->colors[neighbor] == color) {
                    can_color = false;
                    break;
                }
            }

            // If the node can be colored with the current color, then color it
            if (can_color) {
                graph->colors[node] = color;
            }
        }

        // If all the nodes have been colored, then the graph is colorable
        bool all_colored = true;
        for (int node = 0; node < graph->num_nodes; node++) {
            if (graph->colors[node] == -1) {
                all_colored = false;
            }
        }

        if (all_colored) {
            return true;
        }
    }

    // If the graph cannot be colored with any color, then it is not colorable
    return false;
}

// Main function
int main() {
    // Create a new graph
    Graph* graph = create_graph(4, 3);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);

    // Check if the graph is colorable
    if (is_colorable(graph)) {
        printf("The graph is colorable\n");
    } else {
        printf("The graph is not colorable\n");
    }

    // Print the colors of the nodes
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d has color %d\n", i, graph->colors[i]);
    }

    return 0;
}