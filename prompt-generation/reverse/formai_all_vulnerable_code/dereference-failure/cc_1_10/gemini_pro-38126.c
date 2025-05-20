//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Graph data structure
typedef struct graph {
    int V; // Number of vertices
    int E; // Number of edges
    int **adj; // Adjacency matrix
} graph;

// Create a new graph with V vertices
graph* createGraph(int V) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->V = V;
    g->E = 0;
    g->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

// Add an edge to the graph
void addEdge(graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
    g->E++;
}

// Print the graph
void printGraph(graph* g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Graph coloring algorithm
int graphColoring(graph* g) {
    // Initialize the color array
    int colors[g->V];
    for (int i = 0; i < g->V; i++) {
        colors[i] = -1;
    }

    // Assign colors to the vertices
    int colorCount = 0;
    for (int i = 0; i < g->V; i++) {
        if (colors[i] == -1) {
            colors[i] = colorCount;
            for (int j = 0; j < g->V; j++) {
                if (g->adj[i][j] == 1 && colors[j] == colors[i]) {
                    return -1; // Graph is not colorable
                }
            }
            colorCount++;
        }
    }

    // Return the number of colors used
    return colorCount;
}

// Main function
int main() {
    // Create a graph
    graph* g = createGraph(5);

    // Add edges to the graph
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);

    // Print the graph
    printf("Graph:\n");
    printGraph(g);

    // Color the graph
    int numColors = graphColoring(g);

    // Print the number of colors used
    if (numColors == -1) {
        printf("Graph is not colorable\n");
    } else {
        printf("Number of colors used: %d\n", numColors);
    }

    // Free the graph
    for (int i = 0; i < g->V; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);

    return 0;
}