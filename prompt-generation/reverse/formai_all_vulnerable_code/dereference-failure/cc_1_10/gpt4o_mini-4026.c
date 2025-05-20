//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: random
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

// Function prototypes
void addNode(Network* network, const char* name);
void connectNodes(Network* network, const char* name1, const char* name2);
void printNetwork(const Network* network);
void freeNetwork(Network* network);
Node* findNode(Network* network, const char* name);

int main() {
    Network network;
    network.nodeCount = 0;

    // Hardcoded example for simplicity
    addNode(&network, "Router");
    addNode(&network, "Switch1");
    addNode(&network, "Switch2");
    addNode(&network, "PC1");
    addNode(&network, "PC2");
    
    connectNodes(&network, "Router", "Switch1");
    connectNodes(&network, "Router", "Switch2");
    connectNodes(&network, "Switch1", "PC1");
    connectNodes(&network, "Switch2", "PC2");

    printNetwork(&network);

    // Free allocated memory
    freeNetwork(&network);
    
    return 0;
}

void addNode(Network* network, const char* name) {
    if (network->nodeCount >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LEN - 1);
    newNode->name[MAX_NAME_LEN - 1] = '\0'; // Null-terminate
    newNode->connectionCount = 0;
    network->nodes[network->nodeCount++] = newNode;
}

void connectNodes(Network* network, const char* name1, const char* name2) {
    Node* node1 = findNode(network, name1);
    Node* node2 = findNode(network, name2);

    if (node1 && node2) {
        if (node1->connectionCount < MAX_NODES && node2->connectionCount < MAX_NODES) {
            node1->connections[node1->connectionCount++] = node2;
            node2->connections[node2->connectionCount++] = node1; // Bi-directional connection
        } else {
            printf("Error: Max connections for one of the nodes reached.\n");
        }
    } else {
        printf("Error: One or both nodes not found.\n");
    }
}

Node* findNode(Network* network, const char* name) {
    for (int i = 0; i < network->nodeCount; i++) {
        if (strcmp(network->nodes[i]->name, name) == 0) {
            return network->nodes[i];
        }
    }
    return NULL;
}

void printNetwork(const Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->nodeCount; i++) {
        printf("Node: %s\nConnections: ", network->nodes[i]->name);
        for (int j = 0; j < network->nodes[i]->connectionCount; j++) {
            printf("%s ", network->nodes[i]->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Network* network) {
    for (int i = 0; i < network->nodeCount; i++) {
        free(network->nodes[i]);
    }
}