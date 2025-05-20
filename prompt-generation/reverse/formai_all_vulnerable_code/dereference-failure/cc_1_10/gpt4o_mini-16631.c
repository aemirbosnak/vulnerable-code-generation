//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// Structure to represent a graph
typedef struct {
    int numVertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = true;
    graph->adjMatrix[dest][src] = true; // For undirected graph
}

// Function to check if it's safe to color vertex v with color c
bool isSafe(Graph* graph, int v, int color[], int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the m-coloring problem
bool graphColoringUtil(Graph* graph, int m, int color[], int v) {
    if (v == graph->numVertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // Backtrack
            color[v] = 0;
        }
    }
    return false;
}

// Function to solve the m-coloring problem
void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: Colors assigned to vertices are:\n");
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist\n");
    }

    free(color);
}

// Main function
int main() {
    int vertices, edges, src, dest, m;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    
    graphColoring(graph, m);

    // Free allocated memory
    free(graph);
    
    return 0;
}