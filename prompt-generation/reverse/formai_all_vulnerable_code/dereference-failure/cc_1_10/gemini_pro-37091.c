//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct graph {
    int num_vertices;
    struct node **adj_list;
};

struct graph *create_graph(int num_vertices) {
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    if (g == NULL) {
        return NULL;
    }

    g->num_vertices = num_vertices;
    g->adj_list = (struct node **)malloc(sizeof(struct node *) * num_vertices);
    if (g->adj_list == NULL) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = NULL;
    }

    return g;
}

void add_edge(struct graph *g, int src, int dest) {
    if (src < 0 || src >= g->num_vertices || dest < 0 || dest >= g->num_vertices) {
        return;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return;
    }

    new_node->data = dest;
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;
}

void print_graph(struct graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        struct node *curr = g->adj_list[i];
        while (curr != NULL) {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct graph *g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    print_graph(g);

    return 0;
}