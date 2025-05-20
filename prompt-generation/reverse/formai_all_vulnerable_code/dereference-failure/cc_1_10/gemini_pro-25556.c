//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    int num_vertices;
    int num_edges;
    struct node **adj_list;
} graph;

graph *create_graph(int num_vertices, int num_edges) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;
    g->adj_list = (node **)malloc(sizeof(node *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = NULL;
    }
    return g;
}

void add_edge(graph *g, int u, int v) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = g->adj_list[u];
    g->adj_list[u] = new_node;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);
        node *curr = g->adj_list[i];
        while (curr) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

bool is_connected(graph *g, int u, int v) {
    node *curr = g->adj_list[u];
    while (curr) {
        if (curr->data == v) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int main() {
    graph *g = create_graph(5, 6);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    print_graph(g);
    printf("Are vertices 0 and 3 connected? %s\n", is_connected(g, 0, 3) ? "Yes" : "No");
    return 0;
}