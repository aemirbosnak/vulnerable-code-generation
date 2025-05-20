//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graph data structure
typedef struct Graph {
    int num_vertices;
    int** adjacency_matrix;
} Graph;

// Create a new graph with the given number of vertices
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_matrix = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = (int*)calloc(num_vertices, sizeof(int));
    }
    return graph;
}

// Free the memory allocated for the graph
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph);
}

// Add an edge between two vertices in the graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

// Remove an edge between two vertices in the graph
void remove_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 0;
    graph->adjacency_matrix[vertex2][vertex1] = 0;
}

// Check if two vertices are adjacent in the graph
bool are_adjacent(const Graph* graph, int vertex1, int vertex2) {
    return graph->adjacency_matrix[vertex1][vertex2] == 1;
}

// Color the given graph using the greedy algorithm
int* greedy_coloring(const Graph* graph) {
    int* colors = (int*)malloc(graph->num_vertices * sizeof(int));
    for (int i = 0; i < graph->num_vertices; i++) {
        colors[i] = -1;
    }
    int current_color = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (colors[i] == -1) {
            colors[i] = current_color;
            for (int j = 0; j < graph->num_vertices; j++) {
                if (are_adjacent(graph, i, j) && colors[j] == current_color) {
                    current_color++;
                }
            }
        }
    }
    return colors;
}

// Print the coloring of the graph
void print_coloring(const Graph* graph, const int* colors) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: color %d\n", i, colors[i]);
    }
}

// Unit tests for the graph coloring algorithm
void test_graph_coloring() {
    // Create a graph with 5 vertices
    Graph* graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    // Color the graph using the greedy algorithm
    int* colors = greedy_coloring(graph);

    // Print the coloring of the graph
    print_coloring(graph, colors);

    // Free the memory allocated for the graph and the colors
    free_graph(graph);
    free(colors);
}

// Main function
int main() {
    // Run the unit tests
    test_graph_coloring();

    return 0;
}