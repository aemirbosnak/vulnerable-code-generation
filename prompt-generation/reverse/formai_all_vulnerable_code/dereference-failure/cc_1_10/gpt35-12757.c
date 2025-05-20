//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct graph {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int vertices;
};

struct graph* create_graph() {
    struct graph* g = malloc(sizeof(struct graph));
    g->vertices = 0;
    int i, j;

    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            g->matrix[i][j] = 0;
        }
    }

    return g;
}

void add_edge(struct graph* g, int u, int v, int w) {
    g->matrix[u][v] = w;
}

void print_graph(struct graph* g) {
    int i, j;

    for (i = 0; i < g->vertices; i++) {
        for (j = 0; j < g->vertices; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct graph* g = create_graph();
    g->vertices = 6;
    add_edge(g, 0, 1, 2);
    add_edge(g, 0, 2, 3);
    add_edge(g, 1, 2, 4);
    add_edge(g, 2, 3, 1);
    add_edge(g, 3, 4, 5);
    add_edge(g, 3, 5, 6);
    add_edge(g, 4, 5, 7);

    print_graph(g);

    return 0;
}