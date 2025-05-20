//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int vertices;
    int edges;
    int **edges_array;
} graph_t;

// Function to create a new graph
graph_t* new_graph(int v, int e) {
    graph_t* g = (graph_t*)malloc(sizeof(graph_t));
    g->vertices = v;
    g->edges = e;
    g->edges_array = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++) {
        g->edges_array[i] = (int*)malloc(e * sizeof(int));
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(graph_t* g, int v1, int v2) {
    g->edges_array[v1][g->edges] = v2;
    g->edges_array[v2][g->edges] = v1;
    g->edges++;
}

// Function to traverse the graph
void traverse(graph_t* g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("Visiting vertex %d\n", i);
        for (int j = 0; j < g->edges; j++) {
            printf("Edge %d -> %d\n", g->edges_array[i][j], g->edges_array[g->edges_array[i][j]][j]);
        }
    }
}

int main() {
    graph_t* g = new_graph(5, 10);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Traverse the graph
    traverse(g);

    // Free the graph memory
    free(g->edges_array[0]);
    free(g->edges_array);
    free(g);

    return 0;
}