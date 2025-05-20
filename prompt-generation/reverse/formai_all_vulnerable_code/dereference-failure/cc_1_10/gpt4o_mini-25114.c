//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: complex
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

typedef struct Topology {
    Node* nodes[MAX_NODES];
    int nodeCount;
} Topology;

Topology* createTopology() {
    Topology* topology = (Topology*)malloc(sizeof(Topology));
    topology->nodeCount = 0;
    return topology;
}

Node* createNode(const char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->connectionCount = 0;
    return node;
}

void addNode(Topology* topology, const char* name) {
    if (topology->nodeCount >= MAX_NODES) {
        printf("Maximum node limit reached!\n");
        return;
    }
    Node* newNode = createNode(name);
    topology->nodes[topology->nodeCount++] = newNode;
}

void connectNodes(Node* nodeA, Node* nodeB) {
    if (nodeA->connectionCount >= MAX_NODES || nodeB->connectionCount >= MAX_NODES) {
        printf("Connection limit exceeded for nodes!\n");
        return;
    }
    if (nodeA == nodeB) {
        printf("Cannot connect node to itself!\n");
        return;
    }
    
    nodeA->connections[nodeA->connectionCount++] = nodeB;
    nodeB->connections[nodeB->connectionCount++] = nodeA; // Connection is bidirectional
}

void printTopology(const Topology* topology) {
    for (int i = 0; i < topology->nodeCount; i++) {
        Node* node = topology->nodes[i];
        printf("Node %s is connected to: ", node->name);
        for (int j = 0; j < node->connectionCount; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void freeTopology(Topology* topology) {
    for (int i = 0; i < topology->nodeCount; i++) {
        free(topology->nodes[i]);
    }
    free(topology);
}

int main() {
    Topology* myTopology = createTopology();
    
    addNode(myTopology, "Router1");
    addNode(myTopology, "Switch1");
    addNode(myTopology, "PC1");
    addNode(myTopology, "PC2");
    addNode(myTopology, "Server");

    connectNodes(myTopology->nodes[0], myTopology->nodes[1]); // Router1 <-> Switch1
    connectNodes(myTopology->nodes[1], myTopology->nodes[2]); // Switch1 <-> PC1
    connectNodes(myTopology->nodes[1], myTopology->nodes[3]); // Switch1 <-> PC2
    connectNodes(myTopology->nodes[1], myTopology->nodes[4]); // Switch1 <-> Server

    printf("Current Network Topology:\n");
    printTopology(myTopology);

    freeTopology(myTopology);
    return 0;
}