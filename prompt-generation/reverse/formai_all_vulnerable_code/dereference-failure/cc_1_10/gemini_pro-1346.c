//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct graph {
    int num_vertices;
    int num_edges;
    struct node *adj_list;
} graph;

graph *create_graph(int num_vertices) {
    graph *g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    g->adj_list = malloc(sizeof(node) * num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i].data = i;
        g->adj_list[i].next = NULL;
        g->adj_list[i].prev = NULL;
    }

    return g;
}

void add_edge(graph *g, int src, int dest) {
    if (src < 0 || src >= g->num_vertices || dest < 0 || dest >= g->num_vertices) {
        return;
    }

    node *new_node = malloc(sizeof(node));
    new_node->data = dest;
    new_node->next = g->adj_list[src].next;
    new_node->prev = &g->adj_list[src];

    if (g->adj_list[src].next != NULL) {
        g->adj_list[src].next->prev = new_node;
    }

    g->adj_list[src].next = new_node;
    g->num_edges++;
}

void remove_edge(graph *g, int src, int dest) {
    if (src < 0 || src >= g->num_vertices || dest < 0 || dest >= g->num_vertices) {
        return;
    }

    node *current_node = g->adj_list[src].next;

    while (current_node != NULL) {
        if (current_node->data == dest) {
            if (current_node->prev != NULL) {
                current_node->prev->next = current_node->next;
            }

            if (current_node->next != NULL) {
                current_node->next->prev = current_node->prev;
            }

            free(current_node);
            g->num_edges--;
            return;
        }

        current_node = current_node->next;
    }
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);

        node *current_node = g->adj_list[i].next;

        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }

        printf("\n");
    }
}

void free_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        node *current_node = g->adj_list[i].next;

        while (current_node != NULL) {
            node *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }

    free(g->adj_list);
    free(g);
}

int main() {
    graph *g = create_graph(5);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);

    print_graph(g);

    remove_edge(g, 1, 3);
    remove_edge(g, 2, 4);

    print_graph(g);

    free_graph(g);

    return 0;
}