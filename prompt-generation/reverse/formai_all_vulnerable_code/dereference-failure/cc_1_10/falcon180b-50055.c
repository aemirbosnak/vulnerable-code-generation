//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a network node
typedef struct node {
    char name[50];
    int is_visited;
    int num_neighbors;
    struct node *neighbors[10];
} Node;

// Function to create a new network node
Node* create_node(char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->is_visited = 0;
    new_node->num_neighbors = 0;
    for (int i = 0; i < 10; i++) {
        new_node->neighbors[i] = NULL;
    }
    return new_node;
}

// Function to add a neighbor to a network node
void add_neighbor(Node* node, Node* neighbor) {
    for (int i = 0; i < node->num_neighbors; i++) {
        if (node->neighbors[i] == NULL) {
            node->neighbors[i] = neighbor;
            node->num_neighbors++;
            break;
        }
    }
}

// Function to print the network topology
void print_topology(Node* node) {
    printf("Node: %s\n", node->name);
    printf("Neighbors:\n");
    for (int i = 0; i < node->num_neighbors; i++) {
        printf("\t%s\n", node->neighbors[i]->name);
    }
}

// Function to traverse the network recursively
void traverse_network(Node* node) {
    node->is_visited = 1;
    print_topology(node);
    for (int i = 0; i < node->num_neighbors; i++) {
        if (node->neighbors[i]!= NULL &&!node->neighbors[i]->is_visited) {
            traverse_network(node->neighbors[i]);
        }
    }
}

// Main function
int main() {
    // Create network nodes
    Node* node1 = create_node("Node 1");
    Node* node2 = create_node("Node 2");
    Node* node3 = create_node("Node 3");
    Node* node4 = create_node("Node 4");

    // Connect network nodes
    add_neighbor(node1, node2);
    add_neighbor(node1, node3);
    add_neighbor(node2, node4);

    // Traverse the network
    traverse_network(node1);

    return 0;
}