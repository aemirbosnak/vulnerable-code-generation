//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int **adj; // Adjacency matrix
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for adjacency matrix
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0; // Initialize adjacency matrix with 0
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // Undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(struct Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current color assignment is valid
int isSafe(int v, struct Graph *graph, int color[], int c) {
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] && color[i] == c) {
            return 0; // Not safe to color
        }
    }
    return 1; // Safe to color
}

// Recursive function to solve graph coloring problem
int graphColoringUtil(struct Graph *graph, int m, int color[], int v) {
    if (v == graph->V) {
        return 1; // All vertices are colored successfully
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color c to vertex v
            
            // Recur to color the rest of the graph
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return 1;
            }
            color[v] = 0; // Backtrack
        }
    }
    return 0; // No color could be assigned
}

// Function to solve the graph coloring problem
void graphColoring(struct Graph *graph, int m) {
    int *color = (int*)malloc(graph->V * sizeof(int));
    
    // Initialize all color values as 0 (no color assigned)
    for (int i = 0; i < graph->V; i++) {
        color[i] = 0;
    }

    // Solve the graph coloring problem
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return;
    }

    // Print the solution
    printf("Solution exists: Following are the colors assigned to vertices:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }

    // Free allocated memory
    free(color);
}

// Main function
int main() {
    int V, m;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    struct Graph *graph = createGraph(V);
    
    printf("Enter number of edges: ");
    int edges;
    scanf("%d", &edges);
    
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the maximum number of colors: ");
    scanf("%d", &m);

    printGraph(graph);
    graphColoring(graph, m);

    // Free graph memory
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

    return 0;
}