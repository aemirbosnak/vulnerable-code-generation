//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

Graph *create_graph() {
    Graph *graph = (Graph *)calloc(1, sizeof(Graph));
    graph->num_vertices = 0;
    memset(graph->adj_mat, 0, sizeof(graph->adj_mat));
    return graph;
}

void add_edge(Graph *graph, int src, int dest) {
    graph->adj_mat[src][dest] = 1;
    graph->adj_mat[dest][src] = 1;
    graph->num_vertices++;
}

void print_adj_matrix(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void destroy_graph(Graph *graph) {
    free(graph);
}

int main() {
    Graph *graph = create_graph();

    int num_vertices = 5;

    for (int i = 0; i < num_vertices; i++) {
        add_edge(graph, i, (i + 1) % num_vertices);
    }

    print_adj_matrix(graph);

    destroy_graph(graph);

    return 0;
}