//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node **connections;
    int connectionCount;
} Node;

typedef struct Network {
    Node *nodes[MAX_NODES];
    int nodeCount;
} Network;

Network* createNetwork() {
    Network *network = (Network *)malloc(sizeof(Network));
    network->nodeCount = 0;
    return network;
}

Node* createNode(const char* name) {
    Node *node = (Node *)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->connections = (Node **)malloc(MAX_NODES * sizeof(Node*));
    node->connectionCount = 0;
    return node;
}

void addNode(Network *network, const char* name) {
    if (network->nodeCount < MAX_NODES) {
        network->nodes[network->nodeCount++] = createNode(name);
    } else {
        printf("Error: Maximum node limit reached.\n");
    }
}

void connectNodes(Node *node1, Node *node2) {
    if (node1->connectionCount < MAX_NODES && node2->connectionCount < MAX_NODES) {
        node1->connections[node1->connectionCount++] = node2;
        node2->connections[node2->connectionCount++] = node1;  // Assuming undirected connections
    } else {
        printf("Error: Connection limit exceeded.\n");
    }
}

void displayNetwork(Network *network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->nodeCount; i++) {
        Node *node = network->nodes[i];
        printf("Node: %s\n", node->name);
        printf("Connections: ");
        for (int j = 0; j < node->connectionCount; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Network *network) {
    for (int i = 0; i < network->nodeCount; i++) {
        free(network->nodes[i]->connections);
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network *myNetwork = createNetwork();

    addNode(myNetwork, "Router1");
    addNode(myNetwork, "Switch1");
    addNode(myNetwork, "Server1");
    addNode(myNetwork, "PC1");
    addNode(myNetwork, "PC2");
    addNode(myNetwork, "Router2");
    addNode(myNetwork, "Switch2");

    connectNodes(myNetwork->nodes[0], myNetwork->nodes[1]);  // Router1 <-> Switch1
    connectNodes(myNetwork->nodes[1], myNetwork->nodes[2]);  // Switch1 <-> Server1
    connectNodes(myNetwork->nodes[1], myNetwork->nodes[3]);  // Switch1 <-> PC1
    connectNodes(myNetwork->nodes[1], myNetwork->nodes[4]);  // Switch1 <-> PC2
    connectNodes(myNetwork->nodes[0], myNetwork->nodes[5]);  // Router1 <-> Router2
    connectNodes(myNetwork->nodes[5], myNetwork->nodes[6]);  // Router2 <-> Switch2

    displayNetwork(myNetwork);

    freeNetwork(myNetwork);
    return 0;
}