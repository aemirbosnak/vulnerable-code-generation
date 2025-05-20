//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int num_vertices;    // Number of vertices in the graph
    int *adjacency_list; // Adjacency list for each vertex
} Graph;

// Graph operations
void add_vertex(Graph *g);
void add_edge(Graph *g, int u, int v);
void print_graph(Graph *g);

// Utility functions
void dfs(Graph *g, int u);
int find(Graph *g, int u);

int main() {
    // Create a new graph
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->num_vertices = 0;

    // Add some vertices and edges to the graph
    add_vertex(g);
    add_vertex(g);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);

    // Print the graph
    print_graph(g);

    // Perform a depth-first search of the graph
    dfs(g, 0);

    // Find a specific vertex in the graph
    int v = find(g, 2);

    // Free the graph memory
    free(g);

    return 0;
}

// Graph structure and operations
void add_vertex(Graph *g) {
    g->num_vertices++;
    g->adjacency_list = realloc(g->adjacency_list, g->num_vertices * sizeof(int));
    g->adjacency_list[g->num_vertices - 1] = 0;
}

void add_edge(Graph *g, int u, int v) {
    g->adjacency_list[u] = g->adjacency_list[u] | (1 << v);
}

void print_graph(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d:", i);
        for (int j = 0; j < 32; j++) {
            if (g->adjacency_list[i] & (1 << j)) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

// Utility functions
void dfs(Graph *g, int u) {
    printf("Visiting vertex %d\n", u);
    for (int v = 0; v < g->num_vertices; v++) {
        if (g->adjacency_list[u] & (1 << v)) {
            dfs(g, v);
        }
    }
}

int find(Graph *g, int u) {
    int current = u;
    while (current != -1) {
        current = g->adjacency_list[current];
        if (current == -1) {
            return -1;
        }
    }
    return current;
}