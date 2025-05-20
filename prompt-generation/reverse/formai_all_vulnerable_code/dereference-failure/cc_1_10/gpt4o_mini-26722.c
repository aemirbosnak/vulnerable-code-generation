//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connectionCount;
} Node;

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        strncpy(newNode->name, name, MAX_NAME_LENGTH);
        newNode->connectionCount = 0;
        for (int i = 0; i < MAX_NODES; i++) {
            newNode->connections[i] = NULL;
        }
    }
    return newNode;
}

void connectNodes(Node* node1, Node* node2) {
    if (node1->connectionCount < MAX_NODES && node2->connectionCount < MAX_NODES) {
        node1->connections[node1->connectionCount++] = node2;
        node2->connections[node2->connectionCount++] = node1; // Two-way connection
    } else {
        fprintf(stderr, "Unable to connect nodes: maximum connection limit reached.\n");
    }
}

void printNetwork(Node* nodes[], int nodeCount) {
    printf("Network Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("%s -> ", nodes[i]->name);
        for (int j = 0; j < nodes[i]->connectionCount; j++) {
            printf("%s ", nodes[i]->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Node* nodes[], int nodeCount) {
    for (int i = 0; i < nodeCount; i++) {
        free(nodes[i]);
    }
}

int main() {
    // Define a network of nodes
    Node* nodes[MAX_NODES];
    int nodeCount = 0;

    // Create nodes
    nodes[nodeCount++] = createNode("Router A");
    nodes[nodeCount++] = createNode("Switch B");
    nodes[nodeCount++] = createNode("PC 1");
    nodes[nodeCount++] = createNode("PC 2");
    nodes[nodeCount++] = createNode("Server C");
    nodes[nodeCount++] = createNode("Firewall D");
    
    // Connect nodes
    connectNodes(nodes[0], nodes[1]); // Router A <-> Switch B
    connectNodes(nodes[1], nodes[2]); // Switch B <-> PC 1
    connectNodes(nodes[1], nodes[3]); // Switch B <-> PC 2
    connectNodes(nodes[1], nodes[4]); // Switch B <-> Server C
    connectNodes(nodes[0], nodes[5]); // Router A <-> Firewall D
    connectNodes(nodes[5], nodes[4]); // Firewall D <-> Server C

    // Print the network topology
    printNetwork(nodes, nodeCount);
    
    // Free allocated memory
    freeNetwork(nodes, nodeCount);
    
    return 0;
}