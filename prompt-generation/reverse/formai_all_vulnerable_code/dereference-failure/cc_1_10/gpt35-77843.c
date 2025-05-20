//FormAI DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct graph {
    int size;
    int *visited;
    struct node **adj_list;
};

struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

struct graph *create_graph(int size) {
    struct graph *new_graph = malloc(sizeof(struct graph));
    new_graph->size = size;
    new_graph->visited = calloc(size, sizeof(int));
    new_graph->adj_list = calloc(size, sizeof(struct node *));
    return new_graph;
}

void add_edge(struct graph *g, int src, int dest) {
    struct node *new_node = create_node(dest);
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;
}

void print_graph(struct graph *g) {
    for (int i = 0; i < g->size; i++) {
        struct node *curr = g->adj_list[i];
        printf("%d: ", i);
        while (curr) {
            printf("%d->", curr->value);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct graph *g = create_graph(4);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 0);
    add_edge(g, 2, 3);
    add_edge(g, 3, 3);

    print_graph(g);

    return 0;
}