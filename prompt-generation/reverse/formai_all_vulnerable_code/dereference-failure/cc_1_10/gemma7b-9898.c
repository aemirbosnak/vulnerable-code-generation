//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Network {
    int numNodes;
    Node** graph;
} Network;

void createNetwork(Network* network) {
    network->numNodes = MAX;
    network->graph = (Node**)malloc(network->numNodes * sizeof(Node*));

    for (int i = 0; i < network->numNodes; i++) {
        network->graph[i] = NULL;
    }
}

void addNode(Network* network, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (network->graph[data] == NULL) {
        network->graph[data] = newNode;
    } else {
        network->graph[data]->next = newNode;
    }
}

void traverseNetwork(Network* network) {
    for (int i = 0; i < network->numNodes; i++) {
        Node* current = network->graph[i];

        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }

        printf("\n");
    }
}

int main() {
    Network* network = (Network*)malloc(sizeof(Network));
    createNetwork(network);

    addNode(network, 1);
    addNode(network, 2);
    addNode(network, 3);
    addNode(network, 4);
    addNode(network, 5);

    traverseNetwork(network);

    return 0;
}