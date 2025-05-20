//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

// Define the Graph class
typedef struct Graph {
    int n; // number of vertices
    int **adj; // adjacency list representation of the graph
    bool *visited; // visited array to keep track of visited vertices
    bool *cycle; // cycle array to detect cycles in the graph
    int *count; // array to keep track of count of vertices at each level
} Graph;

// Function to initialize the Graph structure
Graph* init_graph(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->n = n;
    g->adj = malloc(n * sizeof(int *));
    g->visited = malloc(n * sizeof(bool));
    g->cycle = malloc(n * sizeof(bool));
    g->count = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        g->adj[i] = malloc(n * sizeof(int));
        g->visited[i] = false;
        g->cycle[i] = false;
        g->count[i] = 0;
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph *g, int v, int w) {
    g->adj[v][g->count[v]] = w;
    g->count[v]++;
}

// Function to perform a depth-first search on the graph
void dfs(Graph *g, int start) {
    g->visited[start] = true;
    g->cycle[start] = false;
    for (int i = 0; i < g->count[start]; i++) {
        int v = g->adj[start][i];
        if (!g->visited[v]) {
            dfs(g, v);
        } else if (g->cycle[start] == true && g->cycle[v] == true) {
            g->cycle[start] = true;
        }
    }
}

// Function to check if the graph has a cycle
bool has_cycle(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        if (!g->visited[i] &&!g->cycle[i]) {
            dfs(g, i);
            if (g->cycle[i]) {
                return true;
            }
        }
    }
    return false;
}

// Function to print the graph representation
void print_graph(Graph *g) {
    printf("Graph Representation:\n");
    for (int i = 0; i < g->n; i++) {
        if (g->visited[i]) {
            printf("Vertex %d: ", i);
            for (int j = 0; j < g->count[i]; j++) {
                int v = g->adj[i][j];
                printf("(%d -> %d)", i, v);
            }
            printf("\n");
        }
    }
}

int main() {
    int n = 5; // number of vertices
    Graph *g = init_graph(n);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 0);

    // Perform depth-first search on the graph
    dfs(g, 0);

    // Check if the graph has a cycle
    if (has_cycle(g)) {
        printf("The graph has a cycle.\n");
    } else {
        printf("The graph does not have a cycle.\n");
    }

    // Print the graph representation
    print_graph(g);

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g->visited);
    free(g->cycle);
    free(g->count);
    free(g);

    return 0;
}