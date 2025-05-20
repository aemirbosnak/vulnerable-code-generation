//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to store a vertex and its color
typedef struct Vertex {
    int vertex;
    int color;
} Vertex;

// Function to check if a color is valid for a vertex
int is_color_valid(Vertex *vertices, int n, int vertex, int color) {
    for (int i = 0; i < n; i++) {
        if (vertices[i].vertex == vertex) {
            continue;
        }
        if (vertices[i].color == color) {
            return 0;
        }
    }
    return 1;
}

// Function to find the minimum number of colors needed to color a graph
int find_min_colors(Vertex *vertices, int n) {
    int max_color = 0;
    for (int i = 0; i < n; i++) {
        if (vertices[i].color > max_color) {
            max_color = vertices[i].color;
        }
    }
    return max_color;
}

// Function to color a graph using the greedy algorithm
void greedy_coloring(Vertex *vertices, int n) {
    for (int i = 0; i < n; i++) {
        int min_color = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (vertices[j].vertex == vertices[i].vertex) {
                continue;
            }
            if (vertices[j].color < min_color && is_color_valid(vertices, n, vertices[i].vertex, vertices[j].color)) {
                min_color = vertices[j].color;
            }
        }
        vertices[i].color = min_color + 1;
    }
}

// Function to print the colored graph
void print_colored_graph(Vertex *vertices, int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d is colored %d\n", vertices[i].vertex, vertices[i].color);
    }
}

// Main function
int main() {
    // Get the number of vertices and edges
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Get the edges
    int edges[e][2];
    printf("Enter the edges:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // Create the vertices
    Vertex vertices[n];
    for (int i = 0; i < n; i++) {
        vertices[i].vertex = i + 1;
        vertices[i].color = 0;
    }

    // Color the graph using the greedy algorithm
    greedy_coloring(vertices, n);

    // Print the colored graph
    print_colored_graph(vertices, n);

    // Find the minimum number of colors used
    int min_colors = find_min_colors(vertices, n);
    printf("The minimum number of colors needed to color the graph is %d\n", min_colors);

    return 0;
}