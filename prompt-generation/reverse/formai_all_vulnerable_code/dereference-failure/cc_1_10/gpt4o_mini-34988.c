//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50

typedef struct Node {
    char name[20];
    struct Node* children[MAX_NODES];
    int child_count;
} Node;

// Function to create a new node
Node* create_node(const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->child_count = 0;
    return new_node;
}

// Function to add a child node to a parent node
void add_child(Node* parent, Node* child) {
    if (parent->child_count < MAX_NODES) {
        parent->children[parent->child_count++] = child;
    } else {
        printf("Cannot add more children to node: %s\n", parent->name);
    }
}

// Recursive function to print the network topology
void print_topology(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("|-- %s\n", node->name);
    for (int i = 0; i < node->child_count; i++) {
        print_topology(node->children[i], level + 1);
    }
}

// Free memory for the nodes
void free_memory(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_memory(node->children[i]);
    }
    free(node);
}

int main() {
    // Create root node
    Node* root = create_node("Router");

    // Create child nodes
    Node* switch1 = create_node("Switch 1");
    Node* switch2 = create_node("Switch 2");
    Node* pc1 = create_node("PC 1");
    Node* pc2 = create_node("PC 2");
    Node* server = create_node("Server");

    // Construct network topology
    add_child(root, switch1);
    add_child(root, switch2);
    add_child(switch1, pc1);
    add_child(switch1, pc2);
    add_child(switch2, server);

    // Print the topology
    printf("Network Topology:\n");
    print_topology(root, 0);

    // Free allocated memory
    free_memory(root);
    
    return 0;
}