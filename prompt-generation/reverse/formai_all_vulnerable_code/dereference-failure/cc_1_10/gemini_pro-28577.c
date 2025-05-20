//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct node {
    char *data;
    struct node *next;
} node_t;

typedef struct graph {
    node_t *nodes[MAX_NODES];
    int num_nodes;
} graph_t;

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        node_t *node = graph->nodes[i];
        printf("%s", node->data);
        while (node->next != NULL) {
            node = node->next;
            printf(" -> %s", node->data);
        }
        printf("\n");
    }
}

int main() {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_nodes = 0;

    // Add nodes to the graph
    node_t *node1 = malloc(sizeof(node_t));
    node1->data = "A";
    graph->nodes[graph->num_nodes++] = node1;

    node_t *node2 = malloc(sizeof(node_t));
    node2->data = "B";
    graph->nodes[graph->num_nodes++] = node2;

    node_t *node3 = malloc(sizeof(node_t));
    node3->data = "C";
    graph->nodes[graph->num_nodes++] = node3;

    // Add edges to the graph
    node1->next = node2;
    node2->next = node3;

    // Print the graph
    print_graph(graph);

    return 0;
}