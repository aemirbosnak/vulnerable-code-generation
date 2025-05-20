//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // For undirected graph
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Function to check if it's safe to color vertex with a given color
int isSafe(int vertex, Graph* graph, int color[], int c, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (graph->adj[vertex][i] == 1 && color[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

// Function to implement the graph coloring algorithm using backtracking
int graphColoringUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->numVertices) {
        return 1; // All vertices are colored successfully
    }
    
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c is safe for vertex
        if (isSafe(vertex, graph, color, c, graph->numVertices)) {
            color[vertex] = c; // Assign color c to vertex
            
            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1; // If successfully colored, return true
            }
            
            color[vertex] = 0; // Backtrack
        }
    }
    
    return 0; // If no color can be assigned
}

// Driver function for graph coloring
int graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    
    // Initialize all vertices as uncolored
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0;
    }
    
    // Start from the first vertex and attempt to color the graph
    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Graph can be colored with %d colors:\n", m);
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", m);
    }
    
    free(color);
    return 0;
}

// Main function
int main() {
    int vertices, edges, m;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (source destination) %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    printf("Enter number of colors: ");
    scanf("%d", &m);
    
    printf("Graph representation (adjacency matrix):\n");
    printGraph(graph);
    
    graphColoring(graph, m);
    
    free(graph);
    return 0;
}