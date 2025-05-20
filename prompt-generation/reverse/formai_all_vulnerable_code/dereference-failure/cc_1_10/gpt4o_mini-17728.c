//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Structure to represent a Graph
typedef struct {
    int vertices;                               // Number of vertices
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

// Function to create a graph with given number of vertices
Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Initialize adjacency matrix with zeros
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v) {
    graph->adjacencyMatrix[u][v] = 1;
    graph->adjacencyMatrix[v][u] = 1; // For undirected graph
}

// Function to check if it's safe to color vertex v with color c
bool isSafe(Graph *graph, int vertex, int color[], int c) {
    for(int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Utility function to solve the graph coloring problem using backtracking
bool graphColoringUtil(Graph *graph, int m, int color[], int vertex) {
    // If all vertices are assigned a color then return true
    if (vertex == graph->vertices) {
        return true;
    }

    // Try different colors for vertex
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c; // Assign color c to vertex

            // Recursively assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return true;
            }

            // Backtrack
            color[vertex] = 0; 
        }
    }

    return false; // No valid color found
}

// Main function to solve Graph Coloring Problem
void graphColoring(Graph *graph, int m) {
    int *color = (int *)malloc(graph->vertices * sizeof(int));

    // Initialize all vertices as uncolored
    for(int i = 0; i < graph->vertices; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == true) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < graph->vertices; i++)
            printf("Vertex %d ---> Color %d\n", i, color[i]);
    } else {
        printf("Solution does not exist\n");
    }

    free(color);
}

// Function to free the allocated graph memory
void freeGraph(Graph *graph) {
    free(graph);
}

int main() {
    int vertices, edges, u, v, m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    Graph *graph = createGraph(vertices);

    printf("Enter the edges (u v) one by one:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);
    freeGraph(graph);
    
    return 0;
}