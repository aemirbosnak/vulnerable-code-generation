//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 30
#define MAX_CONNECTIONS 5

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int numConnections;
    struct Node* connections[MAX_CONNECTIONS];
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int numNodes;
} Network;

Network* createNetwork() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->numNodes = 0;
    return network;
}

Node* addNode(Network* network, const char* name) {
    if (network->numNodes >= MAX_NODES) {
        printf("Max nodes reached. Cannot add more nodes.\n");
        return NULL;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->numConnections = 0;
    network->nodes[network->numNodes++] = newNode;
    return newNode;
}

void connectNodes(Node* nodeA, Node* nodeB) {
    if (nodeA->numConnections >= MAX_CONNECTIONS || nodeB->numConnections >= MAX_CONNECTIONS) {
        printf("Connection limit reached for node %s or %s.\n", nodeA->name, nodeB->name);
        return;
    }
    nodeA->connections[nodeA->numConnections++] = nodeB;
    nodeB->connections[nodeB->numConnections++] = nodeA; // Assume bidirectional connection
}

void displayNetwork(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->numNodes; i++) {
        Node* node = network->nodes[i];
        printf("Node: %s connects to: ", node->name);
        for (int j = 0; j < node->numConnections; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Network* network) {
    for (int i = 0; i < network->numNodes; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network* myNetwork = createNetwork();
    
    addNode(myNetwork, "Router1");
    addNode(myNetwork, "Switch1");
    addNode(myNetwork, "Server1");
    addNode(myNetwork, "PC1");
    addNode(myNetwork, "PC2");
    
    if (myNetwork->numNodes > 0) {
        connectNodes(myNetwork->nodes[0], myNetwork->nodes[1]); // Router1 <-> Switch1
        connectNodes(myNetwork->nodes[1], myNetwork->nodes[2]); // Switch1 <-> Server1
        connectNodes(myNetwork->nodes[1], myNetwork->nodes[3]); // Switch1 <-> PC1
        connectNodes(myNetwork->nodes[1], myNetwork->nodes[4]); // Switch1 <-> PC2
    }

    displayNetwork(myNetwork);

    freeNetwork(myNetwork);
    return 0;
}