//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_SIZE 100

typedef struct Node {
    char name[MAX_NETWORK_SIZE];
    struct Node* next;
} Node;

typedef struct Network {
    Node* head;
} Network;

void mapNetwork(Network* network) {
    Node* current = network->head;
    while (current) {
        printf("%s is connected to:", current->name);
        Node* connected = current->next;
        while (connected) {
            printf(" %s", connected->name);
            connected = connected->next;
        }
        printf("\n");
    }
}

int main() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->head = NULL;

    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->name[0] = 'A';
    node1->next = NULL;
    network->head = node1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->name[0] = 'B';
    node2->next = NULL;
    node1->next = node2;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->name[0] = 'C';
    node3->next = NULL;
    node2->next = node3;

    mapNetwork(network);

    return 0;
}