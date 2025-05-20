//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define NAME_LENGTH 50

typedef struct Node {
    char name[NAME_LENGTH];
    struct Node *connections[MAX_NODES];
    int connectionCount;
} Node;

typedef struct Network {
    Node *nodes[MAX_NODES];
    int nodeCount;
} Network;

Node* createNode(const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->name, name, NAME_LENGTH);
    newNode->connectionCount = 0;
    return newNode;
}

void addNode(Network *network, const char *name) {
    if (network->nodeCount >= MAX_NODES) {
        printf("Network full! Cannot add more nodes.\n");
        return;
    }
    network->nodes[network->nodeCount++] = createNode(name);
    printf("Node %s added to the network.\n", name);
}

void connectNodes(Node *node1, Node *node2) {
    if (node1->connectionCount >= MAX_NODES || node2->connectionCount >= MAX_NODES) {
        printf("Connection limit reached for %s or %s.\n", node1->name, node2->name);
        return;
    }
    node1->connections[node1->connectionCount++] = node2;
    node2->connections[node2->connectionCount++] = node1;  // Ensure bi-directional connection
    printf("Connected %s to %s.\n", node1->name, node2->name);
}

void displayNetwork(Network *network) {
    for (int i = 0; i < network->nodeCount; i++) {
        Node *node = network->nodes[i];
        printf("Node: %s, Connections: ", node->name);
        for (int j = 0; j < node->connectionCount; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Network *network) {
    for (int i = 0; i < network->nodeCount; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network *network = (Network *)malloc(sizeof(Network));
    network->nodeCount = 0;

    addNode(network, "RouterA");
    addNode(network, "SwitchA");
    addNode(network, "ServerA");
    addNode(network, "PC1");
    addNode(network, "PC2");

    connectNodes(network->nodes[0], network->nodes[1]); // RouterA to SwitchA
    connectNodes(network->nodes[1], network->nodes[2]); // SwitchA to ServerA
    connectNodes(network->nodes[1], network->nodes[3]); // SwitchA to PC1
    connectNodes(network->nodes[1], network->nodes[4]); // SwitchA to PC2

    displayNetwork(network);

    freeNetwork(network);
    return 0;
}