//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure to represent a graph
typedef struct {
    int vertices;          // Number of vertices
    int **adjMatrix;      // Adjacency matrix
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        
        // Initialize all entries to 0
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;  // Add edge from src to dest
    graph->adjMatrix[dest][src] = 1;  // Since the graph is undirected
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, Graph* graph, int* color, int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[v][i] == 1 && color[i] == c) {
            return false;  // Not safe if adjacent vertices have the same color
        }
    }
    return true;
}

// Utility function to solve the m-coloring problem
bool graphColoringUtil(Graph* graph, int m, int* color, int v) {
    // Base case: If all vertices are assigned a color then return true
    if (v == graph->vertices) {
        return true;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is safe
        if (isSafe(v, graph, color, c)) {
            color[v] = c;  // Assign color c to v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // Backtrack if color c doesn't lead to a solution
            color[v] = 0;  
        }
    }
    return false;  // If no color can be assigned, return false
}

// Function to solve the graph coloring problem
void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->vertices * sizeof(int));
    
    // Initialize all vertices as uncolored
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0;
    }

    // Solve the problem using utility function
    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    // Print the solution
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
    free(color);  // Free allocated memory
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);  // Free each row
    }
    free(graph->adjMatrix);  // Free the main matrix
    free(graph);  // Free the graph structure
}

// Main function to demonstrate graph coloring
int main() {
    int vertices, edges, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);
    
    graphColoring(graph, m);
    freeGraph(graph);  // Clean up
    return 0;
}