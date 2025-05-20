//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 50
#define MAX_NEIGHBORS 10

typedef struct {
    int id;
    char* name;
    char* ip_addr;
    int num_neighbors;
    int neighbors[MAX_NEIGHBORS];
} Node;

// function to add a neighbor to a node
void add_neighbor(Node* node, int neighbor_id) {
    if (node->num_neighbors >= MAX_NEIGHBORS) {
        printf("Cannot add neighbor - maximum number of neighbors reached!\n");
        return;
    }
    node->neighbors[node->num_neighbors++] = neighbor_id;
}

// function to print a node's information
void print_node(Node node) {
    printf("ID: %d\n", node.id);
    printf("Name: %s\n", node.name);
    printf("IP Address: %s\n", node.ip_addr);
    printf("Number of Neighbors: %d\n", node.num_neighbors);
    printf("Neighbor IDs: ");
    for (int i = 0; i < node.num_neighbors; i++) {
        printf("%d ", node.neighbors[i]);
    }
    printf("\n\n");
}

// function to create a new node
Node* create_node(int id, char* name, char* ip_addr) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->name = (char*)malloc(strlen(name)+1);
    strcpy(node->name, name);
    node->ip_addr = (char*)malloc(strlen(ip_addr)+1);
    strcpy(node->ip_addr, ip_addr);
    node->num_neighbors = 0;
    return node;
}

int main() {
    Node* nodes[MAX_NODES];
    int num_nodes = 0;
    
    // create some nodes
    Node* node1 = create_node(1, "Node 1", "192.168.0.1");
    Node* node2 = create_node(2, "Node 2", "192.168.0.2");
    Node* node3 = create_node(3, "Node 3", "192.168.0.3");
    
    // add neighbors to nodes
    add_neighbor(node1, 2);
    add_neighbor(node1, 3);
    add_neighbor(node2, 1);
    add_neighbor(node3, 1);
    
    // add nodes to our list of nodes
    nodes[num_nodes++] = node1;
    nodes[num_nodes++] = node2;
    nodes[num_nodes++] = node3;
    
    // print each node's information
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d:\n", i+1);
        print_node(*nodes[i]);
    }
    
    // free memory allocated for nodes
    for (int i = 0; i < num_nodes; i++) {
        free(nodes[i]->name);
        free(nodes[i]->ip_addr);
        free(nodes[i]);
    }
    
    return 0;
}