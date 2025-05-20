//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10
#define MAX_NODES 100

typedef struct {
    int num_nodes;
    int num_edges;
    int adj_matrix[MAX_NODES][MAX_NODES];
} Graph;

typedef struct {
    int num_colors;
    int colors[MAX_NODES];
} Coloring;

// Create a new graph with the given number of nodes and edges.
Graph* create_graph(int num_nodes, int num_edges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;

    // Initialize the adjacency matrix to 0.
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Add an edge to the graph.
void add_edge(Graph* graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
}

// Free the memory allocated for the graph.
void free_graph(Graph* graph) {
    free(graph);
}

// Create a new coloring with the given number of colors.
Coloring* create_coloring(int num_colors) {
    Coloring* coloring = malloc(sizeof(Coloring));
    coloring->num_colors = num_colors;

    // Initialize the colors array to 0.
    for (int i = 0; i < MAX_NODES; i++) {
        coloring->colors[i] = 0;
    }

    return coloring;
}

// Free the memory allocated for the coloring.
void free_coloring(Coloring* coloring) {
    free(coloring);
}

// Check if the given coloring is valid.
bool is_valid_coloring(Graph* graph, Coloring* coloring) {
    // Check if any two adjacent nodes have the same color.
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            if (graph->adj_matrix[i][j] == 1 && coloring->colors[i] == coloring->colors[j]) {
                return false;
            }
        }
    }

    return true;
}

// Find the minimum number of colors needed to color the graph.
int find_min_colors(Graph* graph) {
    // Start with 1 color.
    int num_colors = 1;

    // Increment the number of colors until a valid coloring is found.
    while (true) {
        Coloring* coloring = create_coloring(num_colors);
        if (is_valid_coloring(graph, coloring)) {
            free_coloring(coloring);
            return num_colors;
        }
        free_coloring(coloring);
        num_colors++;
    }
}

// Print the coloring to the console.
void print_coloring(Graph* graph, Coloring* coloring) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: Color %d\n", i, coloring->colors[i]);
    }
}

int main() {
    // Create a graph with 4 nodes and 5 edges.
    Graph* graph = create_graph(4, 5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    // Find the minimum number of colors needed to color the graph.
    int min_colors = find_min_colors(graph);

    // Create a coloring with the minimum number of colors.
    Coloring* coloring = create_coloring(min_colors);

    // Initialize the coloring using a greedy algorithm.
    int colors_available[MAX_COLORS];
    for (int i = 0; i < MAX_COLORS; i++) {
        colors_available[i] = true;
    }

    int assigned[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        assigned[i] = false;
    }

    for (int i = 0; i < graph->num_nodes; i++) {
        // If the node is not assigned a color, assign it the first available color.
        if (!assigned[i]) {
            for (int j = 0; j < MAX_COLORS; j++) {
                if (colors_available[j]) {
                    coloring->colors[i] = j;
                    assigned[i] = true;
                    colors_available[j] = false;
                    break;
                }
            }

            // If no colors are available, increment the number of colors and reinitialize the colors_available array.
            if (!colors_available[0]) {
                min_colors++;
                coloring->num_colors = min_colors;

                for (int j = 0; j < MAX_COLORS; j++) {
                    colors_available[j] = true;
                }

                // Reassign the colors to the nodes.
                for (int j = 0; j < graph->num_nodes; j++) {
                    assigned[j] = false;
                }

                for (int j = 0; j < graph->num_nodes; j++) {
                    if (!assigned[j]) {
                        for (int k = 0; k < MAX_COLORS; k++) {
                            if (colors_available[k]) {
                                coloring->colors[j] = k;
                                assigned[j] = true;
                                colors_available[k] = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        // Check if the coloring is valid.
        if (!is_valid_coloring(graph, coloring)) {
            printf("Error: The coloring is not valid.\n");
            return 1;
        }
    }

    // Print the coloring to the console.
    print_coloring(graph, coloring);

    // Free the memory allocated for the graph and coloring.
    free_graph(graph);
    free_coloring(coloring);

    return 0;
}