//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

typedef struct _graph {
    int num_nodes;
    node **nodes;
} graph;

graph *create_graph(int num_nodes) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->nodes = (node **)malloc(sizeof(node *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        g->nodes[i] = NULL;
    }
    return g;
}

node *create_node(int data) {
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void add_edge(graph *g, int src, int dst) {
    if (src < 0 || src >= g->num_nodes || dst < 0 || dst >= g->num_nodes) {
        printf("Invalid edge (%d, %d)\n", src, dst);
    } else {
        node *new_node = create_node(dst);
        new_node->next = g->nodes[src];
        g->nodes[src] = new_node;
    }
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: ", i);
        node *curr = g->nodes[i];
        while (curr) {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int num_nodes = 5;
    graph *g = create_graph(num_nodes);

    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    printf("Graph:\n");
    print_graph(g);

    return 0;
}