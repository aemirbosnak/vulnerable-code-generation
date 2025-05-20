//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// Structure to represent a graph
typedef struct {
    int vertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Initialize adjacency matrix
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

// Function to print the adjacency matrix
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to color a vertex with a given color
bool isSafe(Graph* graph, int vertex, int color[], int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == true && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to assign colors to vertices
bool graphColoringUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->vertices) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c; // Assign color c to vertex

            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return true;
            }

            color[vertex] = 0; // Backtrack
        }
    }

    return false;
}

// Function to solve the graph coloring problem
void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->vertices * sizeof(int));

    // Initialize all vertices as uncolored
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0;
    }

    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist.\n");
        return;
    }

    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }

    free(color);
}

// Main function to demonstrate the graph coloring problem
int main() {
    int vertices;
    int m;
    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    Graph* graph = createGraph(vertices);

    // Edge input
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (format: src dest): ", i + 1);
        scanf("%d %d", &src, &dest);

        if (src >= vertices || dest >= vertices) {
            printf("Invalid edge!\n");
            i--; // Decrement to repeat the input for the invalid edge
            continue;
        }
        
        addEdge(graph, src, dest);
    }

    printf("Enter the number of colors available: ");
    scanf("%d", &m);

    graphColoring(graph, m);
    
    free(graph);
    return 0;
}