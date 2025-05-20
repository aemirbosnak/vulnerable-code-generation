//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    int degree;
    struct node* neighbors[MAX_EDGES];
} node_t;

typedef struct edge {
    int source;
    int destination;
} edge_t;

node_t* create_node(int id) {
    node_t* n = (node_t*) malloc(sizeof(node_t));
    n->id = id;
    n->degree = 0;
    return n;
}

edge_t* create_edge(int source, int destination) {
    edge_t* e = (edge_t*) malloc(sizeof(edge_t));
    e->source = source;
    e->destination = destination;
    return e;
}

void add_edge(node_t* source, node_t* destination) {
    source->degree++;
    source->neighbors[source->degree] = destination;
}

void print_network(node_t* root) {
    if (root == NULL) {
        return;
    }

    printf("%d (%d) -> ", root->id, root->degree);
    for (int i = 0; i < root->degree; i++) {
        printf("%d ", root->neighbors[i]->id);
    }
    printf("\n");

    for (int i = 0; i < root->degree; i++) {
        print_network(root->neighbors[i]);
    }
}

int main() {
    srand(time(NULL));

    // Create a network of 10 nodes
    node_t* nodes[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = create_node(i);
    }

    // Add edges randomly
    for (int i = 0; i < MAX_EDGES; i++) {
        int source = rand() % MAX_NODES;
        int destination = rand() % MAX_NODES;
        add_edge(nodes[source], nodes[destination]);
    }

    // Print the network
    print_network(nodes[0]);

    return 0;
}