//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Definition of the graph structure
typedef struct {
    int num_vertices;
    int *edges;
} Graph;

// Function to create a new graph
Graph *new_graph(int num_vertices) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->edges = (int *) malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph *g, int u, int v) {
    g->edges[u * g->num_vertices + v] = 1;
}

// Function to print the graph
void print_graph(Graph *g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        printf("Node %d:", i);
        for (j = 0; j < g->num_vertices; j++) {
            if (g->edges[i * g->num_vertices + j]) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

// Function to traverse the graph
void traverse(Graph *g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        printf("Visiting node %d\n", i);
        for (j = 0; j < g->num_vertices; j++) {
            if (g->edges[i * g->num_vertices + j]) {
                traverse(g->edges[i * g->num_vertices + j]);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Create a new graph with 10 vertices
    Graph *g = new_graph(10);

    // Add edges randomly
    for (int i = 0; i < 10; i++) {
        int u = rand() % 10;
        int v = rand() % 10;
        add_edge(g, u, v);
    }

    // Print the graph
    print_graph(g);

    // Traverse the graph
    traverse(g);

    // Free the graph memory
    free(g->edges);
    free(g);

    return 0;
}