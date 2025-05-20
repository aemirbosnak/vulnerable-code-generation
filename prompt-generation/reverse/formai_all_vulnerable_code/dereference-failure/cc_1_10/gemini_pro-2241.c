//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct adj_list {
    int vertex;
    struct adj_list *next;
};

struct graph {
    int num_vertices;
    struct adj_list **adj_lists;
};

struct adj_list *new_adj_list(int vertex, struct adj_list *next) {
    struct adj_list *new = malloc(sizeof(struct adj_list));
    new->vertex = vertex;
    new->next = next;
    return new;
}

struct graph *new_graph(int num_vertices) {
    struct graph *g = malloc(sizeof(struct graph));
    g->num_vertices = num_vertices;
    g->adj_lists = malloc(sizeof(struct adj_list *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g->adj_lists[i] = NULL;
    }
    return g;
}

void add_edge(struct graph *g, int source, int destination) {
    struct adj_list *new = new_adj_list(destination, g->adj_lists[source]);
    g->adj_lists[source] = new;
}

void print_graph(struct graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        struct adj_list *current = g->adj_lists[i];
        printf("Vertex %d:\n", i);
        while (current != NULL) {
            printf("  %d\n", current->vertex);
            current = current->next;
        }
    }
}

int main() {
    struct graph *g = new_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 1);
    add_edge(g, 3, 4);
    add_edge(g, 4, 0);
    print_graph(g);
    return 0;
}