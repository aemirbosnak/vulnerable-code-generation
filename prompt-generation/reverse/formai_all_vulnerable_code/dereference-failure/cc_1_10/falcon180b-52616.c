//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of nodes
#define MAX_NODES 100

// Define the structure of a node
typedef struct {
    char name[20];
    int neighbors[MAX_NODES];
    int num_neighbors;
} Node;

// Function to add a neighbor to a node
void add_neighbor(Node* node, char* neighbor_name) {
    int i;
    for (i = 0; i < node->num_neighbors; i++) {
        if (strcmp(node->neighbors[i], neighbor_name) == 0) {
            return; // Neighbor already exists
        }
    }
    strcpy(node->neighbors[node->num_neighbors], neighbor_name);
    node->num_neighbors++;
}

// Function to print the topology of the network
void print_topology(Node* nodes, int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %s has %d neighbors:\n", nodes[i].name, nodes[i].num_neighbors);
        int j;
        for (j = 0; j < nodes[i].num_neighbors; j++) {
            printf("%s ", nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int num_nodes;
    scanf("%d", &num_nodes);
    Node* nodes = (Node*) malloc(num_nodes * sizeof(Node));
    int i;
    for (i = 0; i < num_nodes; i++) {
        scanf("%s", nodes[i].name);
        nodes[i].num_neighbors = 0;
    }
    int u, v;
    while (scanf("%d %d", &u, &v) == 2) {
        add_neighbor(&nodes[u-1], nodes[v-1].name);
    }
    print_topology(nodes, num_nodes);
    return 0;
}