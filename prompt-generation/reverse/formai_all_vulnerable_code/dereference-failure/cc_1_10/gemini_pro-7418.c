//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of nodes in the network
#define MAX_NODES 100

// Define the maximum length of a node name
#define MAX_NAME_LENGTH 256

// Define the maximum number of neighbors for a node
#define MAX_NEIGHBORS 10

// Define the structure of a node
typedef struct node {
    char name[MAX_NAME_LENGTH];
    struct node *neighbors[MAX_NEIGHBORS];
    int num_neighbors;
} node;

// Define the structure of the network
typedef struct network {
    node nodes[MAX_NODES];
    int num_nodes;
} network;

// Create a new network
network *create_network() {
    network *net = malloc(sizeof(network));
    net->num_nodes = 0;
    return net;
}

// Add a node to the network
void add_node(network *net, char *name) {
    node *n = malloc(sizeof(node));
    strcpy(n->name, name);
    n->num_neighbors = 0;
    net->nodes[net->num_nodes++] = *n;
}

// Add a neighbor to a node
void add_neighbor(node *n, node *neighbor) {
    n->neighbors[n->num_neighbors++] = neighbor;
}

// Print the network topology
void print_network(network *net) {
    for (int i = 0; i < net->num_nodes; i++) {
        node *n = &net->nodes[i];
        printf("%s:", n->name);
        for (int j = 0; j < n->num_neighbors; j++) {
            printf(" %s", n->neighbors[j]->name);
        }
        printf("\n");
    }
}

// Free the memory allocated for the network
void free_network(network *net) {
    for (int i = 0; i < net->num_nodes; i++) {
        free(net->nodes[i].neighbors);
    }
    free(net);
}

// Main function
int main() {
    // Create a new network
    network *net = create_network();

    // Add some nodes to the network
    add_node(net, "node1");
    add_node(net, "node2");
    add_node(net, "node3");
    add_node(net, "node4");

    // Add some neighbors to the nodes
    add_neighbor(&net->nodes[0], &net->nodes[1]);
    add_neighbor(&net->nodes[0], &net->nodes[2]);
    add_neighbor(&net->nodes[1], &net->nodes[2]);
    add_neighbor(&net->nodes[1], &net->nodes[3]);
    add_neighbor(&net->nodes[2], &net->nodes[3]);
    add_neighbor(&net->nodes[3], &net->nodes[0]);

    // Print the network topology
    print_network(net);

    // Free the memory allocated for the network
    free_network(net);

    return 0;
}