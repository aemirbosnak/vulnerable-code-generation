//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    int id;
    char name[50];
    struct Node* neighbors[MAX_NODES];
    int neighbor_count;
} Node;

typedef struct NetworkTopology {
    Node* nodes[MAX_NODES];
    int node_count;
} NetworkTopology;

// Function to create a new node
Node* create_node(int id, const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->neighbor_count = 0;
    return new_node;
}

// Function to add a node to the topology
void add_node(NetworkTopology* topology, Node* node) {
    if (topology->node_count < MAX_NODES) {
        topology->nodes[topology->node_count++] = node;
    }
}

// Function to add a connection between two nodes
void connect_nodes(Node* node1, Node* node2) {
    if (node1->neighbor_count < MAX_NODES) {
        node1->neighbors[node1->neighbor_count++] = node2;
    }
    if (node2->neighbor_count < MAX_NODES) {
        node2->neighbors[node2->neighbor_count++] = node1;
    }
}

// Function to display the network topology
void display_topology(NetworkTopology* topology) {
    printf("Network Topology:\n");
    for (int i = 0; i < topology->node_count; i++) {
        Node* node = topology->nodes[i];
        printf("Node ID: %d, Name: %s -> Connected to: ", node->id, node->name);
        for (int j = 0; j < node->neighbor_count; j++) {
            printf("%s ", node->neighbors[j]->name);
        }
        printf("\n");
    }
}

// Function to free memory
void free_topology(NetworkTopology* topology) {
    for (int i = 0; i < topology->node_count; i++) {
        free(topology->nodes[i]);
    }
    free(topology);
}

int main() {
    NetworkTopology* topology = (NetworkTopology*)malloc(sizeof(NetworkTopology));
    topology->node_count = 0;

    // Creating nodes
    Node* node1 = create_node(1, "Router1");
    Node* node2 = create_node(2, "Switch1");
    Node* node3 = create_node(3, "Server1");
    Node* node4 = create_node(4, "Workstation1");

    // Adding nodes to topology
    add_node(topology, node1);
    add_node(topology, node2);
    add_node(topology, node3);
    add_node(topology, node4);

    // Connecting nodes
    connect_nodes(node1, node2);
    connect_nodes(node1, node3);
    connect_nodes(node2, node4);

    // Display the topology
    display_topology(topology);

    // Free allocated memory
    free_topology(topology);

    return 0;
}