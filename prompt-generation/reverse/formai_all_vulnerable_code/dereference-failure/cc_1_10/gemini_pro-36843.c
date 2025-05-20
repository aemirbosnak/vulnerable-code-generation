//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10
#define MAX_VERTICES 100

// Graph representation
typedef struct graph {
    int num_vertices;
    int num_edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} graph_t;

// Coloring representation
typedef struct coloring {
    int num_colors;
    int colors[MAX_VERTICES];
} coloring_t;

// Function to create a new graph
graph_t* create_graph(int num_vertices, int num_edges) {
    graph_t* graph = (graph_t*)malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to a graph
void add_edge(graph_t* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

// Function to create a new coloring
coloring_t* create_coloring(int num_colors) {
    coloring_t* coloring = (coloring_t*)malloc(sizeof(coloring_t));
    coloring->num_colors = num_colors;

    // Initialize colors to -1 (uncolored)
    for (int i = 0; i < MAX_VERTICES; i++) {
        coloring->colors[i] = -1;
    }

    return coloring;
}

// Function to color a graph using the greedy algorithm
bool greedy_coloring(graph_t* graph, coloring_t* coloring) {
    // Initialize colors to -1 (uncolored)
    for (int i = 0; i < graph->num_vertices; i++) {
        coloring->colors[i] = -1;
    }

    // Iterate over vertices in ascending order
    for (int i = 0; i < graph->num_vertices; i++) {
        // Get available colors for vertex i
        int available_colors[MAX_COLORS];
        int num_available_colors = 0;
        for (int j = 0; j < coloring->num_colors; j++) {
            bool color_available = true;
            for (int k = 0; k < graph->num_vertices; k++) {
                if (graph->adjacency_matrix[i][k] == 1 && coloring->colors[k] == j) {
                    color_available = false;
                    break;
                }
            }
            if (color_available) {
                available_colors[num_available_colors++] = j;
            }
        }

        // If there are no available colors, return false
        if (num_available_colors == 0) {
            return false;
        }

        // Assign the first available color to vertex i
        coloring->colors[i] = available_colors[0];
    }

    return true;
}

// Function to print a coloring
void print_coloring(coloring_t* coloring) {
    printf("Colors:");
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (coloring->colors[i] != -1) {
            printf(" %d", coloring->colors[i]);
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Create a graph
    graph_t* graph = create_graph(5, 6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Create a coloring
    coloring_t* coloring = create_coloring(3);

    // Color the graph
    bool colored = greedy_coloring(graph, coloring);

    // Print the coloring
    if (colored) {
        print_coloring(coloring);
    } else {
        printf("The graph cannot be colored with %d colors.\n", coloring->num_colors);
    }

    return 0;
}