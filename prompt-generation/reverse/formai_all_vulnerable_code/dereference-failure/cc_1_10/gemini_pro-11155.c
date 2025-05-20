//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int num_vertices;
    int num_edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
    int vertex;
    int color;
} VertexColor;

VertexColor vertex_colors[MAX_VERTICES];

// Function to create a new graph
Graph *create_graph(int num_vertices, int num_edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    // Initialize the adjacency matrix
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }

    // Read the edges from the user
    for (int i = 0; i < num_edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph->adjacency_matrix[vertex1][vertex2] = 1;
        graph->adjacency_matrix[vertex2][vertex1] = 1;
    }

    return graph;
}

// Function to check if a color is safe for a given vertex
int is_safe(Graph *graph, int vertex, int color) {
    // Check if any of the adjacent vertices have the same color
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] == 1 && vertex_colors[i].color == color) {
            return 0;
        }
    }

    return 1;
}

// Function to color the graph using the greedy algorithm
void greedy_coloring(Graph *graph) {
    // Initialize the vertex colors
    for (int i = 0; i < graph->num_vertices; i++) {
        vertex_colors[i].vertex = i;
        vertex_colors[i].color = 0;
    }

    // Assign colors to the vertices one by one
    for (int i = 0; i < graph->num_vertices; i++) {
        // Find the minimum color that is safe for the current vertex
        int min_color = 1;
        while (!is_safe(graph, i, min_color)) {
            min_color++;
        }

        // Assign the minimum color to the current vertex
        vertex_colors[i].color = min_color;
    }
}

// Function to print the vertex colors
void print_vertex_colors() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (vertex_colors[i].vertex != -1) {
            printf("Vertex %d: Color %d\n", vertex_colors[i].vertex, vertex_colors[i].color);
        }
    }
}

int main() {
    // Create a graph
    Graph *graph = create_graph(5, 4);

    // Color the graph using the greedy algorithm
    greedy_coloring(graph);

    // Print the vertex colors
    print_vertex_colors();

    return 0;
}