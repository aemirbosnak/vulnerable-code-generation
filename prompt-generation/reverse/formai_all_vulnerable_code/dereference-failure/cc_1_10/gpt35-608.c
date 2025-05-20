//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the number of vertices and edges
#define MAX_VERTICES 10
#define MAX_EDGES 20

// Define colors for the vertices
#define RED 0
#define BLUE 1
#define GREEN 2

// Define a structure for an edge
typedef struct {
    int u;
    int v;
} Edge;

// Define a structure for the graph
typedef struct {
    int num_vertices;
    int num_edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Define a function to read the graph from user input
void read_graph(Graph *graph)
{
    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &graph->num_vertices);

    printf("Enter the number of edges (maximum %d): ", MAX_EDGES);
    scanf("%d", &graph->num_edges);

    for (int i = 0; i < graph->num_edges; i++) {
        printf("Enter edge %d (vertex u, vertex v): ", i+1);
        int u, v;
        scanf("%d %d", &u, &v);

        // Add the edge to the adjacency matrix
        graph->adjacency_matrix[u][v] = 1;
        graph->adjacency_matrix[v][u] = 1;
    }
}

// Define a function to check if the current color is valid for a vertex
bool is_color_valid(Graph *graph, int v, int color, int color_assignment[])
{
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[v][i] && color_assignment[i] == color) {
            return false;
        }
    }
    return true;
}

// Define a function to solve the graph coloring problem recursively
bool graph_coloring(Graph *graph, int num_colors, int v, int color_assignment[])
{
    // If all vertices are colored, return true
    if (v == graph->num_vertices) {
        return true;
    }

    // Try all possible colors for the current vertex
    for (int color = 0; color < num_colors; color++) {
        if (is_color_valid(graph, v, color, color_assignment)) {
            color_assignment[v] = color;

            // Recursively solve the remainder of the graph
            if (graph_coloring(graph, num_colors, v+1, color_assignment)) {
                return true;
            }

            // Backtrack
            color_assignment[v] = -1;
        }
    }

    // If no valid color was found for the current vertex, return false
    return false;
}

// Define a function to print the colors assigned to each vertex
void print_vertex_colors(Graph *graph, int color_assignment[])
{
    printf("Vertex colors:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        switch (color_assignment[i]) {
            case RED:
                printf("Red\n");
                break;
            case BLUE:
                printf("Blue\n");
                break;
            case GREEN:
                printf("Green\n");
                break;
            default:
                printf("Color not assigned\n");
                break;
        }
    }
}

int main()
{
    printf("Graph Coloring Problem Solver\n");

    // Initialize the graph
    Graph graph = {0};
    read_graph(&graph);

    // Initialize the color assignment
    int color_assignment[MAX_VERTICES];
    for (int i = 0; i < graph.num_vertices; i++) {
        color_assignment[i] = -1;
    }

    // Solve the graph coloring problem
    if (graph_coloring(&graph, 3, 0, color_assignment)) {
        printf("Solution found!\n");
        print_vertex_colors(&graph, color_assignment);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}