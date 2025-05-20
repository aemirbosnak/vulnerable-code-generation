//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10
#define MAX_VERTICES 100

// Graph data structure
typedef struct graph {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} graph_t;

// Graph coloring data structure
typedef struct coloring {
    int num_colors;
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

// Function to create a new coloring
coloring_t *create_coloring(int num_vertices) {
    coloring_t *coloring = (coloring_t *)malloc(sizeof(coloring_t));
    coloring->num_colors = 0;

    // Initialize the colors array to -1
    for (int i = 0; i < num_vertices; i++) {
        coloring->colors[i] = -1;
    }

    return coloring;
}

// Function to color a graph
coloring_t *color_graph(graph_t *graph) {
    // Create a new coloring
    coloring_t *coloring = create_coloring(graph->num_vertices);

    // Initialize the current color to 0
    int current_color = 0;

    // Loop over the vertices in the graph
    for (int i = 0; i < graph->num_vertices; i++) {
        // If the vertex is not already colored
        if (coloring->colors[i] == -1) {
            // Color the vertex with the current color
            coloring->colors[i] = current_color;

            // Increment the current color
            current_color++;
        }

        // Loop over the adjacent vertices
        for (int j = 0; j < graph->num_vertices; j++) {
            // If the adjacent vertex is not already colored
            if (coloring->colors[j] == -1) {
                // If the adjacent vertex is connected to the current vertex
                if (graph->adj_matrix[i][j] == 1) {
                    // Check if the adjacent vertex can be colored with the current color
                    int can_color = 1;
                    for (int k = 0; k < graph->num_vertices; k++) {
                        // If the adjacent vertex is connected to a vertex that is already colored with the current color
                        if (graph->adj_matrix[j][k] == 1 && coloring->colors[k] == current_color) {
                            // The adjacent vertex cannot be colored with the current color
                            can_color = 0;
                            break;
                        }
                    }

                    // If the adjacent vertex can be colored with the current color
                    if (can_color == 1) {
                        // Color the adjacent vertex with the current color
                        coloring->colors[j] = current_color;
                    }
                }
            }
        }
    }

    return coloring;
}

// Function to print the coloring of a graph
void print_coloring(graph_t *graph, coloring_t *coloring) {
    printf("The coloring of the graph is:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, coloring->colors[i]);
    }
}

// Main function
int main() {
    // Create a new graph
    graph_t *graph = create_graph(5, 6);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Color the graph
    coloring_t *coloring = color_graph(graph);

    // Print the coloring of the graph
    print_coloring(graph, coloring);

    return 0;
}