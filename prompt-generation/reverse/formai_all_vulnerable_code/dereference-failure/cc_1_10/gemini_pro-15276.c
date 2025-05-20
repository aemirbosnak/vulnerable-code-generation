//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph data structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Graph coloring data structure
typedef struct Coloring {
    int num_colors;
    int colors[MAX_VERTICES];
} Coloring;

// Function to create a new graph
Graph *create_graph(int num_vertices, int num_edges) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
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

// Function to add an edge to a graph
void add_edge(Graph *graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
}

// Function to create a new coloring
Coloring *create_coloring(int num_colors) {
    Coloring *coloring = (Coloring *)malloc(sizeof(Coloring));
    coloring->num_colors = num_colors;

    // Initialize the colors array to 0
    for (int i = 0; i < MAX_VERTICES; i++) {
        coloring->colors[i] = 0;
    }

    return coloring;
}

// Function to check if a coloring is valid
bool is_valid_coloring(Graph *graph, Coloring *coloring) {
    // Check if any two adjacent vertices have the same color
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = i + 1; j < graph->num_vertices; j++) {
            if (graph->adj_matrix[i][j] == 1 && coloring->colors[i] == coloring->colors[j]) {
                return false;
            }
        }
    }

    return true;
}

// Function to print a coloring
void print_coloring(Coloring *coloring) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("Vertex %d: Color %d\n", i, coloring->colors[i]);
    }
}

// Function to find all valid colorings of a graph
void find_all_colorings(Graph *graph, Coloring *coloring, int num_assigned) {
    // Check if all vertices have been assigned a color
    if (num_assigned == graph->num_vertices) {
        // Check if the coloring is valid
        if (is_valid_coloring(graph, coloring)) {
            // Print the coloring
            print_coloring(coloring);
        }

        return;
    }

    // Try all possible colors for the next vertex
    for (int color = 1; color <= coloring->num_colors; color++) {
        // Assign the color to the next vertex
        coloring->colors[num_assigned] = color;

        // Recursively find all valid colorings for the remaining vertices
        find_all_colorings(graph, coloring, num_assigned + 1);
    }
}

int main() {
    // Create a graph with 4 vertices and 5 edges
    Graph *graph = create_graph(4, 5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    // Create a coloring with 3 colors
    Coloring *coloring = create_coloring(3);

    // Find all valid colorings of the graph
    find_all_colorings(graph, coloring, 0);

    return 0;
}