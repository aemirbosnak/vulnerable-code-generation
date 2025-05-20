//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
typedef struct Edge {
    int src, dest;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge* edges;
} Graph;

// Function to create a graph with the given number of vertices and edges
Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (Edge*)malloc(graph->numEdges * sizeof(Edge));
    return graph;
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph edges:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        printf("%d -- %d\n", graph->edges[i].src, graph->edges[i].dest);
    }
}

// Utility function to check if we can assign a color to a vertex
bool canColor(int vertex, bool** adjacencyMatrix, int* colors, int color, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve the graph coloring problem
bool graphColoringUtil(bool** adjacencyMatrix, int* colors, int vertex, int numVertices, int numColors) {
    if (vertex == numVertices) {
        return true;
    }

    for (int color = 1; color <= numColors; color++) {
        if (canColor(vertex, adjacencyMatrix, colors, color, numVertices)) {
            colors[vertex] = color;

            if (graphColoringUtil(adjacencyMatrix, colors, vertex + 1, numVertices, numColors)) {
                return true;
            }

            // Backtrack
            colors[vertex] = 0;
        }
    }
    return false;
}

// Function to solve the graph coloring problem
void graphColoring(Graph* graph, int numColors) {
    int* colors = (int*)calloc(graph->numVertices, sizeof(int));
    bool** adjacencyMatrix = (bool**)malloc(graph->numVertices * sizeof(bool*));

    for (int i = 0; i < graph->numVertices; i++) {
        adjacencyMatrix[i] = (bool*)calloc(graph->numVertices, sizeof(bool));
    }

    // Fill the adjacency matrix
    for (int i = 0; i < graph->numEdges; i++) {
        int src = graph->edges[i].src;
        int dest = graph->edges[i].dest;
        adjacencyMatrix[src][dest] = true;
        adjacencyMatrix[dest][src] = true;
    }

    if (graphColoringUtil(adjacencyMatrix, colors, 0, graph->numVertices, numColors)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, colors[i]);
        }
    } else {
        printf("Solution does not exist.");
    }

    for (int i = 0; i < graph->numVertices; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);
    free(colors);
}

// Main function
int main() {
    int numVertices, numEdges, numColors;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    
    Graph* graph = createGraph(numVertices, numEdges);
    
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &graph->edges[i].src, &graph->edges[i].dest);
    }
    
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);
    
    printGraph(graph);
    graphColoring(graph, numColors);
    
    free(graph->edges);
    free(graph);
    
    return 0;
}