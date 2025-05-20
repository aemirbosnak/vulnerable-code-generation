//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices and colors
#define MAX_VERTICES 100
#define MAX_COLORS 10

// Create a graph data structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Create a coloring data structure
typedef struct Coloring {
    int num_colors;
    int colors[MAX_VERTICES];
} Coloring;

// Create a new graph
Graph *create_graph(int num_vertices, int num_edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Free the memory allocated for a graph
void free_graph(Graph *graph) {
    free(graph);
}

// Add an edge to a graph
void add_edge(Graph *graph, int v1, int v2) {
    graph->adj_matrix[v1][v2] = 1;
    graph->adj_matrix[v2][v1] = 1;
}

// Create a new coloring
Coloring *create_coloring(int num_colors) {
    Coloring *coloring = malloc(sizeof(Coloring));
    coloring->num_colors = num_colors;

    // Initialize the colors to 0
    for (int i = 0; i < MAX_VERTICES; i++) {
        coloring->colors[i] = 0;
    }

    return coloring;
}

// Free the memory allocated for a coloring
void free_coloring(Coloring *coloring) {
    free(coloring);
}

// Color a graph using a greedy algorithm
Coloring *greedy_coloring(Graph *graph) {
    Coloring *coloring = create_coloring(MAX_COLORS);

    // Iterate over the vertices in the graph
    for (int i = 0; i < graph->num_vertices; i++) {
        // Find the smallest available color for vertex i
        int color = 1;
        while (true) {
            bool available = true;
            // Check if the color is available for all adjacent vertices
            for (int j = 0; j < graph->num_vertices; j++) {
                if (graph->adj_matrix[i][j] == 1 && coloring->colors[j] == color) {
                    available = false;
                    break;
                }
            }

            if (available) {
                break;
            } else {
                color++;
            }
        }

        coloring->colors[i] = color;
    }

    return coloring;
}

// Check if a coloring is valid
bool is_valid_coloring(Graph *graph, Coloring *coloring) {
    // Iterate over the edges in the graph
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adj_matrix[i][j] == 1 && coloring->colors[i] == coloring->colors[j]) {
                return false;
            }
        }
    }

    return true;
}

// Print a coloring
void print_coloring(Coloring *coloring) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (coloring->colors[i] != 0) {
            printf("Vertex %d: Color %d\n", i, coloring->colors[i]);
        }
    }
}

// Main function
int main() {
    // Create a graph
    Graph *graph = create_graph(5, 6);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);

    // Color the graph using a greedy algorithm
    Coloring *coloring = greedy_coloring(graph);

    // Check if the coloring is valid
    if (is_valid_coloring(graph, coloring)) {
        printf("Valid coloring found:");
    } else {
        printf("No valid coloring found");
    }
    // Print the coloring
    print_coloring(coloring);

    // Free the allocated memory
    free_graph(graph);
    free_coloring(coloring);

    return 0;
}