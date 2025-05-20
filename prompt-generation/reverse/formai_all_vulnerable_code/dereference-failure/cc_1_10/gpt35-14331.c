//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

struct Node {
    int val;
    struct Edge *edges[MAX_EDGES];
};

struct Edge {
    struct Node *from;
    struct Node *to;
};

void simulate_circuit(struct Node *nodes[], int size) {
    // simulation code goes here
}

int main() {
    int size = 5;
    struct Node *nodes[MAX_NODES];

    // create nodes
    for (int i = 0; i < size; i++) {
        nodes[i] = malloc(sizeof(struct Node));
        nodes[i]->val = i * 2;
    }

    // connect nodes
    for (int i = 0; i < size - 1; i++) {
        struct Edge *edge = malloc(sizeof(struct Edge));
        edge->from = nodes[i];
        edge->to = nodes[i+1];
        nodes[i]->edges[0] = edge;
    }

    simulate_circuit(nodes, size);

    // free memory
    for (int i = 0; i < size; i++) {
        free(nodes[i]);
        if (nodes[i]->edges[0]) {
            free(nodes[i]->edges[0]);
        }
    }
    
    return 0;
}