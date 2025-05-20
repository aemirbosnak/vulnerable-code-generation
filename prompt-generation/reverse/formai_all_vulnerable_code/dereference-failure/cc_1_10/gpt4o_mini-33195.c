//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int id;
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

Node* create_node(const char* name, int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->id = id;
    node->neighbor_count = 0;
    return node;
}

void add_node(Network* network, const char* name) {
    if(network->node_count < MAX_NODES) {
        Node* new_node = create_node(name, network->node_count);
        network->nodes[network->node_count++] = new_node;
        printf("Node added: %s (ID: %d)\n", name, new_node->id);
    } else {
        printf("Network is full, cannot add node: %s\n", name);
    }
}

void add_connection(Network* network, int id1, int id2) {
    if (id1 >= 0 && id1 < network->node_count && id2 >= 0 && id2 < network->node_count) {
        Node* node1 = network->nodes[id1];
        Node* node2 = network->nodes[id2];

        node1->neighbors[node1->neighbor_count++] = node2;
        node2->neighbors[node2->neighbor_count++] = node1;

        printf("Connection established between %s (ID: %d) and %s (ID: %d)\n", 
               node1->name, id1, node2->name, id2);
    } else {
        printf("Invalid node IDs: %d and %d\n", id1, id2);
    }
}

void display_network(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("Node %d: %s\n", node->id, node->name);
        printf("  Connected to: ");
        for (int j = 0; j < node->neighbor_count; j++) {
            printf("%s (ID: %d) ", node->neighbors[j]->name, node->neighbors[j]->id);
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
    
    add_node(myNetwork, "Router1");
    add_node(myNetwork, "Switch1");
    add_node(myNetwork, "Server1");
    
    add_connection(myNetwork, 0, 1); // Router1 - Switch1
    add_connection(myNetwork, 1, 2); // Switch1 - Server1
    
    display_network(myNetwork);
    
    free_network(myNetwork);
    
    return 0;
}