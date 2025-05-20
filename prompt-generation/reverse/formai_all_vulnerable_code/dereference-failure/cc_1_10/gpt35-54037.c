//FormAI DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Graph data structure
typedef struct graph {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

// Function to add edges to the graph
void add_edge(Graph *g, int v1, int v2) {
    g->adj_matrix[v1][v2] = 1;
    g->adj_matrix[v2][v1] = 1;
}

// Function to print the graph
void print_graph(Graph *g) {
    printf("Adjacency matrix of the graph: \n\n");
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize graph with 6 vertices
    Graph *g = (Graph*) malloc(sizeof(Graph));
    g->num_vertices = 6;
    
    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 5);

    // Print the graph
    print_graph(g);
    
    // Free memory
    free(g);

    return 0;
}