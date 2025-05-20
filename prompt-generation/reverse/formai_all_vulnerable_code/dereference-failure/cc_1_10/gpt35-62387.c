//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10   // Maximum nodes in the network
#define MAX_LEN   100  // Maximum character length of a node name

// Structure to hold information about a single node in the network
typedef struct Node {
    char name[MAX_LEN];      // The name of the node
    struct Node *neighbors[MAX_NODES];  // Array of pointers to the node's neighbors
    int num_neighbors;       // Number of neighbors the node has
} Node;

// Function to create a new node with the given name
Node *create_node(char *name) {
    Node *node = (Node*) malloc(sizeof(Node));
    strcpy(node->name, name);
    node->num_neighbors = 0;
    return node;
}

// Function to add a neighbor to a node
void add_neighbor(Node *node, Node *neighbor) {
    if (node->num_neighbors < MAX_NODES) {
        node->neighbors[node->num_neighbors++] = neighbor;
    }
}

// Function to print a node and its neighbors recursively
void print_node(Node *node, int depth) {
    int i;
    for (i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s\n", node->name);
    for (i = 0; i < node->num_neighbors; i++) {
        print_node(node->neighbors[i], depth+1);
    }
}

int main() {
    Node *a = create_node("A");
    Node *b = create_node("B");
    Node *c = create_node("C");
    Node *d = create_node("D");

    add_neighbor(a, b);
    add_neighbor(a, c);
    add_neighbor(b, d);

    print_node(a, 0);

    return 0;
}