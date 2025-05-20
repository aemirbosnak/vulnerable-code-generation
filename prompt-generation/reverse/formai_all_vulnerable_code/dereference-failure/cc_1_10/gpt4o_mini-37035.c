//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
    int id;
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int node_count;
} Network;

// Function prototypes
Network* create_network();
void add_node(Network* network, const char* name);
void connect_nodes(Network* network, int id1, int id2);
void display_network(Network* network);
void free_network(Network* network);

int main() {
    Network* network = create_network();

    // Adding nodes to the network
    add_node(network, "Router");
    add_node(network, "Switch 1");
    add_node(network, "Switch 2");
    add_node(network, "PC 1");
    add_node(network, "PC 2");
    
    // Creating connections
    connect_nodes(network, 0, 1); // Router -> Switch 1
    connect_nodes(network, 0, 2); // Router -> Switch 2
    connect_nodes(network, 1, 3); // Switch 1 -> PC 1
    connect_nodes(network, 1, 4); // Switch 1 -> PC 2
    connect_nodes(network, 2, 4); // Switch 2 -> PC 2

    // Display the network topology
    display_network(network);
    
    // Free the allocated memory
    free_network(network);

    return 0;
}

Network* create_network() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->node_count = 0;
    return network;
}

void add_node(Network* network, const char* name) {
    if (network->node_count < MAX_NODES) {
        Node* node = (Node*)malloc(sizeof(Node));
        strncpy(node->name, name, MAX_NAME_LEN);
        node->id = network->node_count;
        node->connection_count = 0;
        network->nodes[network->node_count++] = node;
    } else {
        printf("Network is full, cannot add more nodes.\n");
    }
}

void connect_nodes(Network* network, int id1, int id2) {
    if (id1 >= 0 && id1 < network->node_count && id2 >= 0 && id2 < network->node_count) {
        Node* node1 = network->nodes[id1];
        Node* node2 = network->nodes[id2];
        
        if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
            node1->connections[node1->connection_count++] = node2;
            node2->connections[node2->connection_count++] = node1; // Assuming bidirectional connection
        } else {
            printf("Connection limit reached for one of the nodes: %s (%d) or %s (%d).\n",
                   node1->name, node1->id, node2->name, node2->id);
        }
    } else {
        printf("Invalid node ID(s): %d and %d.\n", id1, id2);
    }
}

void display_network(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("Node %d (%s) is connected to: ", node->id, node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s (%d)", node->connections[j]->name, node->connections[j]->id);
            if (j < node->connection_count - 1) {
                printf(", ");
            }
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