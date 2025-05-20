//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct node_t {
    int id;
    int num_edges;
    struct edge_t* edges[MAX_EDGES];
} node_t;

typedef struct edge_t {
    int from_node;
    int to_node;
} edge_t;

node_t* create_node(int id) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->id = id;
    node->num_edges = 0;
    return node;
}

edge_t* create_edge(int from_node, int to_node) {
    edge_t* edge = (edge_t*)malloc(sizeof(edge_t));
    edge->from_node = from_node;
    edge->to_node = to_node;
    return edge;
}

void add_edge_to_node(node_t* node, int from_node, int to_node) {
    edge_t* edge = create_edge(from_node, to_node);
    node->num_edges++;
    node->edges[node->num_edges - 1] = edge;
}

void print_node(node_t* node) {
    printf("Node %d: ", node->id);
    for (int i = 0; i < node->num_edges; i++) {
        edge_t* edge = node->edges[i];
        printf("%d -> %d\n", edge->from_node, edge->to_node);
    }
}

int main() {
    node_t* node1 = create_node(1);
    add_edge_to_node(node1, 1, 2);
    add_edge_to_node(node1, 1, 3);
    print_node(node1);

    node_t* node2 = create_node(2);
    add_edge_to_node(node2, 2, 1);
    add_edge_to_node(node2, 2, 4);
    add_edge_to_node(node2, 2, 5);
    print_node(node2);

    node_t* node3 = create_node(3);
    add_edge_to_node(node3, 3, 1);
    add_edge_to_node(node3, 3, 2);
    add_edge_to_node(node3, 3, 4);
    print_node(node3);

    node_t* node4 = create_node(4);
    add_edge_to_node(node4, 4, 2);
    add_edge_to_node(node4, 4, 5);
    add_edge_to_node(node4, 4, 6);
    print_node(node4);

    node_t* node5 = create_node(5);
    add_edge_to_node(node5, 5, 2);
    add_edge_to_node(node5, 5, 3);
    add_edge_to_node(node5, 5, 4);
    add_edge_to_node(node5, 5, 6);
    print_node(node5);

    node_t* node6 = create_node(6);
    add_edge_to_node(node6, 6, 4);
    add_edge_to_node(node6, 6, 5);
    print_node(node6);

    return 0;
}