//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graph structure
typedef struct Graph {
    int num_vertices;
    int** adjacency_matrix;
} Graph;

// Function to initialize a graph with the given number of vertices
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_matrix = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = (int*)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

// Function to print the graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the graph is valid for coloring
bool is_valid_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = i + 1; j < graph->num_vertices; j++) {
            if (graph->adjacency_matrix[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

// Function to color the graph
int* color_graph(Graph* graph) {
    int* colors = (int*)malloc(graph->num_vertices * sizeof(int));
    for (int i = 0; i < graph->num_vertices; i++) {
        colors[i] = 0;
    }

    int color = 1;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (colors[i] == 0) {
            colors[i] = color;
            for (int j = i + 1; j < graph->num_vertices; j++) {
                if (graph->adjacency_matrix[i][j] == 1) {
                    colors[j] = color;
                }
            }
            color++;
        }
    }

    return colors;
}

// Function to print the colored graph
void print_colored_graph(Graph* graph, int* colors) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

// Main function
int main() {
    // Create a graph with 4 vertices
    Graph* graph = create_graph(4);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    // Print the graph
    printf("Adjacency matrix of the graph:\n");
    print_graph(graph);

    // Check if the graph is valid for coloring
    if (is_valid_graph(graph)) {
        // Color the graph
        int* colors = color_graph(graph);

        // Print the colored graph
        printf("Colors assigned to the vertices:\n");
        print_colored_graph(graph, colors);
    } else {
        printf("The graph is not valid for coloring.");
    }

    return 0;
}