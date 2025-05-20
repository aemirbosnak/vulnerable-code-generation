//Falcon-180B DATASET v1.0 Category: Data mining ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_NODES 1000
#define MAX_NUM_EDGES 10000

typedef struct node {
    int id;
    int num_edges;
    struct edge *edges;
} Node;

typedef struct edge {
    int src_id;
    int dest_id;
    int weight;
} Edge;

int num_nodes = 0;
int num_edges = 0;
Node *nodes = NULL;
Edge *edges = NULL;

void add_node(int id) {
    num_nodes++;
    nodes = (Node *)realloc(nodes, sizeof(Node) * num_nodes);
    nodes[num_nodes - 1].id = id;
    nodes[num_nodes - 1].num_edges = 0;
    nodes[num_nodes - 1].edges = NULL;
}

void add_edge(int src_id, int dest_id, int weight) {
    num_edges++;
    edges = (Edge *)realloc(edges, sizeof(Edge) * num_edges);
    edges[num_edges - 1].src_id = src_id;
    edges[num_edges - 1].dest_id = dest_id;
    edges[num_edges - 1].weight = weight;
}

int main() {
    int num_nodes = 5;
    int num_edges = 6;
    int i, j;

    // Add nodes
    for (i = 0; i < num_nodes; i++) {
        add_node(i);
    }

    // Add edges
    add_edge(0, 1, 2);
    add_edge(0, 2, 3);
    add_edge(1, 2, 1);
    add_edge(1, 4, 1);
    add_edge(2, 3, 2);
    add_edge(2, 4, 2);

    // Print the graph
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        for (j = 0; j < nodes[i].num_edges; j++) {
            printf("(%d, %d) ", nodes[i].edges[j].src_id, nodes[i].edges[j].dest_id);
        }
        printf("\n");
    }

    return 0;
}