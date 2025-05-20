//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node *connections[MAX_NODES];
    int connectionCount;
} Node;

typedef struct Network {
    Node *nodes[MAX_NODES];
    int nodeCount;
} Network;

Network* createNetwork() {
    Network *network = (Network *)malloc(sizeof(Network));
    network->nodeCount = 0;
    return network;
}

Node* createNode(const char *name) {
    Node *node = (Node *)malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->connectionCount = 0;
    return node;
}

void addNode(Network *network, const char *name) {
    if (network->nodeCount >= MAX_NODES) {
        printf("Network is full. Cannot add more nodes.\n");
        return;
    }
    Node *node = createNode(name);
    network->nodes[network->nodeCount++] = node;
    printf("Node '%s' added to the network.\n", name);
}

void addConnection(Node *node1, Node *node2) {
    if (node1->connectionCount < MAX_NODES && node2->connectionCount < MAX_NODES) {
        node1->connections[node1->connectionCount++] = node2;
        node2->connections[node2->connectionCount++] = node1;
        printf("Connection established between '%s' and '%s'.\n", node1->name, node2->name);
    } else {
        printf("Connection limit reached for either '%s' or '%s'.\n", node1->name, node2->name);
    }
}

void printNetwork(Network *network) {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < network->nodeCount; i++) {
        Node *node = network->nodes[i];
        printf("Node: %s\n", node->name);
        printf("Connected to: ");
        for (int j = 0; j < node->connectionCount; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

Node* findNode(Network *network, const char *name) {
    for (int i = 0; i < network->nodeCount; i++) {
        if (strcmp(network->nodes[i]->name, name) == 0) {
            return network->nodes[i];
        }
    }
    return NULL;
}

void freeNetwork(Network *network) {
    for (int i = 0; i < network->nodeCount; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network *network = createNetwork();

    addNode(network, "Router1");
    addNode(network, "Switch1");
    addNode(network, "Server1");
    addNode(network, "PC1");
    addNode(network, "PC2");

    Node *router1 = findNode(network, "Router1");
    Node *switch1 = findNode(network, "Switch1");
    Node *server1 = findNode(network, "Server1");
    Node *pc1    = findNode(network, "PC1");
    Node *pc2    = findNode(network, "PC2");
    
    addConnection(router1, switch1);
    addConnection(switch1, server1);
    addConnection(switch1, pc1);
    addConnection(switch1, pc2);
    
    printNetwork(network);
    
    freeNetwork(network);
    return 0;
}