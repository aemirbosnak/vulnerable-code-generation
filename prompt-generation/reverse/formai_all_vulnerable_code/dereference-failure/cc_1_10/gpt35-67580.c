//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include<stdio.h>
#include<stdlib.h>

struct graph {
    int vertices;
    int edges;
    int** adjacency_matrix;
};

struct graph* create_graph(int vertices, int edges) {
    int i, j;
    struct graph* g = malloc(sizeof(struct graph));
    g->vertices = vertices;
    g->edges = edges;
    g->adjacency_matrix = malloc(sizeof(int*) * vertices);
    for (i = 0; i < vertices; i++) {
        g->adjacency_matrix[i] = malloc(sizeof(int) * vertices);
        for (j = 0; j < vertices; j++) {
            g->adjacency_matrix[i][j] = 0;
        }
    }
    return g;
}

void add_edge(struct graph* g, int src, int dest) {
    g->adjacency_matrix[src][dest] = 1;
    g->adjacency_matrix[dest][src] = 1;
}

void display_graph(struct graph* g) {
    int i, j;
    for (i = 0; i < g->vertices; i++) {
        for (j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct graph* g = create_graph(5, 6);
    add_edge(g, 0, 2);
    add_edge(g, 0, 3);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    printf("The adjacency matrix of the graph is:\n");
    display_graph(g);

    return 0;
}