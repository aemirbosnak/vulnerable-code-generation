//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
struct Graph {
    int vertices; // Number of vertices
    int **adjMatrix; // Adjacency matrix
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));

    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize with zero
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Link two hearts
    graph->adjMatrix[dest][src] = 1; // Their love is mutual
}

// Function to print the adjacency matrix
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current color assignment is safe
bool isSafe(int v, struct Graph *graph, int color[], int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[v][i] == 1 && color[i] == c) {
            return false; // A conflict in love
        }
    }
    return true; // A safe liaison
}

// Recursive function to solve the graph coloring problem
bool graphColorUtil(struct Graph *graph, int m, int color[], int v) {
    if (v == graph->vertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // A beautiful bond is formed
            if (graphColorUtil(graph, m, color, v + 1)) {
                return true; // Love leads to success
            }
            color[v] = 0; // Unwind the heart's choice
        }
    }
    return false;
}

// Function to solve graph coloring using backtracking
void graphColoring(struct Graph *graph, int m) {
    int *color = (int*)malloc(graph->vertices * sizeof(int));

    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0; // It's a blank canvas for love
    }

    if (!graphColorUtil(graph, m, color, 0)) {
        printf("No solution exists for the passionate hearts.\n");
        return;
    }

    printf("A harmonious coloring is found:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
    free(color);
}

// Main function
int main() {
    int vertices, edges;
    printf("Enter the number of vertices (the number of loves): ");
    scanf("%d", &vertices);
    
    struct Graph *graph = createGraph(vertices);

    printf("Enter the number of edges (the connections between loves): ");
    scanf("%d", &edges);
    printf("Enter the edges (pairs of connected vertices as 'src dest'):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int m;
    printf("Enter the number of colors (choices of affection): ");
    scanf("%d", &m);

    printf("\nThe romantic connections of the graph:\n");
    printGraph(graph);

    graphColoring(graph, m);

    // Clean up the allocated memory
    for (int i = 0; i < vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}