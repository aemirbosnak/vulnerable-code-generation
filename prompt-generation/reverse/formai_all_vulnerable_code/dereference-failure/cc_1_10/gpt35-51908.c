//FormAI DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct edge {
    int vertex;
    struct edge *next;
} edge;

typedef struct graph {
    edge *vertices[MAX_VERTICES];
    int num_vertices;
} graph;

graph* create_graph() {
    graph *g = (graph*) malloc(sizeof(graph));
    g->num_vertices = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->vertices[i] = NULL;
    }
    return g;
}

void add_vertex(graph *g) {
    g->num_vertices++;
}

void add_edge(graph *g, int u, int v) {
    edge *e = (edge*) malloc(sizeof(edge));
    e->vertex = v;
    e->next = g->vertices[u];
    g->vertices[u] = e;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        edge *e = g->vertices[i];
        while (e != NULL) {
            printf("%d ", e->vertex);
            e = e->next;
        }
        printf("\n");
    }
}

int main() {
    graph *g = create_graph();

    add_vertex(g);
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);

    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    printf("Graph Representation:\n");
    print_graph(g);

    return 0;
}