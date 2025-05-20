//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
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

Node* create_node(const char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->neighbor_count = 0;
    return node;
}

void add_node(Network* network, const char* name) {
    if (network->node_count < MAX_NODES) {
        Node* node = create_node(name);
        network->nodes[network->node_count++] = node;
    } else {
        printf("Cannot add more nodes to the network.\n");
    }
}

void add_edge(Node* a, Node* b) {
    if (a->neighbor_count < MAX_NODES && b->neighbor_count < MAX_NODES) {
        a->neighbors[a->neighbor_count++] = b;
        b->neighbors[b->neighbor_count++] = a; // Undirected edge
    } else {
        printf("Cannot add more edges from node %s\n", a->name);
    }
}

void print_network(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("%s -> ", node->name);
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

void remove_node(Network* network, const char* name) {
    for (int i = 0; i < network->node_count; i++) {
        if (strcmp(network->nodes[i]->name, name) == 0) {
            // Remove the node from neighbors' lists
            for (int j = 0; j < network->node_count; j++) {
                if (j != i) {
                    Node* neighbor = network->nodes[j];
                    for (int k = 0; k < neighbor->neighbor_count; k++) {
                        if (strcmp(neighbor->neighbors[k]->name, name) == 0) {
                            neighbor->neighbors[k] = neighbor->neighbors[--neighbor->neighbor_count];
                            break;
                        }
                    }
                }
            }
            // Shift remaining nodes down
            free(network->nodes[i]);
            for (int j = i; j < network->node_count - 1; j++) {
                network->nodes[j] = network->nodes[j + 1];
            }
            network->node_count--;
            printf("Node %s removed from the network.\n", name);
            return;
        }
    }
    printf("Node %s not found in the network.\n", name);
}

int main() {
    Network* network = create_network();

    // Add nodes
    add_node(network, "Router1");
    add_node(network, "Switch1");
    add_node(network, "Server1");
    add_node(network, "PC1");
    add_node(network, "PC2");

    // Add edges
    add_edge(network->nodes[0], network->nodes[1]); // Router1 <-> Switch1
    add_edge(network->nodes[1], network->nodes[2]); // Switch1 <-> Server1
    add_edge(network->nodes[1], network->nodes[3]); // Switch1 <-> PC1
    add_edge(network->nodes[1], network->nodes[4]); // Switch1 <-> PC2

    // Print network
    print_network(network);

    // Remove a node and reprint network
    remove_node(network, "PC1");
    print_network(network);

    // Free the network resources
    free_network(network);
    
    return 0;
}