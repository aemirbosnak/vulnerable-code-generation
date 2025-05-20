//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 10

// Structure to represent a node
struct node {
    int color;
    int neighbors[MAX_NODES];
    int num_neighbors;
};

// Function to add a neighbor to the node
void add_neighbor(struct node* node, int neighbor) {
    node->neighbors[node->num_neighbors] = neighbor;
    node->num_neighbors++;
}

// Function to print the graph
void print_graph(struct node* nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < nodes[i].num_neighbors; j++) {
            printf("%d ", nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

// Function to perform graph coloring
void color_graph(struct node* nodes, int num_nodes) {
    int num_colors = 1;
    while (num_colors < num_nodes) {
        int node = -1;
        for (int i = 0; i < num_nodes; i++) {
            if (nodes[i].color == 0) {
                node = i;
                break;
            }
        }
        if (node == -1) {
            printf("No nodes to color\n");
            return;
        }
        for (int j = 0; j < nodes[node].num_neighbors; j++) {
            if (nodes[nodes[node].neighbors[j]].color == 0) {
                nodes[nodes[node].neighbors[j]].color = num_colors;
                num_colors++;
            } else if (nodes[nodes[node].neighbors[j]].color == nodes[node].color) {
                printf("No valid coloring possible\n");
                return;
            }
        }
    }
    printf("Valid coloring: ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", nodes[i].color);
    }
    printf("\n");
}

int main() {
    struct node nodes[MAX_NODES];
    int num_nodes = 0;

    // Create a graph with 3 nodes and 2 edges
    add_neighbor(&nodes[0], 1);
    add_neighbor(&nodes[0], 2);
    add_neighbor(&nodes[1], 0);
    add_neighbor(&nodes[1], 3);
    add_neighbor(&nodes[2], 0);
    add_neighbor(&nodes[2], 3);

    num_nodes = 4;

    // Print the graph
    printf("Graph:\n");
    print_graph(nodes, num_nodes);

    // Color the graph
    color_graph(nodes, num_nodes);

    return 0;
}