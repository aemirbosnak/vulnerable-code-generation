//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure using adjacency list representation
typedef struct {
    int num_vertices;
    int *adjacency_list;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_vertices) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = (int*) malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int v1, int v2) {
    g->adjacency_list[v1] = g->adjacency_list[v1] || (g->adjacency_list[v1] == 0);
    g->adjacency_list[v2] = g->adjacency_list[v2] || (g->adjacency_list[v2] == 0);
    g->adjacency_list[v1] |= (1 << v2);
    g->adjacency_list[v2] |= (1 << v1);
}

// Function to print the graph
void print_graph(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adjacency_list[i] & (1 << j)) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* g = create_graph(6);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 5);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->adjacency_list);
    free(g);

    return 0;
}