//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes in the network.
#define MAX_NODES 100

// Define a structure to represent each node in the network.
typedef struct {
    int id;                      // The unique ID of the node.
    int num_neighbors;           // The number of neighbors for the node.
    int neighbors[MAX_NODES];    // The IDs of the node's neighbors.
} Node;

// Define a structure to represent the network topology.
typedef struct {
    int num_nodes;               // The number of nodes in the network.
    Node nodes[MAX_NODES];       // The actual nodes in the network.
} Network;

// Define a function to generate a random network topology.
void generate_random_topology(Network* network, int p) {
    // Initialize the random number generator.
    srand(time(NULL));

    // Set the number of nodes in the network.
    network->num_nodes = MAX_NODES;

    // Generate random edges between pairs of nodes.
    for (int i = 0; i < MAX_NODES; i++) {
        Node* node_i = &network->nodes[i];
        node_i->id = i;
        node_i->num_neighbors = 0;
        node_i->neighbors[0] = -1;

        for (int j = i+1; j < MAX_NODES; j++) {
            if (rand() % 100 < p) {
                Node* node_j = &network->nodes[j];
                node_i->neighbors[node_i->num_neighbors++] = j;
                node_j->neighbors[node_j->num_neighbors++] = i;
            }
        }
    }
}

// Define a function to print the network topology.
void print_network_topology(Network* network) {
    printf("Network Topology:\n");

    for (int i = 0; i < network->num_nodes; i++) {
        Node* node = &network->nodes[i];
        printf("Node %d: ", node->id);

        for (int j = 0; j < node->num_neighbors; j++) {
            printf("%d ", node->neighbors[j]);
        }

        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    Network network;

    // Generate a random network topology with probability p.
    int p = 20; // Probability of an edge between any two nodes.
    generate_random_topology(&network, p);

    // Print the network topology.
    print_network_topology(&network);

    return 0;
}