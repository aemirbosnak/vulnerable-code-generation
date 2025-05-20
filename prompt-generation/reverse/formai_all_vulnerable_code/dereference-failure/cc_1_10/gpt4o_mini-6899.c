//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int **adj; // Adjacency matrix
};

// Function to create a new graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for the adjacency matrix
    graph->adj = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*) calloc(V, sizeof(int));
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // Since the graph is undirected
}

// Function to print the graph
void printGraph(struct Graph *graph) {
    printf("Adjacency matrix of the graph:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current color assignment is safe
int isSafe(struct Graph *graph, int v, int *color, int c) {
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] && color[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

// Function to solve the m-coloring problem using backtracking
int graphColoringUtil(struct Graph *graph, int m, int *color, int v) {
    // Base case: If all vertices are assigned a color
    if (v == graph->V) {
        return 1; // Successful coloring
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return 1; // If successful, return true
            }

            // If no color can be assigned, reset and try next color
            color[v] = 0; 
        }
    }
    return 0; // No coloring is possible
}

// Function to solve the m-coloring problem
void graphColoring(struct Graph *graph, int m) {
    int *color = (int*) calloc(graph->V, sizeof(int)); // Store colors assigned to vertices

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Graph can be colored with %d colors:\n", m);
        for (int i = 0; i < graph->V; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", m);
    }

    free(color);
}

// Main function to demonstrate graph coloring
int main() {
    int V = 5; // Number of vertices
    struct Graph *graph = createGraph(V);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency matrix
    printGraph(graph);

    int m = 3; // Number of colors
    graphColoring(graph, m);

    // Free the allocated memory
    for (int i = 0; i < V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

    return 0;
}