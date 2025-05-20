//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct graph {
    int num_vertices;
    node_t **adj_list;
} graph_t;

graph_t *create_graph(int num_vertices) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->adj_list = malloc(sizeof(node_t *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }
    return graph;
}

void add_edge(graph_t *graph, int src, int dest) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = dest;
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *curr = graph->adj_list[i];
        printf("Vertex %d: ", i);
        while (curr != NULL) {
            printf("%d ", curr->data);
            curr = curr->next;
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
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    print_graph(graph);

    return 0;
}