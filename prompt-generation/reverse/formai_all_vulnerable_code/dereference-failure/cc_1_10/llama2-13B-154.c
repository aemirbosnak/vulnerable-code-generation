//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NODES 100
#define EDGE_WEIGHT_MAX 100

typedef struct node {
    int label;
    int weight;
    struct node *next;
} Node;

typedef struct graph {
    Node *nodes;
    int num_nodes;
} Graph;

void init_graph(Graph *g) {
    g->nodes = malloc(MAX_NODES * sizeof(Node));
    g->num_nodes = 0;
}

void add_node(Graph *g, int label) {
    Node *new_node = malloc(sizeof(Node));
    new_node->label = label;
    new_node->weight = rand() % EDGE_WEIGHT_MAX;
    new_node->next = NULL;
    if (g->num_nodes == MAX_NODES) {
        printf("Error: Graph is full. Cannot add more nodes.\n");
        return;
    }
    g->nodes[g->num_nodes] = *new_node;
    g->num_nodes++;
}

void add_edge(Graph *g, int from, int to) {
    Node *from_node = g->nodes + from;
    Node *to_node = g->nodes + to;
    from_node->weight += to_node->weight;
    from_node->next = to_node;
}

void print_graph(Graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        Node *node = g->nodes + i;
        printf("Node %d: label %d, weight %d, next %p\n", i, node->label, node->weight, node->next);
    }
}

int main() {
    srand(time(NULL));
    Graph g;
    init_graph(&g);

    // Add some nodes
    for (int i = 0; i < 10; i++) {
        add_node(&g, i % 2 ? 10 : 20);
    }

    // Add some edges
    for (int i = 0; i < 20; i++) {
        add_edge(&g, rand() % 10, rand() % 10);
    }

    // Print the graph
    print_graph(&g);

    return 0;
}