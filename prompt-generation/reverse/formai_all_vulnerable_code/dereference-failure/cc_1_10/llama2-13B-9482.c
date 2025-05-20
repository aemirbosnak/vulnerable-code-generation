//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define GRAPH_MAX_NODES 100
#define GRAPH_MAX_EDGES 200

typedef struct node {
    int label;
    struct node* next;
    struct node* prev;
} Node;

typedef struct graph {
    Node* nodes;
    int num_nodes;
    int num_edges;
} Graph;

void init_graph(Graph* g) {
    g->nodes = malloc(GRAPH_MAX_NODES * sizeof(Node));
    g->num_nodes = 0;
    g->num_edges = 0;
}

void add_node(Graph* g, int label) {
    Node* new_node = malloc(sizeof(Node));
    new_node->label = label;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (g->num_nodes == GRAPH_MAX_NODES) {
        printf("Oops, too many nodes! Maximum capacity reached.\n");
        return;
    }
    g->nodes[g->num_nodes] = *new_node;
    g->num_nodes++;
}

void add_edge(Graph* g, int label_a, int label_b) {
    int i = g->num_nodes;
    g->num_edges++;
    Node* a = g->nodes + i;
    a->next = g->nodes + i - 1;
    a->prev = NULL;
    a->label = label_a;
    Node* b = g->nodes + i - 1;
    b->next = a;
    b->prev = NULL;
    b->label = label_b;
}

void print_graph(Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        Node* node = g->nodes + i;
        printf("Node %d: %d\n", i, node->label);
        if (node->next != NULL) {
            printf("Next: %d\n", node->next->label);
        }
        if (node->prev != NULL) {
            printf("Prev: %d\n", node->prev->label);
        }
    }
}

int main() {
    Graph g;
    init_graph(&g);

    add_node(&g, 1);
    add_node(&g, 2);
    add_node(&g, 3);
    add_node(&g, 4);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);

    print_graph(&g);

    return 0;
}