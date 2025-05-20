//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct graph {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
} graph;

graph* create_graph(int num_vertices) {
    graph* g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    g->adjacency_matrix = malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        g->adjacency_matrix[i] = malloc(num_vertices * sizeof(int));
    }

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->adjacency_matrix[i][j] = 0;
        }
    }

    return g;
}

void destroy_graph(graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->adjacency_matrix[i]);
    }
    free(g->adjacency_matrix);
    free(g);
}

void add_edge(graph* g, int source, int destination) {
    if (source < 0 || source >= g->num_vertices || destination < 0 || destination >= g->num_vertices) {
        fprintf(stderr, "Invalid vertex specified\n");
        return;
    }

    g->adjacency_matrix[source][destination] = 1;
    g->num_edges++;
}

void remove_edge(graph* g, int source, int destination) {
    if (source < 0 || source >= g->num_vertices || destination < 0 || destination >= g->num_vertices) {
        fprintf(stderr, "Invalid vertex specified\n");
        return;
    }

    g->adjacency_matrix[source][destination] = 0;
    g->num_edges--;
}

bool has_edge(graph* g, int source, int destination) {
    if (source < 0 || source >= g->num_vertices || destination < 0 || destination >= g->num_vertices) {
        fprintf(stderr, "Invalid vertex specified\n");
        return false;
    }

    return g->adjacency_matrix[source][destination] == 1;
}

int main() {
    graph* g = create_graph(5);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    destroy_graph(g);

    return 0;
}