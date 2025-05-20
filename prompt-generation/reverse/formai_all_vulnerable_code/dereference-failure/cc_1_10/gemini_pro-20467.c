//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    int num_vertices;
    int num_edges;
    node **adj_list;
} graph;

graph *create_graph(int num_vertices) {
    graph *g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    g->adj_list = malloc(num_vertices * sizeof(node *));
    return g;
}

void add_edge(graph *g, int src, int dst) {
    node *new_node = malloc(sizeof(node));
    new_node->data = dst;
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;
    g->num_edges++;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);
        node *curr = g->adj_list[i];
        while (curr != NULL) {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

void dfs(graph *g, int start, int *visited) {
    visited[start] = 1;
    printf("%d ", start);
    node *curr = g->adj_list[start];
    while (curr != NULL) {
        if (!visited[curr->data]) {
            dfs(g, curr->data, visited);
        }
        curr = curr->next;
    }
}

int main() {
    graph *g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);

    print_graph(g);

    printf("DFS: ");
    int *visited = calloc(g->num_vertices, sizeof(int));
    dfs(g, 0, visited);
    printf("\n");

    return 0;
}