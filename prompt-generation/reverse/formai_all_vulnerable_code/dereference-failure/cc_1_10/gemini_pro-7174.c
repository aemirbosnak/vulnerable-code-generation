//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a graph structure
typedef struct graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
} graph;

// Create a new graph
graph *create_graph(int V, int E) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->V = V;
    g->E = E;

    // Initialize adjacency matrix
    g->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }

    return g;
}

// Free the graph
void free_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

// Add an edge to the graph
void add_edge(graph *g, int u, int v, int w) {
    g->adj[u][v] = w;
    g->adj[v][u] = w;
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Depth-first search
void dfs(graph *g, int u, bool *visited) {
    visited[u] = true;
    printf("%d ", u);

    for (int v = 0; v < g->V; v++) {
        if (g->adj[u][v] > 0 && !visited[v]) {
            dfs(g, v, visited);
        }
    }
}

// Breadth-first search
void bfs(graph *g, int u) {
    bool *visited = (bool *)malloc(g->V * sizeof(bool));
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    int *queue = (int *)malloc(g->V * sizeof(int));
    int front = -1;
    int rear = -1;

    visited[u] = true;
    queue[++rear] = u;

    while (front != rear) {
        u = queue[++front];
        printf("%d ", u);

        for (int v = 0; v < g->V; v++) {
            if (g->adj[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                queue[++rear] = v;
            }
        }
    }

    free(visited);
    free(queue);
}

// Main function
int main() {
    // Create a graph
    graph *g = create_graph(5, 7);
    add_edge(g, 0, 1, 1);
    add_edge(g, 0, 2, 1);
    add_edge(g, 0, 3, 1);
    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 4, 1);
    add_edge(g, 2, 3, 1);
    add_edge(g, 2, 4, 1);

    // Print the graph
    printf("Graph:\n");
    print_graph(g);

    // Depth-first search
    printf("\nDFS:\n");
    bool *visited = (bool *)malloc(g->V * sizeof(bool));
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }
    dfs(g, 0, visited);
    printf("\n");

    // Breadth-first search
    printf("\nBFS:\n");
    bfs(g, 0);
    printf("\n");

    // Free the graph
    free_graph(g);

    return 0;
}