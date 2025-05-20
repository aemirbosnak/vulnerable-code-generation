//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 5

// Graph structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} Graph;

// Create a new graph
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_matrix = (int**) malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int*) malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void add_edge(Graph* graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
    graph->num_edges++;
}

// Free the graph
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Check if the graph is colorable with the given number of colors
bool is_graph_colorable(Graph* graph, int num_colors) {
    // Initialize the color array
    int* colors = (int*) malloc(graph->num_vertices * sizeof(int));
    for (int i = 0; i < graph->num_vertices; i++) {
        colors[i] = -1;
    }

    // Color the graph using the greedy algorithm
    for (int i = 0; i < graph->num_vertices; i++) {
        if (colors[i] == -1) {
            // Assign a color to the vertex
            colors[i] = 0;

            // Check if the vertex is adjacent to any vertices that are already colored
            for (int j = 0; j < graph->num_vertices; j++) {
                if (graph->adj_matrix[i][j] == 1 && colors[j] == colors[i]) {
                    // The graph is not colorable
                    free(colors);
                    return false;
                }
            }

            // Increment the color
            colors[i]++;
        }
    }

    // The graph is colorable
    free(colors);
    return true;
}

// Main function
int main() {
    // Create a graph
    Graph* graph = create_graph(4);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    // Check if the graph is colorable with 3 colors
    bool is_colorable = is_graph_colorable(graph, 3);

    // Print the result
    if (is_colorable) {
        printf("The graph is colorable with 3 colors.\n");
    } else {
        printf("The graph is not colorable with 3 colors.\n");
    }

    // Free the graph
    free_graph(graph);

    return 0;
}