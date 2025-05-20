//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct graph {
    int num_vertices;
    int num_edges;
    node_t **adj_lists;
} graph_t;

graph_t *create_graph(int num_vertices) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_lists = malloc(sizeof(node_t *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_lists[i] = NULL;
    }
    return graph;
}

void destroy_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *node = graph->adj_lists[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node);
            node = next;
        }
    }
    free(graph->adj_lists);
    free(graph);
}

void add_edge(graph_t *graph, int v1, int v2) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = v2;
    new_node->next = graph->adj_lists[v1];
    graph->adj_lists[v1] = new_node;
    graph->num_edges++;
}

bool is_edge(graph_t *graph, int v1, int v2) {
    node_t *node = graph->adj_lists[v1];
    while (node != NULL) {
        if (node->data == v2) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *node = graph->adj_lists[i];
        printf("%d: ", i);
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    graph_t *graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    printf("Graph:\n");
    print_graph(graph);

    printf("Is there an edge between 0 and 2? %s\n", is_edge(graph, 0, 2) ? "yes" : "no");
    printf("Is there an edge between 1 and 4? %s\n", is_edge(graph, 1, 4) ? "yes" : "no");

    destroy_graph(graph);
    return 0;
}