//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *adj_list; // array of connected nodes
    int n; // number of connected nodes
} Node;

typedef struct {
    int **adj_matrix; // adjacency matrix
    int n; // number of nodes
} Graph;

// function to initialize empty graph
Graph* init_graph(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->n = n;
    g->adj_matrix = malloc(n * sizeof(int*));
    for(int i=0; i<n; i++) {
        g->adj_matrix[i] = malloc(n * sizeof(int));
        memset(g->adj_matrix[i], 0, n * sizeof(int)); // initialize all values to 0
    }
    return g;
}

// function to add edge to graph
void add_edge(Graph *g, int u, int v) {
    g->adj_matrix[u][v] = 1;
    g->adj_matrix[v][u] = 1; // assuming undirected graph
}

// function to print graph
void print_graph(Graph *g) {
    for(int i=0; i<g->n; i++) {
        for(int j=0; j<g->n; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// function to generate random graph with n nodes and e edges
Graph* generate_random_graph(int n, int e) {
    Graph *g = init_graph(n);
    int u, v;
    while(e > 0) {
        u = rand() % n;
        v = rand() % n;
        if(u != v && g->adj_matrix[u][v] == 0) {
            add_edge(g, u, v);
            e--;
        }
    }
    return g;
}

// main function
int main() {
    Graph *g1 = generate_random_graph(5, 7); // generate random graph with 5 nodes and 7 edges
    printf("Graph 1:\n");
    print_graph(g1); // print graph

    Graph *g2 = init_graph(4);
    add_edge(g2, 0, 1);
    add_edge(g2, 0, 2);
    add_edge(g2, 1, 3);
    printf("\nGraph 2:\n");
    print_graph(g2); // print graph

    return 0;
}