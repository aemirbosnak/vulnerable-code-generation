//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 20
#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int node_count;
} Network;

// Function to create a new node
Node* create_node(const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    new_node->connection_count = 0;
    return new_node;
}

// Function to add a node to the network
void add_node(Network* network, const char* name) {
    if (network->node_count < MAX_NODES) {
        Node* new_node = create_node(name);
        network->nodes[network->node_count++] = new_node;
        printf("Node %s added to the network.\n", name);
    } else {
        printf("Cannot add more nodes, network is full.\n");
    }
}

// Function to create a connection between nodes
void connect_nodes(Node* node1, Node* node2) {
    if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1; // assuming undirected connection
        printf("Connected %s with %s.\n", node1->name, node2->name);
    } else {
        printf("Connection limit reached for one of the nodes.\n");
    }
}

// Function to display network topology
void display_topology(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("Node: %s\n", node->name);
        printf("Connections: ");
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n\n");
    }
}

// Function to free memory of the network
void free_network(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->node_count = 0;

    // Adding nodes to the network
    add_node(network, "Router");
    add_node(network, "Switch");
    add_node(network, "Server");
    add_node(network, "PC1");
    add_node(network, "PC2");
    
    // Connecting nodes
    connect_nodes(network->nodes[0], network->nodes[1]); // Router to Switch
    connect_nodes(network->nodes[1], network->nodes[2]); // Switch to Server
    connect_nodes(network->nodes[1], network->nodes[3]); // Switch to PC1
    connect_nodes(network->nodes[1], network->nodes[4]); // Switch to PC2

    // Display the network topology
    printf("Network Topology:\n");
    display_topology(network);

    // Free allocated memory
    free_network(network);

    return 0;
}