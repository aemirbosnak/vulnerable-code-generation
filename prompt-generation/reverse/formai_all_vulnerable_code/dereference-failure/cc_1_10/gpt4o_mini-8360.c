//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int **adj; // Adjacency matrix
};

// Function to create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)calloc(V, sizeof(int));
    }

    return graph;
}

// Function to add an edge
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // For undirected graph
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Function to check if it's safe to color a vertex
int isSafe(int v, int color[], int c, struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] && c == color[i]) {
            return 0; // Cannot color adjacent vertex with the same color
        }
    }
    return 1; // Safe to color
}

// Function to solve graph coloring using backtracking
int graphColoringUtil(struct Graph* graph, int m, int color[], int v) {
    if (v == graph->V) {
        return 1; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c, graph)) {
            color[v] = c; // Assign color c to vertex v
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return 1; // Proceed to assign colors for next vertex
            }
            color[v] = 0; // Reset color for backtracking
        }
    }
    return 0; // No solution found
}

// Function to color the graph using m colors
int graphColoring(struct Graph* graph, int m) {
    int* color = (int*)calloc(graph->V, sizeof(int)); // Store color assignments
    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < graph->V; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
        free(color);
        return 1;
    } else {
        printf("No solution exists\n");
        free(color);
        return 0;
    }
}

// Main function to demonstrate graph coloring
int main() {
    int V = 5; // Number of vertices
    int m = 3; // Number of colors

    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph adjacency list:\n");
    printGraph(graph);

    graphColoring(graph, m);

    // Cleanup
    for (int i = 0; i < V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

    return 0;
}