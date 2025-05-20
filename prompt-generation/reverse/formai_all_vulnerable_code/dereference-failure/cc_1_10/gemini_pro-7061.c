//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a graph
typedef struct {
    int num_vertices;
    int** adjacency_matrix;
} Graph;

// Function to create a new graph with the given number of vertices
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_matrix = (int**) malloc(sizeof(int*) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = (int*) malloc(sizeof(int) * num_vertices);
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

// Function to print the adjacency matrix of the graph
void print_graph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to solve the graph coloring problem using a greedy algorithm
int* graph_coloring(Graph* graph, int num_colors) {
    // Create an array to store the color of each vertex
    int* colors = (int*) malloc(sizeof(int) * graph->num_vertices);
    
    // Initialize the color of all vertices to -1 (uncolored)
    for (int i = 0; i < graph->num_vertices; i++) {
        colors[i] = -1;
    }

    for (int i = 0; i < graph->num_vertices; i++) {
        // If the current vertex is not colored
        if (colors[i] == -1) {
            // Create a list of available colors for the current vertex
            int* available_colors = (int*) malloc(sizeof(int) * num_colors);
            for (int j = 0; j < num_colors; j++) {
                available_colors[j] = 1;
            }

            // Mark the colors of the adjacent vertices as unavailable
            for (int j = 0; j < graph->num_vertices; j++) {
                if (graph->adjacency_matrix[i][j] == 1 && colors[j] != -1) {
                    available_colors[colors[j]] = 0;
                }
            }

            // Find the first available color and assign it to the current vertex
            int color = -1;
            for (int j = 0; j < num_colors; j++) {
                if (available_colors[j] == 1) {
                    color = j;
                    break;
                }
            }

            if (color == -1) {
                printf("The graph is not colorable with %d colors.\n", num_colors);
                return NULL;
            }

            colors[i] = color;
            free(available_colors);
        }
    }

    // Return the array of colors
    return colors;
}

// Function to print the coloring of the graph
void print_coloring(int* colors, int num_vertices) {
    printf("Vertex Colors:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

int main() {
    int num_vertices = 5;
    int num_colors = 3;

    Graph* graph = create_graph(num_vertices);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    printf("Input Graph:\n");
    print_graph(graph);

    int* colors = graph_coloring(graph, num_colors);

    if (colors != NULL) {
        printf("\nGraph Coloring:\n");
        print_coloring(colors, num_vertices);
    }

    for (int i = 0; i < num_vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph);
    free(colors);
    return 0;
}