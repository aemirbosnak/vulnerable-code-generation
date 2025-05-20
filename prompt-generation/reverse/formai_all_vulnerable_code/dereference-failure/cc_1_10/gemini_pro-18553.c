//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
typedef struct Graph {
    int V;  // Number of vertices
    int E;  // Number of edges
    int **adj;  // Adjacency matrix
} Graph;

// Function to create a new graph
Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    
    // Allocate memory for the adjacency matrix
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(V * sizeof(int));
    }
    
    // Initialize the adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the graph is bipartite
bool isBipartite(Graph *graph) {
    int *colors = (int *)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        colors[i] = -1;
    }
    
    // Assign the first vertex to color 1
    colors[0] = 1;
    
    // Queue to store the vertices to be colored
    int queue[graph->V];
    int front = 0;
    int rear = 0;
    queue[rear++] = 0;
    
    while (front != rear) {
        int u = queue[front++];
        
        // Iterate over the adjacent vertices of u
        for (int v = 0; v < graph->V; v++) {
            if (graph->adj[u][v] == 1) {
                // If the adjacent vertex is not colored
                if (colors[v] == -1) {
                    // Assign the opposite color to the adjacent vertex
                    colors[v] = 1 - colors[u];
                    //Enqueue the adjacent vertex for further processing
                    queue[rear++] = v;
                }
                // If the adjacent vertex is already colored
                else if (colors[v] == colors[u]) {
                    return false;
                }
            }
        }
    }
    
    // If all the vertices are colored and no two adjacent vertices have the same color, then the graph is bipartite
    return true;
}

// Driver code to test the graph coloring algorithm
int main() {
    // Create a graph with 4 vertices and 5 edges
    Graph *graph = createGraph(4, 5);
    
    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    
    // Print the adjacency matrix of the graph
    printf("Adjacency matrix of the graph:\n");
    printGraph(graph);
    
    // Check if the graph is bipartite
    bool is_bipartite = isBipartite(graph);
    if (is_bipartite) {
        printf("The graph is bipartite.\n");
    } else {
        printf("The graph is not bipartite.\n");
    }
    
    // Free the memory allocated for the graph
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);
    
    return 0;
}