//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int num_vertices;
    int *adjacency_list;
} Graph;

// Function to create a new graph
Graph* new_graph(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->num_vertices = n;
    g->adjacency_list = malloc(n * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int u, int v) {
    g->adjacency_list[u] = (g->adjacency_list[u] << 1) | (1 << v);
}

// Function to check if a graph is safe
int is_safe(Graph* g) {
    int safe = 1;
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adjacency_list[i] & (1 << i)) {
            safe = 0;
            break;
        }
    }
    return safe;
}

// Function to print the graph
void print_graph(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adjacency_list[i] & (1 << j)) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* g = new_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 0);

    if (is_safe(g)) {
        printf("Graph is safe!\n");
    } else {
        printf("Graph is not safe.\n");
    }

    print_graph(g);

    return 0;
}