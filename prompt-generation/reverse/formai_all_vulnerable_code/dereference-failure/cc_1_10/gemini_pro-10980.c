//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Structure to represent a node in the network topology
typedef struct node {
    char *name;             // Name of the node
    int num_neighbors;      // Number of neighbors the node has
    struct node **neighbors; // Array of pointers to the node's neighbors
} node;

// Function to create a new node
node *create_node(char *name) {
    node *new_node = malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->num_neighbors = 0;
    new_node->neighbors = NULL;
    return new_node;
}

// Function to add a neighbor to a node
void add_neighbor(node *n1, node *n2) {
    n1->neighbors = realloc(n1->neighbors, (n1->num_neighbors + 1) * sizeof(node *));
    n1->neighbors[n1->num_neighbors++] = n2;
}

// Function to print the network topology
void print_topology(node *root) {
    printf("%s\n", root->name);
    for (int i = 0; i < root->num_neighbors; i++) {
        printf(" - %s\n", root->neighbors[i]->name);
    }
}

// Function to free the memory allocated for the network topology
void free_topology(node *root) {
    for (int i = 0; i < root->num_neighbors; i++) {
        free_topology(root->neighbors[i]);
    }
    free(root->name);
    free(root->neighbors);
    free(root);
}

// Main function
int main() {
    // Create the root node of the network topology
    node *root = create_node("root");

    // Add some neighbors to the root node
    add_neighbor(root, create_node("node1"));
    add_neighbor(root, create_node("node2"));
    add_neighbor(root, create_node("node3"));

    // Add some neighbors to the first neighbor of the root node
    add_neighbor(root->neighbors[0], create_node("node11"));
    add_neighbor(root->neighbors[0], create_node("node12"));

    // Add some neighbors to the second neighbor of the root node
    add_neighbor(root->neighbors[1], create_node("node21"));
    add_neighbor(root->neighbors[1], create_node("node22"));

    // Add some neighbors to the third neighbor of the root node
    add_neighbor(root->neighbors[2], create_node("node31"));
    add_neighbor(root->neighbors[2], create_node("node32"));

    // Print the network topology
    print_topology(root);

    // Free the memory allocated for the network topology
    free_topology(root);

    return 0;
}