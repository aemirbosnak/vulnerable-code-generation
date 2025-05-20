//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int id;
    struct Node* connections[MAX_NODES];
    int connection_count;
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

Node* create_node(const char* name, int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->id = id;
    node->connection_count = 0;
    return node;
}

int add_node(Network* network, Node* node) {
    if (network->node_count < MAX_NODES) {
        network->nodes[network->node_count++] = node;
        return 1;
    }
    return 0;
}

int connect_nodes(Node* node1, Node* node2) {
    if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1;  // Undirected connection
        return 1;
    }
    return 0;
}

void print_network(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("Node %d: %s\n", node->id, node->name);
        printf("  Connections: ");
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void cleanup(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network* network = create_network();

    Node* nodeA = create_node("Router A", 0);
    Node* nodeB = create_node("Router B", 1);
    Node* nodeC = create_node("Switch C", 2);
    Node* nodeD = create_node("Server D", 3);
    Node* nodeE = create_node("PC E", 4);

    add_node(network, nodeA);
    add_node(network, nodeB);
    add_node(network, nodeC);
    add_node(network, nodeD);
    add_node(network, nodeE);

    connect_nodes(nodeA, nodeB);
    connect_nodes(nodeA, nodeC);
    connect_nodes(nodeB, nodeC);
    connect_nodes(nodeC, nodeD);
    connect_nodes(nodeD, nodeE);

    print_network(network);
    
    cleanup(network);
    return 0;
}