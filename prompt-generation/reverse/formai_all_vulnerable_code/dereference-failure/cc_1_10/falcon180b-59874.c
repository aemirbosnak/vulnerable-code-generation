//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_NODES 10
#define NUM_EDGES 20
#define NUM_LABELS 30

typedef struct {
    int label;
    int node1;
    int node2;
    int weight;
} Edge;

typedef struct {
    int label;
    int degree;
    int *neighbors;
} Node;

Edge edges[NUM_EDGES];
Node nodes[NUM_NODES];

void init_nodes() {
    for (int i = 0; i < NUM_NODES; i++) {
        nodes[i].label = rand() % NUM_LABELS + 1;
        nodes[i].degree = rand() % 5 + 1;
        nodes[i].neighbors = malloc(nodes[i].degree * sizeof(int));
        for (int j = 0; j < nodes[i].degree; j++) {
            nodes[i].neighbors[j] = rand() % NUM_NODES + 1;
        }
    }
}

void init_edges() {
    for (int i = 0; i < NUM_EDGES; i++) {
        edges[i].label = rand() % NUM_LABELS + 1;
        edges[i].node1 = rand() % NUM_NODES + 1;
        edges[i].node2 = rand() % NUM_NODES + 1;
        edges[i].weight = rand() % 10 + 1;
    }
}

void print_graph() {
    for (int i = 0; i < NUM_NODES; i++) {
        printf("%d - %d\n", i + 1, nodes[i].label);
        for (int j = 0; j < nodes[i].degree; j++) {
            printf("\t%d\n", nodes[i].neighbors[j]);
        }
    }
}

int main() {
    srand(time(NULL));
    init_nodes();
    init_edges();
    print_graph();
    return 0;
}