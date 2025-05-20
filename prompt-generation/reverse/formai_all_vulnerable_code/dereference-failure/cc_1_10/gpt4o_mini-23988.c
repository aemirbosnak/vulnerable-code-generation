//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VILLAGES 10  // Maximum number of villages

// Structure to represent a graph
typedef struct {
    int V;  // Number of villages
    int **adj;  // Adjacency matrix for Merging of Kingdoms
} Graph;

// Function to create a graph with V villages
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    // Allocate memory for the adjacency matrix
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;  // Initialize matrix with no roads
        }
    }
    return graph;
}

// Function to add a road between two villages
void addRoad(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;  // Since the roads are bidirectional
}

// Function to check if the current coloring is safe 
bool isSafe(int v, Graph* graph, int color[], int c) {
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] == 1 && color[i] == c) {
            return false;  // Village i has the same color as village v
        }
    }
    return true;
}

// Recursive function to solve the color assignment
bool graphColorUtil(Graph* graph, int m, int color[], int v) {
    // If all villages have been colored, return true
    if (v == graph->V) {
        return true;
    }

    // Consider different colors for village v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;  // Assign color to village v

            // Recur to assign colors to the remaining villages
            if (graphColorUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution,
            // remove color (backtrack)
            color[v] = 0;
        }
    }
    return false;  // Return false if no color can be assigned
}

// Function to solve the graph coloring problem
void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->V * sizeof(int));
    // Initialize all villages with no color (0)
    for (int i = 0; i < graph->V; i++) {
        color[i] = 0;
    }

    // Call the utility function
    if (graphColorUtil(graph, m, color, 0)) {
        printf("The villages can be colored with %d colors:\n", m);
        for (int i = 0; i < graph->V; i++) {
            printf("Village %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists for %d colors.\n", m);
    }

    free(color);
}

int main() {
    int V = 4;  // Number of villages (size of the kingdom)
    Graph* kingdom = createGraph(V);
    
    // Connect the villages (roads between them)
    addRoad(kingdom, 0, 1);
    addRoad(kingdom, 0, 2);
    addRoad(kingdom, 1, 2);
    addRoad(kingdom, 1, 3);
    
    int m = 3;  // Number of colors (supply of colors for warriors)
    graphColoring(kingdom, m);

    // Free the memory allocated for the graph
    for (int i = 0; i < V; i++) {
        free(kingdom->adj[i]);
    }
    free(kingdom->adj);
    free(kingdom);

    return 0;
}