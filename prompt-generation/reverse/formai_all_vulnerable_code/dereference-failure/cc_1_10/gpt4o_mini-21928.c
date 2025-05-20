//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
    struct Node** connections;
    int numConnections;
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

Node* createNode(const char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LEN - 1);
    node->name[MAX_NAME_LEN - 1] = '\0';
    node->connections = (Node**)malloc(MAX_NODES * sizeof(Node*));
    node->numConnections = 0;
    return node;
}

void addNode(Network* network, const char* name) {
    if (network->numNodes < MAX_NODES) {
        network->nodes[network->numNodes++] = createNode(name);
    } else {
        printf("Network is full, cannot add more nodes.\n");
    }
}

void connectNodes(Node* a, Node* b) {
    if (a->numConnections < MAX_NODES) {
        a->connections[a->numConnections++] = b;
        b->connections[b->numConnections++] = a; // Undirected connection
    } else {
        printf("Max connections reached for node %s.\n", a->name);
    }
}

void printNetwork(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->numNodes; i++) {
        Node* node = network->nodes[i];
        printf("%s connected to: ", node->name);
        for (int j = 0; j < node->numConnections; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Network* network) {
    for (int i = 0; i < network->numNodes; i++) {
        free(network->nodes[i]->connections);
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network* network = createNetwork();

    addNode(network, "Router");
    addNode(network, "Switch");
    addNode(network, "Server");
    addNode(network, "PC1");
    addNode(network, "PC2");

    connectNodes(network->nodes[0], network->nodes[1]); // Router <-> Switch
    connectNodes(network->nodes[1], network->nodes[2]); // Switch <-> Server
    connectNodes(network->nodes[1], network->nodes[3]); // Switch <-> PC1
    connectNodes(network->nodes[1], network->nodes[4]); // Switch <-> PC2

    printNetwork(network);

    freeNetwork(network);
    return 0;
}