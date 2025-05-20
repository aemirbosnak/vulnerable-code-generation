//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int num_vertices;
    int *adjacency_list;
} Graph;

// Graph creation functions
Graph* create_graph(int num_vertices) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = (int*) malloc(num_vertices * sizeof(int));
    return g;
}

void add_vertex(Graph* g, int vertex) {
    g->adjacency_list[vertex] = 0;
}

void add_edge(Graph* g, int u, int v) {
    g->adjacency_list[u] |= (1 << v);
}

// Graph traversal functions
void dfs(Graph* g, int starting_vertex) {
    int current_vertex = starting_vertex;
    while (current_vertex != -1) {
        printf("Visiting vertex %d\n", current_vertex);
        if (g->adjacency_list[current_vertex] & (1 << current_vertex)) {
            dfs(g, g->adjacency_list[current_vertex]);
        }
        current_vertex = g->adjacency_list[current_vertex];
    }
}

int main() {
    Graph* g = create_graph(10);
    add_vertex(g, 0);
    add_vertex(g, 1);
    add_vertex(g, 2);
    add_vertex(g, 3);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    dfs(g, 0);
    return 0;
}