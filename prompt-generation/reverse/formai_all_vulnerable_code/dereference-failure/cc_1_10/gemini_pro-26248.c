//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct edge {
    int dest;
    int weight;
    struct edge *next;
} edge;

typedef struct vertex {
    int value;
    struct edge *head;
} vertex;

typedef struct graph {
    int num_vertices;
    struct vertex *vertices;
} graph;

graph *create_graph(int num_vertices) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->vertices = (vertex *)malloc(sizeof(vertex) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g->vertices[i].value = i;
        g->vertices[i].head = NULL;
    }
    return g;
}

void add_edge(graph *g, int source, int dest, int weight) {
    edge *e = (edge *)malloc(sizeof(edge));
    e->dest = dest;
    e->weight = weight;
    e->next = g->vertices[source].head;
    g->vertices[source].head = e;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d:\n", g->vertices[i].value);
        edge *e = g->vertices[i].head;
        while (e != NULL) {
            printf("  Edge to %d (weight %d)\n", e->dest, e->weight);
            e = e->next;
        }
    }
}

int main() {
    graph *g = create_graph(5);
    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 2, 20);
    add_edge(g, 1, 2, 30);
    add_edge(g, 1, 3, 40);
    add_edge(g, 2, 3, 50);
    add_edge(g, 3, 4, 60);
    print_graph(g);
    return 0;
}