//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
struct Graph {
    int num_vertices;
    int **adjacency_list;
};

// Function to create a graph
struct Graph* create_graph(int n) {
    struct Graph* g = (struct Graph*) malloc(sizeof(struct Graph));
    g->num_vertices = n;
    g->adjacency_list = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->adjacency_list[i] = (int*) malloc(n * sizeof(int));
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(struct Graph* g, int v1, int v2) {
    g->adjacency_list[v1][v2] = 1;
}

// Function to print the graph
void print_graph(struct Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adjacency_list[i][j] == 1) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    struct Graph* g = create_graph(10);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 2, 5);
    add_edge(g, 3, 6);
    add_edge(g, 4, 7);
    add_edge(g, 5, 8);
    print_graph(g);
    return 0;
}