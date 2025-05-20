//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Matrix structure for adjacent vertices
typedef struct {
    int maxVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Color structure to store graph coloring information
typedef struct {
    int maxColors;
    int colors[MAX_VERTICES];
} Color;

// Function to initialize a graph with given number of vertices
Graph* newGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->maxVertices = numVertices;

    // Initialize all elements of the adjacency matrix to 0
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add edges to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Function to print the adjacency matrix
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->maxVertices; i++) {
        for (int j = 0; j < graph->maxVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize a color struct with given number of colors
Color* newColor(int numColors) {
    Color* color = malloc(sizeof(Color));
    color->maxColors = numColors;

    // Initialize all elements of the colors array to -1
    for (int i = 0; i < MAX_VERTICES; i++) {
        color->colors[i] = -1;
    }

    return color;
}

// Function to check if coloring v with color c is safe
int isSafe(Graph* graph, Color* color, int v, int c) {
    for (int i = 0; i < graph->maxVertices; i++) {
        if (graph->adjMatrix[v][i] && color->colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the graph coloring problem using backtracking
int graphColoring(Graph* graph, Color* color, int vertex) {
    // If all vertices are colored, return true
    if (vertex == graph->maxVertices) {
        return 1;
    }

    // Try different colors for vertex
    for (int c = 0; c < color->maxColors; c++) {
        // Check if coloring vertex with color c is safe
        if (isSafe(graph, color, vertex, c)) {
            // Assign color c to vertex
            color->colors[vertex] = c;

            // Recursively color remaining vertices
            if (graphColoring(graph, color, vertex + 1)) {
                return 1;
            }

            // Backtrack and try different color for vertex
            color->colors[vertex] = -1;
        }
    }

    // Return false if coloring vertex is not possible with any color
    return 0;
}

int main() {
    // Create a new graph and add edges
    Graph* graph = newGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Create a new color struct with 3 colors
    Color* color = newColor(3);

    // Solve the graph coloring problem using backtracking
    if (graphColoring(graph, color, 0)) {
        printf("Vertices colored with colors:\n");
        for (int i = 0; i < graph->maxVertices; i++) {
            printf("%d: %d\n", i, color->colors[i]);
        }
    } else {
        printf("Graph coloring not possible\n");
    }

    return 0;
}