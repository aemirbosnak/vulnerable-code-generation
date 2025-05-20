//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

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
    graph->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

// Function to print the result of graph coloring
void printColoring(int color[], int vertices) {
    printf("Vertex   Color\n");
    printf("---------------\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d       %d\n", i, color[i]);
    }
}

// Function to check if the current color assignment is safe
int isSafe(int v, Graph* graph, int color[], int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Greedy function to solve the graph coloring problem
void graphColoring(Graph* graph) {
    int color[MAX_VERTICES];
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = -1; // Initialize all vertices as uncolored
    }

    // Assign first color to the first vertex
    color[0] = 0;

    // Assign colors to remaining vertices
    for (int v = 1; v < graph->vertices; v++) {
        int availableColors[MAX_VERTICES] = {0}; // Available colors

        // Check colors of adjacent vertices
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[v][i] && color[i] != -1) {
                availableColors[color[i]] = 1;
            }
        }

        // Find the first available color
        for (int c = 0; c < MAX_VERTICES; c++) {
            if (!availableColors[c]) {
                color[v] = c;
                break;
            }
        }
    }

    printColoring(color, graph->vertices);
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);
    
    // Creating a sample graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printf("Graph coloring using greedy algorithm:\n");
    graphColoring(graph);

    // Freeing allocated memory
    free(graph);
    
    return 0;
}