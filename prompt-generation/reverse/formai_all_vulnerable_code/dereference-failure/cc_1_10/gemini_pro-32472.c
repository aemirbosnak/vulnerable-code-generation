//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
typedef struct Graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
} Graph;

// Function to create a new graph with V vertices and E edges
Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(V * sizeof(int));
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

// Function to print the graph
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
    // Create a color array to store the colors of the vertices
    int *color = (int *)malloc(graph->V * sizeof(int));
    
    // Initialize all vertices as unassigned
    for (int i = 0; i < graph->V; i++) {
        color[i] = -1;
    }
    
    // Assign a color to the first vertex
    color[0] = 0;
    
    // Queue to store the vertices
    int q[graph->V];
    int front = 0, rear = 0;
    q[rear++] = 0;
    
    // While there are vertices in the queue
    while (front != rear) {
        int u = q[front++];
        
        // For each adjacent vertex of u
        for (int v = 0; v < graph->V; v++) {
            // If u and v are adjacent and have the same color
            if (graph->adj[u][v] && color[u] == color[v]) {
                return false;
            }
            
            // If u and v are adjacent and v is unassigned
            else if (graph->adj[u][v] && color[v] == -1) {
                // Assign the opposite color to v
                color[v] = 1 - color[u];
                
                // Enqueue v
                q[rear++] = v;
            }
        }
    }
    
    // If all vertices are assigned colors, the graph is bipartite
    return true;
}

// Driver function
int main() {
    // Create a graph
    Graph *graph = createGraph(4, 4);
    
    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    
    // Print the graph
    printGraph(graph);
    
    // Check if the graph is bipartite
    bool is_bipartite = isBipartite(graph);
    
    // Print the result
    printf("The graph is %sbipartite\n", is_bipartite ? "" : "not ");
    
    return 0;
}