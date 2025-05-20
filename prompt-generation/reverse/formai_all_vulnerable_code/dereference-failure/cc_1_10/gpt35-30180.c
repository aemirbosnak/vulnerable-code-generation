//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a data structure for a computer node
typedef struct ComputerNode {
    char* name;             // The name of the computer node
    struct ComputerNode** neighbors;    // An array of pointers to neighbor computer nodes
    int num_neighbors;      // The number of neighbor computer nodes
} ComputerNode;

// Define a data structure to hold the network topology
typedef struct NetworkTopology {
    ComputerNode** nodes;   // An array of pointers to computer nodes in the network
    int num_nodes;          // The number of computer nodes in the network
} NetworkTopology;

// Function to create a new computer node with the given name
ComputerNode* create_computer_node(char* name) {
    ComputerNode* node = malloc(sizeof(ComputerNode));
    node->name = strdup(name);
    node->num_neighbors = 0;
    node->neighbors = NULL;
    return node;
}

// Function to add a neighbor computer node to a given computer node
void add_neighbor(ComputerNode* node, ComputerNode* neighbor) {
    node->neighbors = realloc(node->neighbors, sizeof(ComputerNode*) * (node->num_neighbors + 1));
    node->neighbors[node->num_neighbors] = neighbor;
    node->num_neighbors++;
}

// Function to create a new network topology with a given number of computer nodes
NetworkTopology* create_network_topology(int num_nodes) {
    NetworkTopology* topology = malloc(sizeof(NetworkTopology));
    topology->num_nodes = num_nodes;
    topology->nodes = malloc(sizeof(ComputerNode*) * num_nodes);
    return topology;
}

// Function to add a computer node to a given network topology
void add_node(NetworkTopology* topology, ComputerNode* node) {
    topology->nodes[topology->num_nodes] = node;
    topology->num_nodes++;
}

// Function to initialize a sample network topology
void initialize_topology(NetworkTopology* topology) {
    ComputerNode* node1 = create_computer_node("node1");
    ComputerNode* node2 = create_computer_node("node2");
    ComputerNode* node3 = create_computer_node("node3");
    ComputerNode* node4 = create_computer_node("node4");
    add_neighbor(node1, node2);
    add_neighbor(node2, node3);
    add_neighbor(node3, node4);
    add_neighbor(node4, node1);
    add_node(topology, node1);
    add_node(topology, node2);
    add_node(topology, node3);
    add_node(topology, node4);
}

// Function to print the network topology
void print_topology(NetworkTopology* topology) {
    printf("Network Topology:\n");
    for (int i = 0; i < topology->num_nodes; i++) {
        ComputerNode* node = topology->nodes[i];
        printf("%s neighbors: ", node->name);
        for (int j = 0; j < node->num_neighbors; j++) {
            ComputerNode* neighbor = node->neighbors[j];
            printf("%s ", neighbor->name);
        }
        printf("\n");
    }
}

int main() {
    NetworkTopology* topology = create_network_topology(0);
    initialize_topology(topology);
    print_topology(topology);
    return 0;
}