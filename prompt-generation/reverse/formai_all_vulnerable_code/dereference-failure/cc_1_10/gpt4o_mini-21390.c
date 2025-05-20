//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with given vertices and edges
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; // Because the graph is undirected
}

// Function to check if coloring is possible for a vertex
bool isSafe(Graph* graph, int vertex, int color[], int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColorUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->numVertices) {
        return true; // All vertices colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c; // Assign color c
            
            // Recur for the rest of the vertices
            if (graphColorUtil(graph, m, color, vertex + 1)) {
                return true;
            }
            
            color[vertex] = 0; // Backtrack
        }
    }
    return false;
}

// Function to solve the graph coloring problem
bool graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));

    // Initialize all vertices as uncolored
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0;
    }

    // Call to graphColorUtil
    if (!graphColorUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        free(color);
        return false;
    }

    // Print the assigned colors
    printf("Solution exists: Assigned colors are:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }

    free(color);
    return true;
}

// Main function demonstrating the graph coloring
int main() {
    int vertices = 5; // Number of vertices
    int m = 3; // Number of colors

    // Create a graph
    Graph* graph = createGraph(vertices);

    // Add edges (Example Graph)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Color the graph
    graphColoring(graph, m);

    // Free allocated memory
    free(graph);
    return 0;
}