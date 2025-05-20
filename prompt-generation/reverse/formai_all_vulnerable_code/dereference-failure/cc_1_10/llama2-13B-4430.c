//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Graph structure definition
typedef struct {
    int num_vertices;    // Number of vertices in the graph
    int **edges;       // Array of adjacency lists
} Graph;

// Function to create an empty graph
Graph *empty_graph(int n) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->num_vertices = n;
    g->edges = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g->edges[i] = NULL;
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph *g, int u, int v) {
    if (u >= g->num_vertices || v >= g->num_vertices) {
        printf("Error: Vertex index out of range\n");
        return;
    }
    if (g->edges[u] == NULL) {
        g->edges[u] = (int *) malloc(sizeof(int));
        g->edges[u][0] = v;
    } else {
        int *new_edge = (int *) realloc(g->edges[u], (g->edges[u][0] + 1) * sizeof(int));
        g->edges[u] = new_edge;
        g->edges[u][g->edges[u][0]++] = v;
    }
}

// Function to print the graph
void print_graph(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g->edges[i][0]; j++) {
            printf("%d ", g->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph *g = empty_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    print_graph(g);
    return 0;
}