//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 5  // Number of vertices in the graph

// A utility function to check if the current color assignment is safe for vertex 'v'
bool is_safe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// A recursive function to solve the m-coloring problem
bool graph_coloring_util(int graph[V][V], int m, int color[], int v) {
    // Base case: If all vertices are assigned a color then return true
    if (v == V) {
        return true;
    }

    // Try different colors for vertex 'v'
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is safe
        if (is_safe(graph, color, v, c)) {
            color[v] = c;  // Assign color c to vertex v

            // Recursively assign colors to the remaining vertices
            if (graph_coloring_util(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, remove it
            color[v] = 0;
        }
    }

    return false;  // No color can be assigned to this vertex
}

// The main function that solves the m-coloring problem using graph_coloring_util
bool graph_coloring(int graph[V][V], int m) {
    int *color = (int *)malloc(V * sizeof(int));

    // Initialize all vertices as unassigned
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    // Call the recursive utility function to solve the m-coloring problem
    if (graph_coloring_util(graph, m, color, 0)) {
        printf("Solution exists! The colors assigned are:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
        }
        free(color);
        return true;
    } else {
        printf("No solution exists for the given graph.\n");
        free(color);
        return false;
    }
}

// A function to create a graph and test the coloring
void create_graph_and_test() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},  // Vertex 1 is adjacent to Vertex 2, 3
        {1, 0, 0, 1, 1},  // Vertex 2 is adjacent to Vertex 1, 4, 5
        {1, 0, 0, 1, 0},  // Vertex 3 is adjacent to Vertex 1, 4
        {1, 1, 1, 0, 1},  // Vertex 4 is adjacent to Vertex 1, 2, 3, 5
        {0, 1, 0, 1, 0}   // Vertex 5 is adjacent to Vertex 2, 4
    };
    
    int m = 3;  // Number of colors available
    graph_coloring(graph, m);
}

int main() {
    create_graph_and_test();
    return 0;
}