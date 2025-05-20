//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

// Graph data structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Graph coloring data structure
typedef struct GraphColoring {
    int num_colors;
    int color_assignment[MAX_VERTICES];
} GraphColoring;

// Function to initialize a graph
Graph* create_graph(int num_vertices, int num_edges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to a graph
void add_edge(Graph* graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
}

// Function to initialize a graph coloring
GraphColoring* create_graph_coloring(int num_colors) {
    GraphColoring* coloring = malloc(sizeof(GraphColoring));
    coloring->num_colors = num_colors;

    // Initialize color assignment to -1 (not colored)
    for (int i = 0; i < MAX_VERTICES; i++) {
        coloring->color_assignment[i] = -1;
    }

    return coloring;
}

// Function to check if a coloring is valid
int is_valid_coloring(Graph* graph, GraphColoring* coloring) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = i + 1; j < graph->num_vertices; j++) {
            if (graph->adj_matrix[i][j] == 1 &&
                coloring->color_assignment[i] == coloring->color_assignment[j]) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to find a valid coloring
int find_valid_coloring(Graph* graph, GraphColoring* coloring, int color_index) {
    if (color_index == graph->num_vertices) {
        return is_valid_coloring(graph, coloring);
    }

    for (int color = 0; color < coloring->num_colors; color++) {
        coloring->color_assignment[color_index] = color;
        if (find_valid_coloring(graph, coloring, color_index + 1)) {
            return 1;
        }
    }

    return 0;
}

// Function to print a graph coloring
void print_graph_coloring(GraphColoring* coloring) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (coloring->color_assignment[i] != -1) {
            printf("Vertex %d is colored %d\n", i, coloring->color_assignment[i]);
        }
    }
}

// Main function
int main() {
    // Create a graph
    Graph* graph = create_graph(5, 6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Create a graph coloring
    GraphColoring* coloring = create_graph_coloring(3);

    // Find a valid coloring
    if (find_valid_coloring(graph, coloring, 0)) {
        printf("Valid coloring found:\n");
        print_graph_coloring(coloring);
    } else {
        printf("No valid coloring found.\n");
    }

    return 0;
}