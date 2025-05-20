//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct graph {
   int vertices;
   int** adjacency_matrix; 
};

struct graph* create_graph(int vertices) {
    // dynamically allocate memory for the graph struct
    struct graph* g = malloc(sizeof(struct graph));
    g->vertices = vertices;
    
    // dynamically allocate memory for the adjacency matrix
    g->adjacency_matrix = malloc(vertices * sizeof(int*));
    for(int i = 0; i < vertices; i++) {
        g->adjacency_matrix[i] = calloc(vertices, sizeof(int));
    }
    
    return g;
}

void add_edge(struct graph* g, int source, int destination) {
    // add edge to the adjacency matrix
    g->adjacency_matrix[source][destination] = 1;
    g->adjacency_matrix[destination][source] = 1;
}

void print_graph(struct graph* g) {
    int i, j;
    for(i = 0; i < g->vertices; i++) {
        for(j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct graph* g = create_graph(5);
    
    // add edges between nodes
    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    
    // print the adjacency matrix representation of the graph
    printf("The graph represented by its adjacency matrix:\n");
    print_graph(g);
    
    return 0;
}