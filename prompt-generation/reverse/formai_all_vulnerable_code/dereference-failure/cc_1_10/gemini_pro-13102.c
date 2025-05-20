//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Graph coloring problem data structure
typedef struct {
    int num_vertices;
    int **adj_matrix;
    int *colors;
} Graph;

// Function to create a new graph
Graph *create_graph(int num_vertices) {
    // Allocate memory for the graph
    Graph *graph = malloc(sizeof(Graph));

    // Initialize the number of vertices
    graph->num_vertices = num_vertices;

    // Allocate memory for the adjacency matrix
    graph->adj_matrix = malloc(sizeof(int *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_vertices);
    }

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    // Allocate memory for the colors
    graph->colors = malloc(sizeof(int) * num_vertices);

    // Initialize the colors to -1
    for (int i = 0; i < num_vertices; i++) {
        graph->colors[i] = -1;
    }

    // Return the graph
    return graph;
}

// Function to free the memory allocated for a graph
void free_graph(Graph *graph) {
    // Free the adjacency matrix
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);

    // Free the colors
    free(graph->colors);

    // Free the graph
    free(graph);
}

// Function to add an edge to a graph
void add_edge(Graph *graph, int vertex1, int vertex2) {
    // Add the edge to the adjacency matrix
    graph->adj_matrix[vertex1][vertex2] = 1;
    graph->adj_matrix[vertex2][vertex1] = 1;
}

// Function to check if a graph is colorable
int is_colorable(Graph *graph) {
    // Initialize the stack
    int stack[graph->num_vertices];
    int top = -1;

    // Push the first vertex onto the stack
    stack[++top] = 0;

    // While the stack is not empty
    while (top >= 0) {
        // Pop the top vertex from the stack
        int vertex = stack[top--];

        // Color the vertex
        for (int color = 0; color < graph->num_vertices; color++) {
            // If the color is not used by any of the neighbors
            if (!used_color(graph, vertex, color)) {
                graph->colors[vertex] = color;
                break;
            }
        }

        // If the vertex could not be colored
        if (graph->colors[vertex] == -1) {
            return 0;
        }

        // Push the uncolored neighbors of the vertex onto the stack
        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adj_matrix[vertex][i] && graph->colors[i] == -1) {
                stack[++top] = i;
            }
        }
    }

    // If the stack is empty, the graph is colorable
    return 1;
}

// Function to check if a color is used by any of the neighbors of a vertex
int used_color(Graph *graph, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex][i] && graph->colors[i] == color) {
            return 1;
        }
    }
    return 0;
}

// Function to print a graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the colors of a graph
void print_colors(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d ", graph->colors[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a graph
    Graph *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the graph
    printf("Graph:\n");
    print_graph(graph);

    // Check if the graph is colorable
    int is_colorable_result = is_colorable(graph);

    // Print the result
    if (is_colorable_result) {
        printf("Graph is colorable\n");
        print_colors(graph);
    } else {
        printf("Graph is not colorable\n");
    }

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}