//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct {
    int vertices;  // number of vertices
    int edges;    // number of edges
    int *edges_arr; // array of edges
} graph_t;

// Function to create a new graph
graph_t *create_graph(int vertices, int edges) {
    graph_t *g = malloc(sizeof(graph_t));
    g->vertices = vertices;
    g->edges = edges;
    g->edges_arr = malloc(edges * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(graph_t *g, int v1, int v2) {
    g->edges_arr[g->edges] = v1;
    g->edges_arr[g->edges + 1] = v2;
    g->edges++;
}

// Function to traverse the graph
void traverse(graph_t *g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->edges; j++) {
            if (g->edges_arr[j] == i) {
                printf("%d ", g->edges_arr[j + 1]);
            }
        }
        printf("\n");
    }
}

int main() {
    graph_t *g = create_graph(5, 10);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Traverse the graph
    traverse(g);

    return 0;
}