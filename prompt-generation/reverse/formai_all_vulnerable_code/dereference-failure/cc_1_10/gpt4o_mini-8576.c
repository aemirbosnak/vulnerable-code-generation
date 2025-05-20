//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
    struct Node* connections[MAX_NODES];
    int conn_count;
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int node_count;
} Network;

void init_network(Network* network) {
    network->node_count = 0;
}

Node* create_node(Network* network, const char* name) {
    if (network->node_count >= MAX_NODES) {
        printf("Maximum node limit reached!\n");
        return NULL;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LEN);
    new_node->conn_count = 0;

    network->nodes[network->node_count++] = new_node;
    return new_node;
}

void connect_nodes(Node* a, Node* b) {
    if (a->conn_count < MAX_NODES && b->conn_count < MAX_NODES) {
        a->connections[a->conn_count++] = b;
        b->connections[b->conn_count++] = a; // bidirectional connection
    } else {
        printf("Connection limit exceeded for node %s or %s\n", a->name, b->name);
    }
}

void display_network(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("Node %s connected to: ", node->name);
        for (int j = 0; j < node->conn_count; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void free_network(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
}

int main() {
    Network network;
    init_network(&network);

    // Configurable network structure
    create_node(&network, "Router");
    create_node(&network, "Switch1");
    create_node(&network, "Switch2");
    create_node(&network, "PC1");
    create_node(&network, "PC2");
    create_node(&network, "PC3");
    create_node(&network, "Server");

    // Adding connections
    connect_nodes(network.nodes[0], network.nodes[1]); // Router to Switch1
    connect_nodes(network.nodes[0], network.nodes[2]); // Router to Switch2
    connect_nodes(network.nodes[1], network.nodes[3]); // Switch1 to PC1
    connect_nodes(network.nodes[1], network.nodes[4]); // Switch1 to PC2
    connect_nodes(network.nodes[2], network.nodes[5]); // Switch2 to PC3
    connect_nodes(network.nodes[2], network.nodes[6]); // Switch2 to Server

    // Display the network topology
    display_network(&network);

    // Free allocated memory
    free_network(&network);

    return 0;
}