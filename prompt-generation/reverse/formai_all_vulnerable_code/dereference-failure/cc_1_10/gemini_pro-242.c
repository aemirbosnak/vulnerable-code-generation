//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct graph {
    int num_vertices;
    int num_edges;
    node_t **adj_list;
} graph_t;

typedef struct edge {
    int src;
    int dest;
    int weight;
} edge_t;

graph_t *create_graph(int num_vertices) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_list = malloc(sizeof(node_t *) * num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

void add_edge(graph_t *graph, int src, int dest, int weight) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = dest;
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    graph->num_edges++;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *current_node = graph->adj_list[i];
        printf("%d: ", i);
        while (current_node != NULL) {
            printf("%d -> ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

int main() {
    graph_t *graph = create_graph(5);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 20);
    add_edge(graph, 1, 2, 30);
    add_edge(graph, 1, 3, 40);
    add_edge(graph, 2, 3, 50);
    add_edge(graph, 2, 4, 60);
    add_edge(graph, 3, 4, 70);

    print_graph(graph);

    return 0;
}