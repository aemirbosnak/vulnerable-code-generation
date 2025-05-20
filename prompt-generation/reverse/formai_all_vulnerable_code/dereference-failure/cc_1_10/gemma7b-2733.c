//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_OF_NODES 100

typedef struct Node {
    char name[MAX_NUMBER_OF_NODES];
    struct Node* next;
} Node;

typedef struct Network {
    Node** nodes;
    int numNodes;
} Network;

Network* createNetwork(int numNodes) {
    Network* network = malloc(sizeof(Network));
    network->nodes = malloc(sizeof(Node*) * numNodes);
    network->numNodes = numNodes;

    for (int i = 0; i < numNodes; i++) {
        network->nodes[i] = NULL;
    }

    return network;
}

void addNode(Network* network, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (network->nodes[network->numNodes - 1] != NULL) {
        network->nodes[network->numNodes - 1]->next = newNode;
    } else {
        network->nodes[network->numNodes - 1] = newNode;
    }

    network->numNodes++;
}

void mapTopology(Network* network) {
    for (int i = 0; i < network->numNodes; i++) {
        printf("%s ", network->nodes[i]->name);
    }
    printf("\n");
}

int main() {
    Network* network = createNetwork(5);
    addNode(network, "A");
    addNode(network, "B");
    addNode(network, "C");
    addNode(network, "D");
    addNode(network, "E");

    mapTopology(network);

    return 0;
}