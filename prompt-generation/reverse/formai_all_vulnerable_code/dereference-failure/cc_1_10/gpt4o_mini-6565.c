//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Structure to represent a graph
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to initialize the graph
void initializeGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* g, int startVertex, int endVertex) {
    g->adjMatrix[startVertex][endVertex] = 1;
    g->adjMatrix[endVertex][startVertex] = 1; // For undirected graph
}

// Function to print the adjacency matrix
void printGraph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Check if it's safe to color a vertex
bool isSafe(int v, Graph* g, int color[], int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Function to solve the graph coloring problem
bool graphColoringUtil(Graph* g, int m, int color[], int vertex) {
    // If all vertices are assigned a color
    if (vertex == g->numVertices) {
        return true;
    }

    // Try different colors for this vertex
    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, g, color, c)) {
            color[vertex] = c;

            // Recur to assign colors to the remaining vertices
            if (graphColoringUtil(g, m, color, vertex + 1)) {
                return true;
            }

            // If no color can be assigned, reset and try next color
            color[vertex] = 0;
        }
    }
    return false;
}

// Function to start the graph coloring
void graphColoring(Graph* g, int m) {
    int* color = malloc(g->numVertices * sizeof(int));
    
    // Initialize color array
    for (int i = 0; i < g->numVertices; i++) {
        color[i] = 0;
    }

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Solution Exists: Coloring of vertices:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists for the given graph and number of colors.\n");
    }

    free(color);
}

int main() {
    printf("Welcome to the Graph Coloring Problem Solver!\n");
    int vertices, edges, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    Graph g;
    initializeGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (format: start end):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    printGraph(&g);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Apply graph coloring
    graphColoring(&g, m);

    return 0;
}