//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NETWORK_SIZE 100

typedef struct Node {
    int index;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Network {
    Node** graph;
    int size;
} Network;

void initializeNetwork(Network* network) {
    network->graph = malloc(network->size * sizeof(Node*));
    for (int i = 0; i < network->size; i++) {
        network->graph[i] = NULL;
    }
}

void insertNode(Network* network, int index) {
    Node* newNode = malloc(sizeof(Node));
    newNode->index = index;
    newNode->next = network->graph[index];
    network->graph[index] = newNode;
}

void traverseNetwork(Network* network) {
    for (int i = 0; i < network->size; i++) {
        Node* node = network->graph[i];
        if (node) {
            printf("Node %d: ", node->index);
            node = node->next;
            while (node) {
                printf("Connected to Node %d, ", node->index);
                node = node->next;
            }
            printf("\n");
        }
    }
}

int main() {
    Network* network = malloc(sizeof(Network));
    network->size = MAX_NETWORK_SIZE;
    initializeNetwork(network);

    insertNode(network, 0);
    insertNode(network, 1);
    insertNode(network, 2);
    insertNode(network, 3);
    insertNode(network, 4);

    traverseNetwork(network);

    return 0;
}