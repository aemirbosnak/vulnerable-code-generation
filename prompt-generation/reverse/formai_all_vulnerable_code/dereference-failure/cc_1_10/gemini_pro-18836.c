//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graph data structure
typedef struct Graph {
    int V;              // Number of vertices
    int E;              // Number of edges
    int **adj;          // Adjacency matrix
    int *colors;        // Color assigned to each vertex
    bool *visited;      // Whether each vertex has been visited
} Graph;

// Vertex color
typedef enum {
    WHITE,
    GRAY,
    BLACK
} Color;

// Create a new graph with V vertices and E edges
Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;

    // Allocate memory for the adjacency matrix
    graph->adj = (int **)malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(sizeof(int) * V);
    }

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }

    // Allocate memory for the color array
    graph->colors = (int *)malloc(sizeof(int) * V);

    // Initialize the color array to WHITE
    for (int i = 0; i < V; i++) {
        graph->colors[i] = WHITE;
    }

    // Allocate memory for the visited array
    graph->visited = (bool *)malloc(sizeof(bool) * V);

    // Initialize the visited array to false
    for (int i = 0; i < V; i++) {
        graph->visited[i] = false;
    }

    return graph;
}

// Free the memory allocated for the graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph->colors);
    free(graph->visited);
    free(graph);
}

// Add an edge between vertices u and v
void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Print the adjacency matrix of the graph
void printAdjacencyMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Check if the graph is bipartite
bool isBipartite(Graph *graph) {
    // Initialize the queue
    int queue[graph->V];
    int front = 0;
    int rear = 0;

    // Enqueue the first vertex
    queue[rear++] = 0;

    // Color the first vertex black
    graph->colors[0] = BLACK;

    // While the queue is not empty
    while (front != rear) {
        // Dequeue the next vertex
        int u = queue[front++];

        // Visit all the adjacent vertices of u
        for (int v = 0; v < graph->V; v++) {
            // If there is an edge between u and v
            if (graph->adj[u][v] == 1) {
                // If v has not been visited
                if (graph->visited[v] == false) {
                    // Enqueue v
                    queue[rear++] = v;

                    // Color v with the opposite color of u
                    graph->colors[v] = (graph->colors[u] == BLACK) ? WHITE : BLACK;

                    // Mark v as visited
                    graph->visited[v] = true;
                }
                // If v has already been visited
                else {
                    // If v has the same color as u
                    if (graph->colors[v] == graph->colors[u]) {
                        // The graph is not bipartite
                        return false;
                    }
                }
            }
        }
    }

    // The graph is bipartite
    return true;
}

// Main function
int main() {
    // Create a graph with 4 vertices and 5 edges
    Graph *graph = createGraph(5, 10);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    // Print the adjacency matrix of the graph
    printf("Adjacency Matrix:\n");
    printAdjacencyMatrix(graph);

    // Check if the graph is bipartite
    bool is_bipartite = isBipartite(graph);

    // Print the result
    if (is_bipartite) {
        printf("The graph is bipartite.\n");
    } else {
        printf("The graph is not bipartite.\n");
    }

    // Free the memory allocated for the graph
    freeGraph(graph);

    return 0;
}