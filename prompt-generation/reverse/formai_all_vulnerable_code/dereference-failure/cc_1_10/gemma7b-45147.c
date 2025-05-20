//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

// Define a structure to represent a network topology
typedef struct Node {
    char *name;
    struct Node **neighbors;
    int num_neighbors;
} Node;

// Function to create a new node
Node *newNode(char *name) {
    Node *node = malloc(sizeof(Node));
    node->name = strdup(name);
    node->neighbors = NULL;
    node->num_neighbors = 0;

    return node;
}

// Function to add a neighbor to a node
void addNeighbor(Node *node, Node *neighbor) {
    node->neighbors = realloc(node->neighbors, (node->num_neighbors + 1) * sizeof(Node *));
    node->neighbors[node->num_neighbors++] = neighbor;
}

// Function to print the topology of a network
void printTopology(Node *node) {
    printf("%s: ", node->name);

    for (int i = 0; i < node->num_neighbors; i++) {
        printf("%s ", node->neighbors[i]->name);
    }

    printf("\n");
}

int main() {
    // Create a new node for each device in the network
    Node *router = newNode("Router");
    Node *switch1 = newNode("Switch 1");
    Node *switch2 = newNode("Switch 2");
    Node *switch3 = newNode("Switch 3");
    Node *pc1 = newNode("PC 1");
    Node *pc2 = newNode("PC 2");

    // Add neighbors to the network topology
    addNeighbor(router, switch1);
    addNeighbor(router, switch2);
    addNeighbor(switch1, switch2);
    addNeighbor(switch1, switch3);
    addNeighbor(switch2, pc1);
    addNeighbor(switch2, pc2);

    // Print the topology of the network
    printTopology(router);

    return 0;
}