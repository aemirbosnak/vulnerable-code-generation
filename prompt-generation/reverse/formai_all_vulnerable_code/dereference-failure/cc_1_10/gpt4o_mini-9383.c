//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_NAME_LENGTH 30

// Structure to represent a Node in the network
typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int id;
    struct Node* neighbors[MAX_NODES];
    int neighborCount;
} Node;

// Structure to represent the Network Topology
typedef struct Network {
    Node* nodes[MAX_NODES];
    int nodeCount;
} Network;

// Function declarations
void addNode(Network* network, const char* name);
void addConnection(Network* network, int id1, int id2);
void displayNetwork(const Network* network);
void printConnections(const Node* node);
void freeNetwork(Network* network);

int main() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->nodeCount = 0;

    addNode(network, "Router1");
    addNode(network, "Switch1");
    addNode(network, "PC1");
    addNode(network, "PC2");
    addNode(network, "Server1");

    addConnection(network, 0, 1); // Router1 <-> Switch1
    addConnection(network, 1, 2); // Switch1 <-> PC1
    addConnection(network, 1, 3); // Switch1 <-> PC2
    addConnection(network, 0, 4); // Router1 <-> Server1

    displayNetwork(network);
    
    freeNetwork(network);
    return 0;
}

// Function to add a node to the network
void addNode(Network* network, const char* name) {
    if (network->nodeCount < MAX_NODES) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        strncpy(newNode->name, name, MAX_NAME_LENGTH);
        newNode->id = network->nodeCount;
        newNode->neighborCount = 0;
        network->nodes[network->nodeCount] = newNode;
        network->nodeCount++;
    } else {
        printf("Network is full! Cannot add more nodes.\n");
    }
}

// Function to add a connection between two nodes
void addConnection(Network* network, int id1, int id2) {
    if (id1 < network->nodeCount && id2 < network->nodeCount) {
        Node* node1 = network->nodes[id1];
        Node* node2 = network->nodes[id2];

        // Avoid duplicate connections
        for (int i = 0; i < node1->neighborCount; i++) {
            if (node1->neighbors[i] == node2) {
                return; // Connection already exists
            }
        }

        node1->neighbors[node1->neighborCount++] = node2;
        node2->neighbors[node2->neighborCount++] = node1; // Bi-directional connection
    } else {
        printf("Invalid node IDs for connection!\n");
    }
}

// Function to display the current network topology
void displayNetwork(const Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->nodeCount; i++) {
        printf("Node %d: %s\n", i, network->nodes[i]->name);
        printConnections(network->nodes[i]);
    }
}

// Function to print connections of a node
void printConnections(const Node* node) {
    printf("  Connections: ");
    for (int i = 0; i < node->neighborCount; i++) {
        printf("%s ", node->neighbors[i]->name);
    }
    printf("\n");
}

// Function to free the allocated memory in network
void freeNetwork(Network* network) {
    for (int i = 0; i < network->nodeCount; i++) {
        free(network->nodes[i]);
    }
    free(network);
}