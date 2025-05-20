//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Graph data structure
typedef struct Graph {
    int num_vertices;
    int** adjacency_matrix;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_matrix = malloc(sizeof(int*) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = calloc(num_vertices, sizeof(int));
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

// Function to check if the graph is colorable
int is_colorable(Graph* graph, int num_colors) {
    // Create a color array to store the colors of the vertices
    int* colors = malloc(sizeof(int) * graph->num_vertices);

    // Initialize all vertices to uncolored
    for (int i = 0; i < graph->num_vertices; i++) {
        colors[i] = -1;
    }

    // Try to color the graph using the given number of colors
    if (color_graph(graph, colors, 0, num_colors)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to color the graph
int color_graph(Graph* graph, int* colors, int vertex, int num_colors) {
    // If all vertices have been colored, then the graph is colored
    if (vertex == graph->num_vertices) {
        return 1;
    }

    // Try all possible colors for the current vertex
    for (int color = 0; color < num_colors; color++) {
        // Check if the current color is valid for the current vertex
        if (is_valid_color(graph, colors, vertex, color)) {
            // Assign the current color to the current vertex
            colors[vertex] = color;

            // Recursively color the remaining vertices
            if (color_graph(graph, colors, vertex + 1, num_colors)) {
                return 1;
            }

            // If the recursive call fails, then the current color is not valid for the current vertex
            colors[vertex] = -1;
        }
    }

    // If no valid color can be found for the current vertex, then the graph is not colorable
    return 0;
}

// Function to check if the current color is valid for the current vertex
int is_valid_color(Graph* graph, int* colors, int vertex, int color) {
    // Check if any adjacent vertices have the same color
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] == 1 && colors[i] == color) {
            return 0;
        }
    }

    // If no adjacent vertices have the same color, then the current color is valid
    return 1;
}

// Main function
int main() {
    // Create a graph
    Graph* graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    // Print the graph
    printf("Graph:\n");
    print_graph(graph);

    // Check if the graph is colorable
    int is_colorable_result = is_colorable(graph, 3);

    // Print the result
    if (is_colorable_result) {
        printf("The graph is colorable using 3 colors.\n");
    } else {
        printf("The graph is not colorable using 3 colors.\n");
    }

    // Free the graph
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph);

    return 0;
}