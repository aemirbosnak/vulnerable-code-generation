//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct graph {
    int num_nodes;
    node_t *nodes[MAX_NODES];
} graph_t;

graph_t *create_graph(int num_nodes) {
    graph_t *graph = malloc(sizeof(graph_t));
    if (graph == NULL) {
        return NULL;
    }

    graph->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = NULL;
    }

    return graph;
}

void add_edge(graph_t *graph, int node1, int node2) {
    if (node1 < 0 || node1 >= graph->num_nodes ||
        node2 < 0 || node2 >= graph->num_nodes) {
        return;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    new_node->data = node2;
    new_node->next = graph->nodes[node1];
    graph->nodes[node1] = new_node;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d: ", i);
        node_t *current_node = graph->nodes[i];
        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        node_t *current_node = graph->nodes[i];
        while (current_node != NULL) {
            node_t *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }

    free(graph);
}

int main() {
    graph_t *graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    print_graph(graph);

    free_graph(graph);

    return 0;
}