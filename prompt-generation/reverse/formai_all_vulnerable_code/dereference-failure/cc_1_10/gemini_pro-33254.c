//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10

// Graph data structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
} Graph;

// Create a new graph with the given number of vertices and edges
Graph* create_graph(int num_vertices, int num_edges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adjacency_matrix = malloc(sizeof(int*) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = malloc(sizeof(int) * num_vertices);
    }

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
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

// Add an edge to the graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

// Check if the graph is connected
bool is_connected(Graph* graph) {
    // Use a depth-first search to check if the graph is connected
    bool* visited = malloc(sizeof(bool) * graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = false;
    }

    int stack[graph->num_vertices];
    int top = 0;
    stack[top++] = 0;
    visited[0] = true;

    while (top > 0) {
        int vertex = stack[--top];
        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adjacency_matrix[vertex][i] && !visited[i]) {
                stack[top++] = i;
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < graph->num_vertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    free(visited);
    return true;
}

// Color the graph using the greedy algorithm
int* greedy_coloring(Graph* graph) {
    // Initialize the color array to -1
    int* color = malloc(sizeof(int) * graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++) {
        color[i] = -1;
    }

    // Iterate over the vertices in order of decreasing degree
    int* degree = malloc(sizeof(int) * graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++) {
        degree[i] = 0;
        for (int j = 0; j < graph->num_vertices; j++) {
            degree[i] += graph->adjacency_matrix[i][j];
        }
    }

    int* order = malloc(sizeof(int) * graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++) {
        order[i] = i;
    }

    for (int i = 0; i < graph->num_vertices - 1; i++) {
        for (int j = i + 1; j < graph->num_vertices; j++) {
            if (degree[order[i]] < degree[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    // Assign colors to the vertices
    int available_colors[MAX_COLORS];
    for (int i = 0; i < MAX_COLORS; i++) {
        available_colors[i] = true;
    }

    for (int i = 0; i < graph->num_vertices; i++) {
        int vertex = order[i];
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adjacency_matrix[vertex][j] && color[j] != -1) {
                available_colors[color[j]] = false;
            }
        }

        int c;
        for (c = 0; c < MAX_COLORS; c++) {
            if (available_colors[c]) {
                break;
            }
        }

        color[vertex] = c;
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adjacency_matrix[vertex][j]) {
                available_colors[color[j]] = true;
            }
        }
    }

    free(degree);
    free(order);
    return color;
}

// Print the coloring of the graph
void print_coloring(Graph* graph, int* color) {
    printf("Vertex  Color\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d  %d\n", i, color[i]);
    }
}

int main() {
    // Create a graph
    Graph* graph = create_graph(4, 3);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);

    // Check if the graph is connected
    if (is_connected(graph)) {
        // Color the graph using the greedy algorithm
        int* color = greedy_coloring(graph);

        // Print the coloring of the graph
        print_coloring(graph, color);

        // Free the memory allocated for the color array
        free(color);
    } else {
        printf("The graph is not connected.\n");
    }

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}