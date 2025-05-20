//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

// Define the structure for each node
typedef struct {
    char name[20];
    int id;
    int degree;
    int *neighbors;
} Node;

// Function to initialize a node
void initNode(Node *node) {
    strcpy(node->name, "");
    node->id = -1;
    node->degree = 0;
    node->neighbors = NULL;
}

// Function to create a new node
Node *createNode(char *name) {
    Node *node = (Node *)malloc(sizeof(Node));
    initNode(node);
    strcpy(node->name, name);
    return node;
}

// Function to add a neighbor to a node
void addNeighbor(Node *node, int neighborId) {
    node->neighbors = (int *)realloc(node->neighbors, sizeof(int) * ++node->degree);
    node->neighbors[node->degree - 1] = neighborId;
}

// Function to print a node
void printNode(Node *node) {
    printf("Node %s (%d) has %d neighbors:\n", node->name, node->id, node->degree);
    for (int i = 0; i < node->degree; i++) {
        printf("%d ", node->neighbors[i]);
    }
    printf("\n");
}

// Function to print the entire network topology
void printNetwork(Node *nodes, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        printNode(nodes + i);
    }
}

// Function to generate a random network topology
void generateNetwork(Node *nodes, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        initNode(nodes + i);
    }

    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (rand() % 2 == 0) {
                addNeighbor(nodes + i, j);
                addNeighbor(nodes + j, i);
            }
        }
    }
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    Node *nodes = (Node *)malloc(sizeof(Node) * numNodes);

    generateNetwork(nodes, numNodes);

    printNetwork(nodes, numNodes);

    return 0;
}