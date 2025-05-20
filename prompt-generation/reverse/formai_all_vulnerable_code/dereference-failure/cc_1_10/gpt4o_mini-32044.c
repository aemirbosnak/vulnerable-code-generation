//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int verticesCount;
} Graph;

// Function to initialize the graph for the given number of vertices
void initializeGraph(Graph *g, int vertices) {
    g->verticesCount = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices
void addEdge(Graph *g, int src, int dest) {
    g->adjacencyMatrix[src][dest] = 1;
    g->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

// Function to check if the current color assignment is safe for vertex
bool isSafe(Graph *g, int vertex, int color[], int c) {
    for (int i = 0; i < g->verticesCount; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the Graph Coloring Problem
bool graphColoringUtil(Graph *g, int m, int color[], int v) {
    // Base case: If all vertices are assigned a color then return true
    if (v == g->verticesCount) {
        return true;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to vertex v is safe
        if (isSafe(g, v, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(g, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0; // Reset color
        }
    }
    return false; // No solution
}

// Function to solve the Graph Coloring Problem
bool graphColoring(Graph *g, int m) {
    int *color = (int *)malloc(g->verticesCount * sizeof(int));
    for (int i = 0; i < g->verticesCount; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    // Call the recursive utility function to solve the coloring problem
    if (!graphColoringUtil(g, m, color, 0)) {
        printf("Solution does not exist\n");
        free(color);
        return false;
    }

    // Print the solution
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < g->verticesCount; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }

    free(color);
    return true;
}

int main() {
    Graph g;
    int vertices, edges, m;

    // Let’s surprise ourselves by reading a graph from the user!
    printf("Welcome to the Graph Coloring Problem Solver!\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d pairs of edges (0-indexed):\n", edges);
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Enter the number of colors to use: ");
    scanf("%d", &m);

    // Call the graphColoring function
    graphColoring(&g, m);

    return 0;
}