//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_COLORS 3

typedef struct {
    int num_nodes;
    int num_edges;
    int **adj_matrix;
} Graph;

Graph *create_graph(int num_nodes, int num_edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->adj_matrix = malloc(sizeof(int *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_nodes);
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

void destroy_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

bool is_valid_coloring(Graph *graph, int *coloring) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = i + 1; j < graph->num_nodes; j++) {
            if (graph->adj_matrix[i][j] == 1 && coloring[i] == coloring[j]) {
                return false;
            }
        }
    }
    return true;
}

int count_valid_colorings(Graph *graph) {
    int num_valid_colorings = 0;
    int *coloring = malloc(sizeof(int) * graph->num_nodes);

    // Try all possible combinations of colors for the first node
    for (int i = 0; i < NUM_COLORS; i++) {
        coloring[0] = i;

        // Recursively try all possible combinations of colors for the remaining nodes
        num_valid_colorings += count_valid_colorings_helper(graph, coloring, 1);
    }

    free(coloring);
    return num_valid_colorings;
}

int count_valid_colorings_helper(Graph *graph, int *coloring, int node_index) {
    if (node_index == graph->num_nodes) {
        // If all nodes have been colored, check if the coloring is valid
        if (is_valid_coloring(graph, coloring)) {
            return 1;
        } else {
            return 0;
        }
    }

    int num_valid_colorings = 0;

    // Try all possible colors for the current node
    for (int i = 0; i < NUM_COLORS; i++) {
        coloring[node_index] = i;

        // Recursively try all possible combinations of colors for the remaining nodes
        num_valid_colorings += count_valid_colorings_helper(graph, coloring, node_index + 1);
    }

    return num_valid_colorings;
}

int main() {
    // Create a graph
    Graph *graph = create_graph(4, 5);
    graph->adj_matrix[0][1] = 1;
    graph->adj_matrix[0][2] = 1;
    graph->adj_matrix[1][2] = 1;
    graph->adj_matrix[1][3] = 1;
    graph->adj_matrix[2][3] = 1;

    // Count the number of valid colorings for the graph
    int num_valid_colorings = count_valid_colorings(graph);

    // Print the number of valid colorings
    printf("Number of valid colorings: %d\n", num_valid_colorings);

    // Destroy the graph
    destroy_graph(graph);

    return 0;
}