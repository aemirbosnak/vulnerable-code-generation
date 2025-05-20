//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLORS 10

typedef struct {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
} Graph;

// Create a new graph with the given number of vertices and edges.
Graph* create_graph(int num_vertices, int num_edges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adjacency_matrix = malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Free the memory used by the graph.
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph);
}

// Add an edge to the graph.
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

// Check if the graph is connected.
int is_connected(Graph* graph) {
    // Create a queue to store the vertices that have been visited.
    int* queue = malloc(graph->num_vertices * sizeof(int));
    int front = 0;
    int rear = 0;

    // Add the first vertex to the queue.
    queue[rear++] = 0;

    // While the queue is not empty, visit the next vertex in the queue.
    while (front != rear) {
        // Get the next vertex from the queue.
        int vertex = queue[front++];

        // Visit the vertex.
        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adjacency_matrix[vertex][i] && i != vertex) {
                // If the vertex is adjacent to the current vertex and has not been visited, add it to the queue.
                queue[rear++] = i;
            }
        }
    }

    // Free the memory used by the queue.
    free(queue);

    // Return whether or not all of the vertices were visited.
    return rear == graph->num_vertices;
}

// Color the graph using the given number of colors.
int* color_graph(Graph* graph, int num_colors) {
    // Create an array to store the colors of the vertices.
    int* colors = malloc(graph->num_vertices * sizeof(int));

    // Initialize the colors of the vertices to -1.
    for (int i = 0; i < graph->num_vertices; i++) {
        colors[i] = -1;
    }

    // Color the first vertex.
    colors[0] = 0;

    // While there are still vertices that have not been colored, color the next vertex.
    int vertex = 1;
    while (vertex < graph->num_vertices) {
        // Get the colors of the adjacent vertices.
        int* adjacent_colors = malloc(num_colors * sizeof(int));
        for (int i = 0; i < num_colors; i++) {
            adjacent_colors[i] = 0;
        }
        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adjacency_matrix[vertex][i]) {
                adjacent_colors[colors[i]] = 1;
            }
        }

        // Find the first available color.
        int color = 0;
        while (adjacent_colors[color]) {
            color++;
        }

        // Color the vertex.
        colors[vertex] = color;

        // Free the memory used by the adjacent colors array.
        free(adjacent_colors);

        // Move to the next vertex.
        vertex++;
    }

    // Return the colors of the vertices.
    return colors;
}

// Print the graph.
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Print the colors of the graph.
void print_colors(int* colors, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    // Create a graph.
    Graph* graph = create_graph(5, 6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);

    // Check if the graph is connected.
    if (!is_connected(graph)) {
        printf("The graph is not connected.\n");
        return 1;
    }

    // Color the graph.
    int* colors = color_graph(graph, MAX_COLORS);

    // Print the graph.
    printf("The graph:\n");
    print_graph(graph);

    // Print the colors of the graph.
    printf("The colors:\n");
    print_colors(colors, graph->num_vertices);

    // Free the memory used by the graph.
    free_graph(graph);

    // Free the memory used by the colors array.
    free(colors);

    return 0;
}