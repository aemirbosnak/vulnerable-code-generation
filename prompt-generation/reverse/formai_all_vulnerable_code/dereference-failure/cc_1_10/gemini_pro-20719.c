//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct graph {
    int V;
    int E;
    struct node **adj;
} graph_t;

graph_t *create_graph(int V, int E) {
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->V = V;
    g->E = E;
    g->adj = (node_t **)malloc(V * sizeof(node_t *));
    for (int i = 0; i < V; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

void add_edge(graph_t *g, int u, int v) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = v;
    new_node->next = g->adj[u];
    g->adj[u] = new_node;
}

void print_graph(graph_t *g) {
    for (int i = 0; i < g->V; i++) {
        node_t *temp = g->adj[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    int E = 7;
    graph_t *g = create_graph(V, E);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);
    add_edge(g, 4, 0);
    print_graph(g);
    return 0;
}