//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
};

// Function to create a graph
struct Graph *createGraph(int V, int E) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    // Create the adjacency matrix
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

// Function to add an edge to a graph
void addEdge(struct Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Function to print the adjacency matrix of a graph
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a graph is bipartite
int isBipartite(struct Graph *graph) {
    // Create a color array to store the colors of the vertices
    int *color = (int *)malloc(graph->V * sizeof(int));

    // Initialize the color array to -1 (uncolored)
    for (int i = 0; i < graph->V; i++) {
        color[i] = -1;
    }

    // Perform BFS on the graph
    int queue[graph->V];
    int front = 0, rear = 0;
    queue[rear++] = 0;
    color[0] = 0;

    while (front < rear) {
        int u = queue[front++];

        // Iterate over all the adjacent vertices of u
        for (int v = 0; v < graph->V; v++) {
            // If u and v are adjacent and have the same color, then the graph is not bipartite
            if (graph->adj[u][v] == 1 && color[u] == color[v]) {
                return 0;
            }

            // If u and v are adjacent and v is uncolored, then color v with the opposite color of u
            if (graph->adj[u][v] == 1 && color[v] == -1) {
                color[v] = 1 - color[u];
                queue[rear++] = v;
            }
        }
    }

    // If the BFS finishes without finding any contradictions, then the graph is bipartite
    return 1;
}

// Driver program to test the isBipartite function
int main() {
    // Create a graph
    struct Graph *graph = createGraph(4, 4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    // Print the adjacency matrix of the graph
    printf("Adjacency matrix of the graph:\n");
    printGraph(graph);

    // Check if the graph is bipartite
    int is_bipartite = isBipartite(graph);

    // Print the result
    if (is_bipartite) {
        printf("The graph is bipartite.\n");
    } else {
        printf("The graph is not bipartite.\n");
    }

    return 0;
}