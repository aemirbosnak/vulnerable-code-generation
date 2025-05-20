//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 50

// Structure to represent a node in the network
typedef struct {
    int id; // Unique identifier for the node
    char name[50]; // Name of the node
    int num_edges; // Number of edges connected to the node
    int edges[MAX_EDGES]; // Array of edges connected to the node
} node_t;

// Structure to represent an edge in the network
typedef struct {
    int src; // Source node of the edge
    int dest; // Destination node of the edge
} edge_t;

// Function to create a new node in the network
node_t* new_node(int id, char name[50]) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->id = id;
    strcpy(node->name, name);
    node->num_edges = 0;
    return node;
}

// Function to create a new edge in the network
edge_t* new_edge(int src, int dest) {
    edge_t* edge = (edge_t*) malloc(sizeof(edge_t));
    edge->src = src;
    edge->dest = dest;
    return edge;
}

// Function to add an edge to a node
void add_edge(node_t* node, edge_t* edge) {
    node->num_edges++;
    node->edges[node->num_edges - 1] = edge;
}

// Function to print the network
void print_network(node_t* node) {
    printf("Node %d: %s\n", node->id, node->name);
    for (int i = 0; i < node->num_edges; i++) {
        edge_t* edge = node->edges[i];
        printf("  - Edge to %d: %d\n", edge->dest, edge->src);
    }
}

int main() {
    // Create a new node
    node_t* node1 = new_node(1, "Node 1");

    // Create two new edges
    edge_t* edge1 = new_edge(1, 2);
    edge_t* edge2 = new_edge(2, 3);

    // Add the edges to the node
    add_edge(node1, edge1);
    add_edge(node1, edge2);

    // Create two more nodes
    node_t* node2 = new_node(2, "Node 2");
    node_t* node3 = new_node(3, "Node 3");

    // Add edges between the nodes
    add_edge(node2, edge1);
    add_edge(node3, edge2);

    // Print the network
    print_network(node1);
    print_network(node2);
    print_network(node3);

    return 0;
}