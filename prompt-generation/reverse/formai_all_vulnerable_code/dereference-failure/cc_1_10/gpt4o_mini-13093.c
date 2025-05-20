//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 20

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int node_count;
} Network;

Node* create_node(const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH - 1);
    new_node->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    new_node->connection_count = 0;
    return new_node;
}

void add_node(Network* network, const char* name) {
    if (network->node_count < MAX_NODES) {
        network->nodes[network->node_count] = create_node(name);
        network->node_count++;
    } else {
        printf("Network is full, cannot add more nodes.\n");
    }
}

void connect_nodes(Node* node1, Node* node2) {
    if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1; // Bi-directional
    } else {
        printf("You cannot connect more nodes from %s or %s\n", node1->name, node2->name);
    }
}

void print_network(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("Node: %s - Connections: ", node->name);
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
}

int main() {
    Network network = { .node_count = 0 };

    add_node(&network, "Router1");
    add_node(&network, "Switch1");
    add_node(&network, "Server1");
    add_node(&network, "PC1");
    add_node(&network, "PC2");

    connect_nodes(network.nodes[0], network.nodes[1]); // Router1 <-> Switch1
    connect_nodes(network.nodes[1], network.nodes[2]); // Switch1 <-> Server1
    connect_nodes(network.nodes[1], network.nodes[3]); // Switch1 <-> PC1
    connect_nodes(network.nodes[1], network.nodes[4]); // Switch1 <-> PC2

    printf("Current Network Topology:\n");
    print_network(&network);

    cleanup(&network);
    return 0;
}