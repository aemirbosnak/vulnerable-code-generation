//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define MAX_COLORS 10

// Structure to represent a graph
struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    
    // Initialize adjacency matrix with zero
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add an edge
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;  // Undirected graph
}

// Function to check if a color can be assigned to a vertex
int isSafe(struct Graph* graph, int vertex, int color[], int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && color[i] == c) {
            return 0;  // Not safe to color vertex
        }
    }
    return 1;  // Safe to color vertex
}

// Utility function to solve graph coloring problem
int graphColoringUtil(struct Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->vertices) {
        return 1;  // All vertices are colored successfully
    }
    
    // Try different colors for the vertex
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c;  // Assign color c to vertex
            
            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1;  // Return true if solution found
            }
            
            // Backtrack
            color[vertex] = 0;  // Reset color
        }
    }
    
    return 0;  // No solution found
}

// Function to solve the graph coloring problem
int graphColoring(struct Graph* graph, int m) {
    int* color = (int*)malloc(graph->vertices * sizeof(int));
    
    // Initialize all vertices with no color
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0;
    }
    
    // Call the utility function to solve the coloring
    if (graphColoringUtil(graph, m, color, 0) == 1) {
        printf("Solution exists: Following are the assigned colors: \n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
        free(color);
        return 1;
    }
    
    printf("No solution exists\n");
    free(color);
    return 0;
}

// Main function to test the graph coloring
int main() {
    int m; // Number of colors
    int n; // Number of vertices
    struct Graph* graph;

    // Input number of vertices and colors
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of colors: ");
    scanf("%d", &m);

    // Create the graph
    graph = createGraph(n);

    // Input edges
    printf("Enter edges in the format (src dest) and -1 -1 to stop:\n");
    while (1) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) break;
        addEdge(graph, src, dest);
    }

    // Solve the graph coloring problem
    graphColoring(graph, m);

    // Free memory
    free(graph);
    return 0;
}