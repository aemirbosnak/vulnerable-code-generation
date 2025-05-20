//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

// Define the maximum number of nodes in the network
#define MAX_NODES 100

// Define the maximum length of a node name
#define MAX_NODE_NAME 32

// Define the maximum number of neighbors per node
#define MAX_NEIGHBORS 10

// Define the port number to use for communication
#define PORT_NUMBER 5000

// Define the structure of a node
typedef struct node {
    char name[MAX_NODE_NAME];
    int num_neighbors;
    struct node *neighbors[MAX_NEIGHBORS];
} node_t;

// Define the structure of a network
typedef struct network {
    int num_nodes;
    node_t *nodes[MAX_NODES];
} network_t;

// Create a new node
node_t *create_node(char *name) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(node->name, name);
    node->num_neighbors = 0;
    return node;
}

// Add a neighbor to a node
void add_neighbor(node_t *node, node_t *neighbor) {
    if (node->num_neighbors < MAX_NEIGHBORS) {
        node->neighbors[node->num_neighbors] = neighbor;
        node->num_neighbors++;
    } else {
        fprintf(stderr, "Error: node %s has too many neighbors\n", node->name);
        exit(EXIT_FAILURE);
    }
}

// Create a new network
network_t *create_network() {
    network_t *network = (network_t *)malloc(sizeof(network_t));
    if (network == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    network->num_nodes = 0;
    return network;
}

// Add a node to a network
void add_node(network_t *network, node_t *node) {
    if (network->num_nodes < MAX_NODES) {
        network->nodes[network->num_nodes] = node;
        network->num_nodes++;
    } else {
        fprintf(stderr, "Error: network has too many nodes\n");
        exit(EXIT_FAILURE);
    }
}

// Print the network topology to a file
void print_network_topology(network_t *network, FILE *file) {
    for (int i = 0; i < network->num_nodes; i++) {
        fprintf(file, "%s: ", network->nodes[i]->name);
        for (int j = 0; j < network->nodes[i]->num_neighbors; j++) {
            fprintf(file, "%s ", network->nodes[i]->neighbors[j]->name);
        }
        fprintf(file, "\n");
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <network_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the network file
    FILE *network_file = fopen(argv[1], "r");
    if (network_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Create a new network
    network_t *network = create_network();

    // Read the nodes from the network file
    char line[1024];
    while (fgets(line, sizeof(line), network_file) != NULL) {
        // Parse the line
        char *name = strtok(line, " ");
        char *neighbor_name = strtok(NULL, " ");

        // Create the node
        node_t *node = create_node(name);

        // Add the node to the network
        add_node(network, node);

        // Add the neighbors to the node
        while (neighbor_name != NULL) {
            // Find the neighbor node
            node_t *neighbor = NULL;
            for (int i = 0; i < network->num_nodes; i++) {
                if (strcmp(network->nodes[i]->name, neighbor_name) == 0) {
                    neighbor = network->nodes[i];
                    break;
                }
            }

            // If the neighbor node was not found, create it
            if (neighbor == NULL) {
                neighbor = create_node(neighbor_name);
                add_node(network, neighbor);
            }

            // Add the neighbor to the node
            add_neighbor(node, neighbor);

            // Get the next neighbor name
            neighbor_name = strtok(NULL, " ");
        }
    }

    // Close the network file
    fclose(network_file);

    // Open the output file
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Print the network topology to the output file
    print_network_topology(network, output_file);

    // Close the output file
    fclose(output_file);

    // Free the memory allocated for the network
    for (int i = 0; i < network->num_nodes; i++) {
        free(network->nodes[i]);
    }
    free(network);

    return 0;
}