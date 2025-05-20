//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// A custom data structure to store network topology information
typedef struct network_topology {
    int num_nodes;          // Number of nodes in the network
    int num_links;          // Number of links in the network
    int **adj_matrix;       // Adjacency matrix representing the network topology
} network_topology;

// Function to create a new network topology
network_topology *create_network_topology(int num_nodes) {
    // Allocate memory for the network topology
    network_topology *topology = malloc(sizeof(network_topology));

    // Initialize the number of nodes and links
    topology->num_nodes = num_nodes;
    topology->num_links = 0;

    // Allocate memory for the adjacency matrix
    topology->adj_matrix = malloc(sizeof(int *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        topology->adj_matrix[i] = malloc(sizeof(int) * num_nodes);
    }

    // Initialize the adjacency matrix to zero
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            topology->adj_matrix[i][j] = 0;
        }
    }

    // Return the network topology
    return topology;
}

// Function to add a link to the network topology
void add_link(network_topology *topology, int node1, int node2) {
    // Check if the nodes are valid
    if (node1 < 0 || node1 >= topology->num_nodes) {
        printf("Invalid node: %d\n", node1);
        return;
    }
    if (node2 < 0 || node2 >= topology->num_nodes) {
        printf("Invalid node: %d\n", node2);
        return;
    }

    // Check if the link already exists
    if (topology->adj_matrix[node1][node2] != 0) {
        printf("Link already exists between nodes %d and %d\n", node1, node2);
        return;
    }

    // Add the link to the adjacency matrix
    topology->adj_matrix[node1][node2] = 1;
    topology->adj_matrix[node2][node1] = 1;

    // Increment the number of links
    topology->num_links++;
}

// Function to print the network topology
void print_network_topology(network_topology *topology) {
    // Print the adjacency matrix
    for (int i = 0; i < topology->num_nodes; i++) {
        for (int j = 0; j < topology->num_nodes; j++) {
            printf("%d ", topology->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to destroy the network topology
void destroy_network_topology(network_topology *topology) {
    // Free the adjacency matrix
    for (int i = 0; i < topology->num_nodes; i++) {
        free(topology->adj_matrix[i]);
    }
    free(topology->adj_matrix);

    // Free the network topology
    free(topology);
}

// Main function
int main() {
    // Create a new network topology with 5 nodes
    network_topology *topology = create_network_topology(5);

    // Add some links to the network topology
    add_link(topology, 0, 1);
    add_link(topology, 0, 2);
    add_link(topology, 1, 2);
    add_link(topology, 1, 3);
    add_link(topology, 2, 3);
    add_link(topology, 2, 4);
    add_link(topology, 3, 4);

    // Print the network topology
    printf("Network Topology:\n");
    print_network_topology(topology);

    // Destroy the network topology
    destroy_network_topology(topology);

    return 0;
}