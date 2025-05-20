//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connectionCount;
} Node;

typedef struct NetworkTopology {
    Node* nodes[MAX_NODES];
    int nodeCount;
} NetworkTopology;

Node* createNode(char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->connectionCount = 0;
    return node;
}

void addConnection(Node* fromNode, Node* toNode) {
    if (fromNode->connectionCount < MAX_NODES) {
        fromNode->connections[fromNode->connectionCount++] = toNode;
    }
}

NetworkTopology* createTopology() {
    NetworkTopology* topology = (NetworkTopology*)malloc(sizeof(NetworkTopology));
    topology->nodeCount = 0;
    return topology;
}

void addNode(NetworkTopology* topology, Node* node) {
    if (topology->nodeCount < MAX_NODES) {
        topology->nodes[topology->nodeCount++] = node;
    }
}

void displayTopology(NetworkTopology* topology) {
    printf("Network Topology:\n");
    for (int i = 0; i < topology->nodeCount; i++) {
        Node* node = topology->nodes[i];
        printf("Node %s:\n", node->name);
        for (int j = 0; j < node->connectionCount; j++) {
            printf("  - Connected to %s\n", node->connections[j]->name);
        }
    }
}

void freeTopology(NetworkTopology* topology) {
    for (int i = 0; i < topology->nodeCount; i++) {
        free(topology->nodes[i]);
    }
    free(topology);
}

int main() {
    NetworkTopology* network = createTopology();
    
    // Adding nodes to the network
    Node* nodeA = createNode("Router_A");
    Node* nodeB = createNode("Switch_A");
    Node* nodeC = createNode("PC_A");
    Node* nodeD = createNode("Server_A");
    Node* nodeE = createNode("Router_B");
    
    addNode(network, nodeA);
    addNode(network, nodeB);
    addNode(network, nodeC);
    addNode(network, nodeD);
    addNode(network, nodeE);
    
    // Establishing connections
    addConnection(nodeA, nodeB);
    addConnection(nodeA, nodeE);
    addConnection(nodeB, nodeC);
    addConnection(nodeB, nodeD);
    addConnection(nodeE, nodeA);
    
    // Display the network topology
    displayTopology(network);
    
    // Clean up
    freeTopology(network);
    
    return 0;
}