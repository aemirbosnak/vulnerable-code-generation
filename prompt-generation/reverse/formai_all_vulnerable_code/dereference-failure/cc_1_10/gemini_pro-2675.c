//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
typedef struct Graph {
    int num_vertices;
    int** adjacency_matrix;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_matrix = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = (int*)malloc(num_vertices * sizeof(int));
    }
    return graph;
}

// Function to free the memory allocated for a graph
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph);
}

// Function to add an edge to a graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

// Function to check if a graph is connected
bool is_connected(Graph* graph) {
    // Create a queue to store the vertices that need to be visited
    int* queue = (int*)malloc(graph->num_vertices * sizeof(int));
    int front = 0;
    int rear = 0;

    // Mark all vertices as unvisited
    bool* visited = (bool*)malloc(graph->num_vertices * sizeof(bool));
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = false;
    }

    // Start by visiting the first vertex
    visited[0] = true;
    queue[rear++] = 0;

    // While there are still vertices to be visited
    while (front != rear) {
        // Get the next vertex from the queue
        int vertex = queue[front++];

        // Visit all adjacent vertices
        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adjacency_matrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    // Check if all vertices have been visited
    for (int i = 0; i < graph->num_vertices; i++) {
        if (!visited[i]) {
            free(queue);
            free(visited);
            return false;
        }
    }

    // Free the memory allocated for the queue and the visited array
    free(queue);
    free(visited);

    return true;
}

// Function to color a graph with the minimum number of colors
int color_graph(Graph* graph) {
    // Check if the graph is connected
    if (!is_connected(graph)) {
        return -1;
    }

    // Create a color array to store the color of each vertex
    int* color = (int*)malloc(graph->num_vertices * sizeof(int));

    // Initialize all vertices with color 0
    for (int i = 0; i < graph->num_vertices; i++) {
        color[i] = 0;
    }

    // Assign colors to the vertices one by one
    int num_colors = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        // Find the first available color for the vertex
        bool available_colors[graph->num_vertices];
        for (int j = 0; j < graph->num_vertices; j++) {
            available_colors[j] = true;
        }
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adjacency_matrix[i][j] == 1 && color[j] != 0) {
                available_colors[color[j]] = false;
            }
        }

        // Assign the first available color to the vertex
        for (int j = 1; j <= graph->num_vertices; j++) {
            if (available_colors[j]) {
                color[i] = j;
                break;
            }
        }

        // Increment the number of colors used
        num_colors++;
    }

    // Free the memory allocated for the color array
    free(color);

    return num_colors;
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

int main() {
    // Create a graph with 5 vertices
    Graph* graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the graph
    printf("The graph:\n");
    print_graph(graph);

    // Get the minimum number of colors needed to color the graph
    int num_colors = color_graph(graph);

    // Print the number of colors needed
    printf("The minimum number of colors needed to color the graph: %d\n", num_colors);

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}