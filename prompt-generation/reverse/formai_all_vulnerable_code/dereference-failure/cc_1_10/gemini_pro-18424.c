//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100  // Maximum number of nodes in the graph
#define MAX_COLORS 10  // Maximum number of colors to use

// Graph data structure
typedef struct graph {
    int num_nodes;         // Number of nodes in the graph
    int num_edges;         // Number of edges in the graph
    int** adj_matrix;     // Adjacency matrix representing the graph
} graph_t;

// Graph coloring data structure
typedef struct coloring {
    int* colors;          // Array of colors assigned to nodes
    int num_colors;       // Number of colors used
} coloring_t;

// Function to initialize a graph
graph_t* initialize_graph(int num_nodes) {
    graph_t* graph = (graph_t*)malloc(sizeof(graph_t));
    graph->num_nodes = num_nodes;
    graph->num_edges = 0;
    graph->adj_matrix = (int**)malloc(sizeof(int*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = (int*)malloc(sizeof(int) * num_nodes);
        memset(graph->adj_matrix[i], 0, sizeof(int) * num_nodes);
    }
    return graph;
}

// Function to add an edge to a graph
void add_edge(graph_t* graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
    graph->num_edges++;
}

// Function to print a graph
void print_graph(graph_t* graph) {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize a coloring
coloring_t* initialize_coloring(int num_nodes) {
    coloring_t* coloring = (coloring_t*)malloc(sizeof(coloring_t));
    coloring->colors = (int*)malloc(sizeof(int) * num_nodes);
    memset(coloring->colors, 0, sizeof(int) * num_nodes);
    coloring->num_colors = 0;
    return coloring;
}

// Function to check if a coloring is valid
bool is_valid_coloring(graph_t* graph, coloring_t* coloring) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            if (graph->adj_matrix[i][j] && coloring->colors[i] == coloring->colors[j]) {
                return false;
            }
        }
    }
    return true;
}

// Function to print a coloring
void print_coloring(coloring_t* coloring) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < coloring->num_colors; i++) {
        printf("%d\t%d\n", i, coloring->colors[i]);
    }
}

// Function to generate all possible colorings of a graph
void generate_colorings(graph_t* graph, coloring_t* coloring, int node) {
    if (node == graph->num_nodes) {
        if (is_valid_coloring(graph, coloring)) {
            print_coloring(coloring);
            printf("\n");
        }
        return;
    }

    for (int color = 1; color <= graph->num_nodes; color++) {
        coloring->colors[node] = color;
        coloring->num_colors = fmax(coloring->num_colors, color);
        generate_colorings(graph, coloring, node + 1);
    }
}

int main() {
    // Create a graph with 4 nodes
    graph_t* graph = initialize_graph(4);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    // Print the graph
    print_graph(graph);

    // Create a coloring for the graph
    coloring_t* coloring = initialize_coloring(graph->num_nodes);

    // Generate all possible colorings of the graph
    generate_colorings(graph, coloring, 0);

    return 0;
}