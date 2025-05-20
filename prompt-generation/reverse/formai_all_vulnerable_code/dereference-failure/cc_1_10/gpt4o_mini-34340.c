//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connectionCount;
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int nodeCount;
} Network;

void initializeNetwork(Network* network) {
    network->nodeCount = 0;
}

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->connectionCount = 0;
    return newNode;
}

bool addNode(Network* network, const char* nodeName) {
    if (network->nodeCount >= MAX_NODES) {
        return false; // Network is full
    }
    Node* newNode = createNode(nodeName);
    network->nodes[network->nodeCount++] = newNode;
    return true;
}

bool findNode(Network* network, const char* nodeName, Node** nodeOut) {
    for (int i = 0; i < network->nodeCount; i++) {
        if (strcmp(network->nodes[i]->name, nodeName) == 0) {
            *nodeOut = network->nodes[i];
            return true;
        }
    }
    return false;
}

bool addConnection(Network* network, const char* nodeName1, const char* nodeName2) {
    Node *node1, *node2;
    if (!findNode(network, nodeName1, &node1) || !findNode(network, nodeName2, &node2)) {
        return false; // One or both nodes not found
    }
    // Assuming undirected graph, add connection in both directions
    node1->connections[node1->connectionCount++] = node2;
    node2->connections[node2->connectionCount++] = node1;
    return true;
}

void printNetwork(Network* network) {
    for (int i = 0; i < network->nodeCount; i++) {
        Node* node = network->nodes[i];
        printf("Node: %s is connected to: ", node->name);
        for (int j = 0; j < node->connectionCount; j++) {
            printf("%s ", node->connections[j]->name);
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
    Network network;
    initializeNetwork(&network);

    addNode(&network, "Node1");
    addNode(&network, "Node2");
    addNode(&network, "Node3");
    addNode(&network, "Node4");

    addConnection(&network, "Node1", "Node2");
    addConnection(&network, "Node1", "Node3");
    addConnection(&network, "Node2", "Node4");

    printf("Network Topology:\n");
    printNetwork(&network);

    freeNetwork(&network);
    return 0;
}