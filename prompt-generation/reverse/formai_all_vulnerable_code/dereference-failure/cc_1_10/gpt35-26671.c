//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph structure
typedef struct graph {
    int num_vertices;
    int num_colors;
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int colors[MAX_VERTICES];
} graph;

// Function to create graph
graph* createGraph(int num_vertices, int num_colors) {
    graph* g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_colors = num_colors;

    // Set all vertices to be uncolored
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->colors[i] = 0;
    }

    // Initialize adjacency matrix
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->vertices[i][j] = 0;
        }
    }

    return g;
}

// Function to add edge to graph
void addEdge(graph* g, int v1, int v2) {
    g->vertices[v1][v2] = 1;
    g->vertices[v2][v1] = 1;
}

// Helper function to check if coloring is valid
bool isValid(graph* g, int vertex, int color) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->vertices[vertex][i] && g->colors[i] == color) {
            return false;
        }
    }
    return true;
}

// Function to solve graph coloring problem recursively
bool solve(graph* g, int vertex) {
    // All vertices have a color
    if (vertex == g->num_vertices) {
        return true;
    }

    // Try all possible colors for this vertex
    for (int color = 1; color <= g->num_colors; color++) {
        if (isValid(g, vertex, color)) {
            g->colors[vertex] = color;
            if (solve(g, vertex + 1)) {
                return true;
            }
            g->colors[vertex] = 0;
        }
    }

    return false;
}

// Function to print solution
void printSolution(graph* g) {
    printf("Solution:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, g->colors[i]);
    }
}

// Main function
int main() {
    graph* g = createGraph(4, 3);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);

    // Solve graph coloring problem
    if (solve(g, 0)) {
        printSolution(g);
    } else {
        printf("No solution found.\n");
    }

    free(g);

    return 0;
}