//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Graph data structure
struct Graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
};

// Create a new graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
    }
    return graph;
}

// Add an edge between vertices u and v
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Print the adjacency matrix of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Check if the graph is bipartite
int isBipartite(struct Graph* graph) {
    // Initialize the color array
    int *color = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        color[i] = -1;
    }

    // Perform a BFS on the graph
    int queue[graph->V];
    int front = 0;
    int rear = 0;
    for (int i = 0; i < graph->V; i++) {
        if (color[i] == -1) {
            queue[rear++] = i;
            color[i] = 0;
        }

        while (front != rear) {
            int u = queue[front++];
            for (int v = 0; v < graph->V; v++) {
                if (graph->adj[u][v] == 1) {
                    if (color[v] == -1) {
                        queue[rear++] = v;
                        color[v] = 1 - color[u];
                    } else if (color[v] == color[u]) {
                        return 0;
                    }
                }
            }
        }
    }

    // Free the color array
    free(color);

    // Return true if the graph is bipartite
    return 1;
}

// Driver program to test the graph coloring algorithm
int main() {
    // Create a graph
    struct Graph* graph = createGraph(4, 4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the graph
    printGraph(graph);

    // Check if the graph is bipartite
    if (isBipartite(graph)) {
        printf("The graph is bipartite\n");
    } else {
        printf("The graph is not bipartite\n");
    }

    // Free the graph
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

    return 0;
}