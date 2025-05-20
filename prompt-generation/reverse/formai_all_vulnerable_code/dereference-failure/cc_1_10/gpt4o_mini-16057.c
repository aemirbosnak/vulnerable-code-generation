//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define INF 1000

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int **adj; // Adjacency matrix
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0; // Initialize adjacency matrix with 0s
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // Since the graph is undirected
}

// Function to print the graph (adjacency matrix)
void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to assign colors to vertices with a greedy algorithm
void greedyColoring(struct Graph* graph) {
    int *result = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        result[i] = -1; // Initialize all vertices as uncolored
    }

    result[0] = 0; // First vertex assigned the first color

    for (int u = 1; u < graph->V; u++) {
        // Track the available colors
        int available[graph->V];
        for (int i = 0; i < graph->V; i++) {
            available[i] = 1; // Initialize all colors as available
        }

        // Check adjacent vertices and mark their colors as unavailable
        for (int i = 0; i < graph->V; i++) {
            if (graph->adj[u][i] == 1 && result[i] != -1) {
                available[result[i]] = 0; // Color not available
            }
        }

        // Find the first available color
        for (int color = 0; color < graph->V; color++) {
            if (available[color]) {
                result[u] = color;
                break;
            }
        }
    }

    // Print the result
    printf("Vertex Color Assignment:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d --> Color %d\n", i, result[i]);
    }

    free(result);
}

// Free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);
}

// Main function to run the program
int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Color the graph
    greedyColoring(graph);

    // Free the graph memory
    freeGraph(graph);

    return 0;
}