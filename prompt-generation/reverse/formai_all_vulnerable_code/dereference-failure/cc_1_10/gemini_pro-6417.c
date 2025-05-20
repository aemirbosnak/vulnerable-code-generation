//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

// Graph data structure
typedef struct graph {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} graph;

// Graph coloring data structure
typedef struct graph_coloring {
    int num_colors;
    int colors[MAX_VERTICES];
} graph_coloring;

// Function to create a new graph
graph *create_graph(int num_vertices, int num_edges) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }

    return g;
}

// Function to add an edge to a graph
void add_edge(graph *g, int u, int v) {
    g->adj_matrix[u][v] = 1;
    g->adj_matrix[v][u] = 1;
}

// Function to create a new graph coloring
graph_coloring *create_graph_coloring(int num_colors) {
    graph_coloring *gc = (graph_coloring *)malloc(sizeof(graph_coloring));
    gc->num_colors = num_colors;

    // Initialize colors to 0
    for (int i = 0; i < MAX_VERTICES; i++) {
        gc->colors[i] = 0;
    }

    return gc;
}

// Function to check if a graph can be colored with the given number of colors
bool is_graph_colorable(graph *g, graph_coloring *gc) {
    // Initialize a queue to store the vertices that need to be colored
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Enqueue all the vertices
    for (int i = 0; i < g->num_vertices; i++) {
        queue[rear++] = i;
    }

    // While there are vertices in the queue
    while (front < rear) {
        // Dequeue a vertex
        int u = queue[front++];

        // Get the adjacent vertices of u
        int adj[MAX_VERTICES];
        int num_adj = 0;
        for (int i = 0; i < g->num_vertices; i++) {
            if (g->adj_matrix[u][i] == 1) {
                adj[num_adj++] = i;
            }
        }

        // Try all the colors
        for (int c = 1; c <= gc->num_colors; c++) {
            // Check if the color is available
            bool available = true;
            for (int i = 0; i < num_adj; i++) {
                if (gc->colors[adj[i]] == c) {
                    available = false;
                    break;
                }
            }

            // If the color is available, assign it to u
            if (available) {
                gc->colors[u] = c;
                break;
            }
        }

        // If no color is available, the graph cannot be colored
        if (gc->colors[u] == 0) {
            return false;
        }

        // Enqueue the adjacent vertices that have not been colored
        for (int i = 0; i < num_adj; i++) {
            if (gc->colors[adj[i]] == 0) {
                queue[rear++] = adj[i];
            }
        }
    }

    return true;
}

// Function to print the graph coloring
void print_graph_coloring(graph *g, graph_coloring *gc) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, gc->colors[i]);
    }
}

// Driver code
int main() {
    // Create a graph with 5 vertices and 6 edges
    graph *g = create_graph(5, 6);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Create a graph coloring with 3 colors
    graph_coloring *gc = create_graph_coloring(3);

    // Check if the graph is colorable
    if (is_graph_colorable(g, gc)) {
        printf("The graph is colorable:\n");
        print_graph_coloring(g, gc);
    } else {
        printf("The graph is not colorable.\n");
    }

    return 0;
}