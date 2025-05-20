//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 5
#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node *children[MAX_CHILDREN];
    int child_count;
} Node;

// Function to create a new node
Node* create_node(char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    new_node->child_count = 0;
    return new_node;
}

// Function to add a child to a node
void add_child(Node *parent, Node *child) {
    if (parent->child_count < MAX_CHILDREN) {
        parent->children[parent->child_count++] = child;
    } else {
        printf("Cannot add more children to %s\n", parent->name);
    }
}

// Recursive function to print the network topology
void print_topology(Node *node, int level) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("- %s\n", node->name);
    for (int i = 0; i < node->child_count; i++) {
        print_topology(node->children[i], level + 1);
    }
}

// Function to free the allocated memory for the network
void free_network(Node *node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < node->child_count; i++) {
        free_network(node->children[i]);
    }
    free(node);
}

int main() {
    // Create root node
    Node *root = create_node("Router");

    // Create child nodes
    Node *switch1 = create_node("Switch1");
    Node *switch2 = create_node("Switch2");

    // Add switches to the root
    add_child(root, switch1);
    add_child(root, switch2);

    // Create devices under Switch1
    Node *device1 = create_node("Device1");
    Node *device2 = create_node("Device2");
    Node *device3 = create_node("Device3");

    add_child(switch1, device1);
    add_child(switch1, device2);
    add_child(switch1, device3);

    // Create devices under Switch2
    Node *device4 = create_node("Device4");
    Node *device5 = create_node("Device5");

    add_child(switch2, device4);
    add_child(switch2, device5);

    // Print the network topology
    printf("Network Topology:\n");
    print_topology(root, 0);

    // Free the allocated memory
    free_network(root);

    return 0;
}