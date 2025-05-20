//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
    struct Node* connections[MAX_NODES];
    int connectionCount;
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int nodeCount;
} Network;

void initNetwork(Network* network) {
    network->nodeCount = 0;
}

Node* createNode(const char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LEN);
    node->connectionCount = 0;
    return node;
}

void addNode(Network* network, const char* name) {
    if (network->nodeCount < MAX_NODES) {
        Node* newNode = createNode(name);
        network->nodes[network->nodeCount++] = newNode;
    } else {
        printf("Error: Maximum node limit reached\n");
    }
}

void connectNodes(Node* node1, Node* node2) {
    if (node1->connectionCount < MAX_NODES && node2->connectionCount < MAX_NODES) {
        node1->connections[node1->connectionCount++] = node2;
        node2->connections[node2->connectionCount++] = node1; // Bi-directional connection
    } else {
        printf("Error: Connection limit reached\n");
    }
}

void printNetwork(const Network* network) {
    for (int i = 0; i < network->nodeCount; i++) {
        Node* node = network->nodes[i];
        printf("Node %s is connected to:", node->name);
        for (int j = 0; j < node->connectionCount; j++) {
            printf(" %s", node->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Network* network) {
    for (int i = 0; i < network->nodeCount; i++) {
        free(network->nodes[i]);
    }
}

int main() {
    Network myNetwork;
    initNetwork(&myNetwork);

    addNode(&myNetwork, "Router1");
    addNode(&myNetwork, "Switch1");
    addNode(&myNetwork, "PC1");
    addNode(&myNetwork, "Printer1");

    connectNodes(myNetwork.nodes[0], myNetwork.nodes[1]);
    connectNodes(myNetwork.nodes[1], myNetwork.nodes[2]);
    connectNodes(myNetwork.nodes[1], myNetwork.nodes[3]);

    printNetwork(&myNetwork);

    freeNetwork(&myNetwork);
    return 0;
}