//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
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

Node* create_node(const char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LEN);
    node->connection_count = 0;
    return node;
}

void add_node(Network* network, const char* name) {
    if (network->node_count < MAX_NODES) {
        Node* new_node = create_node(name);
        network->nodes[network->node_count++] = new_node;
        printf("Node '%s' added to the network.\n", name);
    } else {
        printf("Network is full! Cannot add more nodes.\n");
    }
}

void connect_nodes(Node* node1, Node* node2) {
    if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1; // assuming bidirectional connection
        printf("Connected '%s' to '%s'.\n", node1->name, node2->name);
    } else {
        printf("Cannot connect nodes, one of them might be full.\n");
    }
}

void print_network(Network* network) {
    printf("\nCurrent Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("Node: %s - Connections: ", node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s ", node->connections[j]->name);
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
    Network* my_network = create_network();
    
    add_node(my_network, "Router");
    add_node(my_network, "Switch");
    add_node(my_network, "Server");
    add_node(my_network, "PC1");
    add_node(my_network, "PC2");

    connect_nodes(my_network->nodes[0], my_network->nodes[1]); // Router <-> Switch
    connect_nodes(my_network->nodes[1], my_network->nodes[2]); // Switch <-> Server
    connect_nodes(my_network->nodes[1], my_network->nodes[3]); // Switch <-> PC1
    connect_nodes(my_network->nodes[1], my_network->nodes[4]); // Switch <-> PC2

    print_network(my_network);
    
    free_network(my_network);
    
    return 0;
}