//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct graph {
    int num_vertices;
    int edges[MAX_VERTICES][MAX_VERTICES];
};

void initialize_graph(struct graph* g, int num_vertices) {
    g->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->edges[i][j] = 0;
        }
    }
}

void add_edge(struct graph* g, int start_vertex, int end_vertex) {
    g->edges[start_vertex][end_vertex] = 1;
    g->edges[end_vertex][start_vertex] = 1;
}

void print_graph(struct graph* g) {
    printf("Graph:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct graph* g = malloc(sizeof(struct graph));
    initialize_graph(g, 6);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 3, 5);

    print_graph(g);

    free(g);
    return 0;
}