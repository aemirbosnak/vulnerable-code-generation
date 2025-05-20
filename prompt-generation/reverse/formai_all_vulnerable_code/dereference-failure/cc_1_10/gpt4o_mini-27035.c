//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_NAME_LENGTH 30

typedef struct Node {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Node *connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Network {
    Node *nodes[MAX_NODES];
    int node_count;
} Network;

Network* create_network() {
    Network *network = malloc(sizeof(Network));
    network->node_count = 0;
    return network;
}

Node* create_node(int id, const char *name) {
    Node *node = malloc(sizeof(Node));
    node->id = id;
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->connection_count = 0;
    return node;
}

int add_node(Network *network, const char *name) {
    if (network->node_count >= MAX_NODES) {
        printf("Cannot add more nodes to the network.\n");
        return -1;
    }
    Node *node = create_node(network->node_count, name);
    network->nodes[network->node_count++] = node;
    return node->id;
}

void connect_nodes(Node *node1, Node *node2) {
    // Prevent self-connection and duplicate connections
    if (node1 == node2) {
        printf("Nodes cannot connect to themselves.\n");
        return;
    }
    for (int i = 0; i < node1->connection_count; i++) {
        if (node1->connections[i] == node2) {
            printf("Nodes %s and %s are already connected.\n", node1->name, node2->name);
            return;
        }
    }
    node1->connections[node1->connection_count++] = node2;
    node2->connections[node2->connection_count++] = node1; // For a bidirectional connection
}

void print_network(const Network *network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node *node = network->nodes[i];
        printf("Node %d (%s): ", node->id, node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void free_network(Network *network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network *network = create_network();

    add_node(network, "Router1");
    add_node(network, "Switch1");
    add_node(network, "PC1");
    add_node(network, "PC2");
    add_node(network, "Server1");

    connect_nodes(network->nodes[0], network->nodes[1]); // Router1 to Switch1
    connect_nodes(network->nodes[1], network->nodes[2]); // Switch1 to PC1
    connect_nodes(network->nodes[1], network->nodes[3]); // Switch1 to PC2
    connect_nodes(network->nodes[0], network->nodes[4]); // Router1 to Server1

    print_network(network);

    free_network(network);
    return 0;
}