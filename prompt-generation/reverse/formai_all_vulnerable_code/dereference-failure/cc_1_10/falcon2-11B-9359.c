//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int vertex;
    int color;
} VertexColorPair;

typedef struct {
    int num_vertices;
    int *adjacency_list;
} Graph;

Graph create_graph(int num_vertices) {
    Graph g;
    g.num_vertices = num_vertices;
    g.adjacency_list = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        g.adjacency_list[i] = 0;
    }
    return g;
}

void add_edge(Graph *g, int v, int w) {
    if (v < 0 || v >= g->num_vertices || w < 0 || w >= g->num_vertices) {
        fprintf(stderr, "Invalid vertex indices\n");
        exit(1);
    }
    g->adjacency_list[v]++;
    g->adjacency_list[w]++;
}

void print_graph(Graph g) {
    for (int i = 0; i < g.num_vertices; i++) {
        if (g.adjacency_list[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num_vertices = 7;
    Graph g = create_graph(num_vertices);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 0, 3);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 5);
    add_edge(&g, 3, 6);
    add_edge(&g, 4, 5);
    print_graph(g);
    return 0;
}