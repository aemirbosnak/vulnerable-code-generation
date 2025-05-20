//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 100

// A node in the network topology
struct node {
    int id;
    char *name;
    struct node *next;
};

// The network topology
struct network {
    int num_nodes;
    struct node *nodes;
};

// Create a new node
struct node *create_node(int id, char *name) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->id = id;
    new_node->name = strdup(name);
    new_node->next = NULL;
    return new_node;
}

// Add a node to the network
void add_node(struct network *network, struct node *node) {
    if (network->num_nodes == 0) {
        network->nodes = node;
    } else {
        struct node *current_node = network->nodes;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = node;
    }
    network->num_nodes++;
}

// Print the network topology
void print_network(struct network *network) {
    struct node *current_node = network->nodes;
    while (current_node != NULL) {
        printf("Node %d: %s\n", current_node->id, current_node->name);
        current_node = current_node->next;
    }
}

// Free the memory allocated for the network topology
void free_network(struct network *network) {
    struct node *current_node = network->nodes;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node->name);
        free(current_node);
        current_node = next_node;
    }
}

// Main function
int main(int argc, char **argv) {
    // Create a new network
    struct network *network = malloc(sizeof(struct network));
    network->num_nodes = 0;
    network->nodes = NULL;

    // Add some nodes to the network
    add_node(network, create_node(1, "Node 1"));
    add_node(network, create_node(2, "Node 2"));
    add_node(network, create_node(3, "Node 3"));

    // Print the network topology
    print_network(network);

    // Free the memory allocated for the network topology
    free_network(network);

    return 0;
}