//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Decentralized structure
struct Node {
    int id;
    struct Node *neighbors[MAX_NODES];
    int num_neighbors;
};

// Initialize a node with given id
void init_node(struct Node *node, int id) {
    node->id = id;
    node->num_neighbors = 0;
}

// Add a neighbor to a node
void add_neighbor(struct Node *node, struct Node *neighbor) {
    node->neighbors[node->num_neighbors] = neighbor;
    node->num_neighbors++;
}

// Print graph in adjacency list representation
void print_graph(struct Node *nodes[], int num_nodes) {
    printf("Graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", nodes[i]->id);
        for (int j = 0; j < nodes[i]->num_neighbors; j++) {
            printf("%d ", nodes[i]->neighbors[j]->id);
        }
        printf("\n");
    }
}

int main() {
    struct Node *nodes[MAX_NODES];
    int num_nodes = 0;

    // Create nodes
    for (int i = 1; i <= 5; i++) {
        struct Node *node = malloc(sizeof(struct Node));
        init_node(node, i);
        nodes[num_nodes] = node;
        num_nodes++;
    }

    // Connect nodes
    add_neighbor(nodes[0], nodes[1]);
    add_neighbor(nodes[0], nodes[3]);
    add_neighbor(nodes[1], nodes[0]);
    add_neighbor(nodes[1], nodes[2]);
    add_neighbor(nodes[2], nodes[1]);
    add_neighbor(nodes[2], nodes[3]);
    add_neighbor(nodes[3], nodes[0]);
    add_neighbor(nodes[3], nodes[2]);
    add_neighbor(nodes[3], nodes[4]);
    add_neighbor(nodes[4], nodes[3]);

    // Print graph
    print_graph(nodes, num_nodes);

    // Free memory
    for (int i = 0; i < num_nodes; i++) {
        free(nodes[i]);
    }

    return 0;
}