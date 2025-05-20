//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to hold a graph
typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with a specified number of vertices
Graph createGraph(int vertices) {
    Graph g;
    g.vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g.adjMatrix[i][j] = 0;
        }
    }
    
    return g;
}

// Function to add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // since it's an undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g.vertices; i++) {
        for (int j = 0; j < g.vertices; j++) {
            printf("%d ", g.adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, Graph g, int color[], int c) {
    for (int i = 0; i < g.vertices; i++) {
        if (g.adjMatrix[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Utility function to solve the graph coloring problem
bool graphColoringUtil(Graph g, int m, int color[], int v) {
    if (v == g.vertices) {
        return true; // All vertices are processed
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c)) {
            color[v] = c; // Assign color c to vertex v
            
            if (graphColoringUtil(g, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Reset color if it doesn't lead to a solution
        }
    }
    return false; // No solution found
}

// Function to solve the m Coloring Problem
void graphColoring(Graph g, int m) {
    int* color = (int*)malloc(g.vertices * sizeof(int));
    for (int i = 0; i < g.vertices; i++) {
        color[i] = 0; // Initialize all colors to 0
    }

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < g.vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }

    free(color); // Clean up allocated memory
}

// Main function to run our Graph Coloring Program
int main() {
    int vertices, edges, m;
    
    printf("Welcome to the Graph Coloring Problem Solver!\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    Graph g = createGraph(vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }
    
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    
    printGraph(g);
    graphColoring(g, m);
    
    return 0;
}