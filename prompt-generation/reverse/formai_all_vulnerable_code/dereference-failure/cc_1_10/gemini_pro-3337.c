//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_NODES 1024
#define MAX_EDGES 1024
#define MAX_NETWORKS 1024

typedef struct node {
    uint32_t id;
    uint32_t num_edges;
    uint32_t *edges;
    uint32_t *weights;
} node_t;

typedef struct edge {
    uint32_t id;
    uint32_t node1;
    uint32_t node2;
    uint32_t weight;
} edge_t;

typedef struct network {
    uint32_t id;
    uint32_t num_nodes;
    uint32_t *nodes;
    uint32_t num_edges;
    uint32_t *edges;
} network_t;

node_t nodes[MAX_NODES];
edge_t edges[MAX_EDGES];
network_t networks[MAX_NETWORKS];

uint32_t num_nodes = 0;
uint32_t num_edges = 0;
uint32_t num_networks = 0;

void add_node(uint32_t id) {
    nodes[num_nodes].id = id;
    nodes[num_nodes].num_edges = 0;
    nodes[num_nodes].edges = NULL;
    nodes[num_nodes].weights = NULL;
    num_nodes++;
}

void add_edge(uint32_t id, uint32_t node1, uint32_t node2, uint32_t weight) {
    edges[num_edges].id = id;
    edges[num_edges].node1 = node1;
    edges[num_edges].node2 = node2;
    edges[num_edges].weight = weight;
    num_edges++;
}

void add_network(uint32_t id) {
    networks[num_networks].id = id;
    networks[num_networks].num_nodes = 0;
    networks[num_networks].nodes = NULL;
    networks[num_networks].num_edges = 0;
    networks[num_networks].edges = NULL;
    num_networks++;
}

void add_node_to_network(uint32_t network_id, uint32_t node_id) {
    networks[network_id].nodes = realloc(networks[network_id].nodes, (networks[network_id].num_nodes + 1) * sizeof(uint32_t));
    networks[network_id].nodes[networks[network_id].num_nodes] = node_id;
    networks[network_id].num_nodes++;
}

void add_edge_to_network(uint32_t network_id, uint32_t edge_id) {
    networks[network_id].edges = realloc(networks[network_id].edges, (networks[network_id].num_edges + 1) * sizeof(uint32_t));
    networks[network_id].edges[networks[network_id].num_edges] = edge_id;
    networks[network_id].num_edges++;
}

void print_network(uint32_t network_id) {
    printf("Network %u:\n", networks[network_id].id);
    printf("  Nodes:\n");
    for (uint32_t i = 0; i < networks[network_id].num_nodes; i++) {
        printf("    %u\n", networks[network_id].nodes[i]);
    }
    printf("  Edges:\n");
    for (uint32_t i = 0; i < networks[network_id].num_edges; i++) {
        printf("    %u\n", networks[network_id].edges[i]);
    }
}

int main() {
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);
    add_edge(1, 1, 2, 1);
    add_edge(2, 2, 3, 1);
    add_edge(3, 3, 4, 1);
    add_network(1);
    add_node_to_network(1, 1);
    add_node_to_network(1, 2);
    add_node_to_network(1, 3);
    add_node_to_network(1, 4);
    add_edge_to_network(1, 1);
    add_edge_to_network(1, 2);
    add_edge_to_network(1, 3);
    print_network(1);
    return 0;
}