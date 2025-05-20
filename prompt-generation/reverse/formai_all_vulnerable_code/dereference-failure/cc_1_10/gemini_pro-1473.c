//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Graph representation
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} Graph;

// Graph coloring result
typedef int *Coloring;

// Forward declarations
Graph *create_graph(int num_vertices, int num_edges);
void destroy_graph(Graph *graph);
void print_graph(Graph *graph);
Coloring greedy_color(Graph *graph);
void print_coloring(Coloring coloring, int num_vertices);

// Main function
int main() {
    // Create a graph
    Graph *graph = create_graph(5, 6);
    graph->adj_matrix[0][1] = 1;
    graph->adj_matrix[0][2] = 1;
    graph->adj_matrix[0][3] = 0;
    graph->adj_matrix[0][4] = 1;
    graph->adj_matrix[1][0] = 1;
    graph->adj_matrix[1][2] = 1;
    graph->adj_matrix[1][3] = 1;
    graph->adj_matrix[1][4] = 0;
    graph->adj_matrix[2][0] = 1;
    graph->adj_matrix[2][1] = 1;
    graph->adj_matrix[2][3] = 1;
    graph->adj_matrix[2][4] = 1;
    graph->adj_matrix[3][0] = 0;
    graph->adj_matrix[3][1] = 1;
    graph->adj_matrix[3][2] = 1;
    graph->adj_matrix[3][4] = 1;
    graph->adj_matrix[4][0] = 1;
    graph->adj_matrix[4][1] = 0;
    graph->adj_matrix[4][2] = 1;
    graph->adj_matrix[4][3] = 1;

    // Print the graph
    printf("Graph:\n");
    print_graph(graph);

    // Get the greedy coloring
    Coloring coloring = greedy_color(graph);

    // Print the coloring
    printf("Greedy coloring:\n");
    print_coloring(coloring, graph->num_vertices);

    // Destroy the graph
    destroy_graph(graph);

    return 0;
}

// Creates a new graph with the given number of vertices and edges
Graph *create_graph(int num_vertices, int num_edges) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
    }
    return graph;
}

// Destroys the given graph
void destroy_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Prints the given graph to the standard output
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Performs a greedy coloring of the given graph and returns the result as an array of colors
Coloring greedy_color(Graph *graph) {
    Coloring coloring = (Coloring)malloc(graph->num_vertices * sizeof(int));
    int available_colors[graph->num_vertices];

    // Initialize the available colors array
    for (int i = 0; i < graph->num_vertices; i++) {
        available_colors[i] = 1;
    }

    // Iterate over the vertices
    for (int i = 0; i < graph->num_vertices; i++) {
        // Find the first available color for the current vertex
        int color = 0;
        while (!available_colors[color]) {
            color++;
        }

        // Color the current vertex and mark the color as unavailable for adjacent vertices
        coloring[i] = color;
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adj_matrix[i][j] == 1) {
                available_colors[coloring[i]] = 0;
            }
        }
    }

    return coloring;
}

// Prints the given coloring to the standard output
void print_coloring(Coloring coloring, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", coloring[i]);
    }
    printf("\n");
}