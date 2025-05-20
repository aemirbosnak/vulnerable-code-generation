//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Representation of a graph using adjacency list
struct Graph {
    int V;                // Number of vertices
    int E;                // Number of edges
    int **adj;            // Adjacency list
    int *color;           // Color of each vertex (0: uncolored, 1: red, 2: blue, ...)
};

// Create a new graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    graph->color = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        graph->color[i] = 0;
    }
    return graph;
}

// Add an edge between vertices u and v
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Check if the graph is bipartite (can be colored with two colors)
int isBipartite(struct Graph* graph) {
    // Initialize the queue with the first vertex
    int queue[graph->V];
    int front = 0, rear = 0;
    queue[rear++] = 0;
    graph->color[0] = 1;  // Color the first vertex red

    // While the queue is not empty
    while (front != rear) {
        // Dequeue a vertex from the queue
        int u = queue[front++];

        // For each adjacent vertex v of u
        for (int v = 0; v < graph->V; v++) {
            if (graph->adj[u][v] == 1) {
                // If v is uncolored
                if (graph->color[v] == 0) {
                    // Color v with the opposite color of u
                    graph->color[v] = 3 - graph->color[u];
                    queue[rear++] = v;
                }
                // If v is already colored and its color is the same as u, the graph is not bipartite
                else if (graph->color[v] == graph->color[u]) {
                    return 0;
                }
            }
        }
    }

    // If the queue is empty, the graph is bipartite
    return 1;
}

// Print the colors of the vertices
void printColors(struct Graph* graph) {
    printf("Colors of the vertices:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: %s\n", i, graph->color[i] == 1 ? "Red" : "Blue");
    }
}

// Main function
int main() {
    // Create a graph with 4 vertices and 4 edges
    struct Graph* graph = createGraph(4, 4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Check if the graph is bipartite
    int isB = isBipartite(graph);

    // Print the result
    if (isB) {
        printf("The graph is bipartite.\n");
        printColors(graph);
    } else {
        printf("The graph is not bipartite.\n");
    }

    // Free the memory allocated for the graph
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph->color);
    free(graph);

    return 0;
}