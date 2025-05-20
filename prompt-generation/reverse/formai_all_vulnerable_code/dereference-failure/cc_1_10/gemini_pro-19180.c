//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Macros for colors
#define RED 1
#define GREEN 2
#define BLUE 3

// Graph data structure
typedef struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    int **adj; // Adjacency matrix
} Graph;

// Function to create a new graph
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = 0;
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(V * sizeof(int));
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
    graph->E++;
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
int isBipartite(Graph *graph) {
    int *color = (int *)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        color[i] = -1;
    }

    // Queue to store the vertices
    int queue[graph->V];
    int front = 0, rear = -1;

    // Enqueue the first vertex
    queue[++rear] = 0;
    color[0] = RED;

    while (front <= rear) {
        int u = queue[front++];

        // Check all the adjacent vertices of u
        for (int i = 0; i < graph->V; i++) {
            if (graph->adj[u][i] && color[i] == -1) {
                // Assign the opposite color to the adjacent vertex
                color[i] = color[u] == RED ? GREEN : RED;
                // Enqueue the adjacent vertex
                queue[++rear] = i;
            } else if (graph->adj[u][i] && color[i] == color[u]) {
                // If the adjacent vertex has the same color, the graph is not bipartite
                return 0;
            }
        }
    }

    // If all the vertices have been colored without any conflicts, the graph is bipartite
    return 1;
}

// Main function
int main() {
    // Create a graph
    Graph *graph = createGraph(4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the graph
    printf("Graph:\n");
    printGraph(graph);

    // Check if the graph is bipartite
    int is_bipartite = isBipartite(graph);

    if (is_bipartite) {
        printf("The graph is bipartite.\n");
    } else {
        printf("The graph is not bipartite.\n");
    }

    return 0;
}