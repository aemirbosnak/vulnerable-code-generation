//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Define a maximum number of vertices

// Structure to represent a Graph
typedef struct {
    int vertices;                     // Number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    
    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // Since it's an undirected graph
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adj[i][j]){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Check if it's safe to color vertex v with color c
bool isSafe(Graph* graph, int v, int color[], int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[v][i] == 1 && color[i] == c) {
            return false; // Conflict found
        }
    }
    return true; // No conflict
}

// Utility function to solve graph coloring problem
bool graphColoringUtil(Graph* graph, int m, int color[], int v) {
    // Base case: If all vertices are assigned a color then return true
    if (v == graph->vertices) {
        return true;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, remove it
            color[v] = 0; // Reset the color
        }
    }

    return false; // No solution for this configuration
}

// Function to solve the graph coloring problem
bool graphColoring(Graph* graph, int m) {
    // Initialize colors of all vertices to 0
    int* color = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0;
    }

    // Call the utility function
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    // Print the solution
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }

    free(color); // Free allocated memory
    return true;
}

int main() {
    int vertices, edges, m;

    // Input the number of vertices, edges and colors
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    Graph* graph = createGraph(vertices);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    printGraph(graph);
    graphColoring(graph, m);

    free(graph); // Free allocated memory for the graph
    return 0;
}