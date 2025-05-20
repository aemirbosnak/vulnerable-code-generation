//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    int id;
    char name[MAX_NAME_LEN];
    struct Node* neighbors[MAX_NODES];
    int neighbor_count;
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int node_count;
} Network;

Network* create_network() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->node_count = 0;
    return network;
}

Node* create_node(int id, const char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    strncpy(node->name, name, MAX_NAME_LEN);
    node->neighbor_count = 0;
    return node;
}

void add_node(Network* network, Node* node) {
    if (network->node_count < MAX_NODES) {
        network->nodes[network->node_count++] = node;
    } else {
        printf("Network is full, cannot add node %s\n", node->name);
    }
}

void add_edge(Node* src, Node* dest) {
    if (src->neighbor_count < MAX_NODES) {
        src->neighbors[src->neighbor_count++] = dest;
    } else {
        printf("Node %s has reached its neighbor limit\n", src->name);
    }
}

void print_network(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("Node ID: %d, Name: %s, Neighbors: ", node->id, node->name);
        for (int j = 0; j < node->neighbor_count; j++) {
            printf("%s ", node->neighbors[j]->name);
        }
        printf("\n");
    }
}

void free_network(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network* myNetwork = create_network();

    Node* router1 = create_node(1, "Router1");
    Node* router2 = create_node(2, "Router2");
    Node* switch1 = create_node(3, "Switch1");
    Node* server1 = create_node(4, "Server1");
    Node* server2 = create_node(5, "Server2");

    add_node(myNetwork, router1);
    add_node(myNetwork, router2);
    add_node(myNetwork, switch1);
    add_node(myNetwork, server1);
    add_node(myNetwork, server2);

    add_edge(router1, switch1);
    add_edge(router2, switch1);
    add_edge(switch1, server1);
    add_edge(switch1, server2);

    print_network(myNetwork);

    free_network(myNetwork);
    return 0;
}