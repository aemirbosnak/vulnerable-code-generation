//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
typedef struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    int **adj; // Adjacency matrix
} Graph;

// Create a new graph with V vertices
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = 0;
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
    graph->E++;
}

// Check if the graph is colorable with m colors
bool isColorable(Graph *graph, int m) {
    // Create a color array to store the colors of the vertices
    int *color = (int *)malloc(graph->V * sizeof(int));

    // Initialize all vertices as unassigned
    for (int i = 0; i < graph->V; i++) {
        color[i] = -1;
    }

    // A temporary array to store the available colors 
    bool *available = (bool *)malloc(m * sizeof(bool));

    // Consider each vertex
    for (int i = 0; i < graph->V; i++) {
        // Process all adjacent vertices and 
        // mark the colors as unavailable
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1 && color[j] != -1) {
                available[color[j]] = false;
            }
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < m; cr++) {
            if (available[cr] == true) {
                break;
            }
        }

        // Assign the found color to the current vertex
        color[i] = cr;

        // Reset the available colors 
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1 && color[j] != -1) {
                available[color[j]] = true;
            }
        }
    }

    // Check if all vertices are assigned a color
    for (int i = 0; i < graph->V; i++) {
        if (color[i] == -1) {
            return false;
        }
    }

    // Free up the memory
    free(color);
    free(available);

    // Return true if all vertices are colored
    return true;
}

// Print the colors of the vertices
void printColors(Graph *graph, int m) {
    bool *color = (bool *)malloc(graph->V * sizeof(bool));

    // Initialize all vertices as unassigned
    for (int i = 0; i < graph->V; i++) {
        color[i] = false;
    }

    // A temporary array to store the available colors 
    bool *available = (bool *)malloc(m * sizeof(bool));

    // Consider each vertex
    for (int i = 0; i < graph->V; i++) {
        // Process all adjacent vertices and 
        //mark the colors as unavailable
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1 && color[j] != false) {
                available[color[j]] = false;
            }
        }
        // Find the first available color
        int cr;
        for (cr = 0; cr < m; cr++) {
            if (available[cr] == false) {
                break;
            }
        }
        // Assign the found color to the current vertex
        color[i] = cr;

        // Reset the available colors for the next vertex
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1 && color[j] != false) {
                available[color[j]] = true;
            }
        }
    }

    // Print the colors of the vertices
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d is colored %d\n", i, color[i]);
    }

    // Free up the memory
    free(color);
    free(available);
}

// Driver program to test the above functions
int main() {
    // Create a graph with 4 vertices
    Graph *graph = createGraph(4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    // Check if the graph is 3-colorable
    if (isColorable(graph, 3)) {
        printf("The graph is 3-colorable\n");
    } else {
        printf("The graph is not 3-colorable\n");
    }

    // Print the colors of the vertices
    printColors(graph, 3);

    return 0;
}