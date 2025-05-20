//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10
#define MAX_VERTICES 100

// Graph data structure
typedef struct graph {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} graph_t;

// Graph coloring result data structure
typedef struct coloring {
    int colors[MAX_VERTICES];
} coloring_t;

// Function to create a new graph
graph_t *create_graph(int num_vertices, int num_edges) {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
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
void add_edge(graph_t *graph, int vertex1, int vertex2) {
    graph->adj_matrix[vertex1][vertex2] = 1;
    graph->adj_matrix[vertex2][vertex1] = 1;
}

// Function to print a graph
void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to create a new coloring
coloring_t *create_coloring(int num_vertices) {
    coloring_t *coloring = (coloring_t *)malloc(sizeof(coloring_t));
    for (int i = 0; i < num_vertices; i++) {
        coloring->colors[i] = -1;
    }

    return coloring;
}

// Function to check if a coloring is valid
bool is_valid_coloring(graph_t *graph, coloring_t *coloring) {
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
void print_coloring(graph_t *graph, coloring_t *coloring) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, coloring->colors[i]);
    }
}

// Function to find a valid coloring for a graph
coloring_t *graph_coloring(graph_t *graph) {
    // Create a new coloring
    coloring_t *coloring = create_coloring(graph->num_vertices);

    // Initialize the colors to -1
    for (int i = 0; i < graph->num_vertices; i++) {
        coloring->colors[i] = -1;
    }

    // Start coloring from the first vertex
    int vertex = 0;
    int color = 0;
    while (vertex < graph->num_vertices) {
        // Try all colors for the current vertex
        while (color < MAX_COLORS) {
            // Check if the color is valid for the current vertex
            bool valid = true;
            for (int i = 0; i < graph->num_vertices; i++) {
                if (graph->adj_matrix[vertex][i] == 1 && coloring->colors[i] == color) {
                    valid = false;
                }
            }

            // If the color is valid, assign it to the current vertex
            if (valid) {
                coloring->colors[vertex] = color;
                break;
            }

            // Increment the color
            color++;
        }

        // If no valid color was found for the current vertex, backtrack
        if (color == MAX_COLORS) {
            color = coloring->colors[vertex];
            vertex--;
        }

        // Increment the vertex
        vertex++;
        color = 0;
    }

    // Return the coloring
    return coloring;
}

// Main function
int main() {
    // Create a new graph
    graph_t *graph = create_graph(4, 3);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);

    // Print the graph
    print_graph(graph);

    // Find a valid coloring for the graph
    coloring_t *coloring = graph_coloring(graph);

    // Print the coloring
    print_coloring(graph, coloring);

    return 0;
}