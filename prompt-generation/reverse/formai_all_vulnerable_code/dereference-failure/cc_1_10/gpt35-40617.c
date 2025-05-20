//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// structure to represent a node in the graph
typedef struct Node {
    int value;
    int num_neighbors;
    struct Node** neighbors;
} Node;

// function to create a new node with specified value
Node* create_node(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->num_neighbors = 0;
    node->neighbors = (Node**) malloc(MAX_SIZE * sizeof(Node*));
    return node;
}

// function to add an edge between two nodes
void add_edge(Node* node1, Node* node2) {
    node1->neighbors[node1->num_neighbors++] = node2;
    node2->neighbors[node2->num_neighbors++] = node1;
}

// function to print the graph in adjacency list representation
void print_graph(Node* nodes[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: ", nodes[i]->value);
        for (int j = 0; j < nodes[i]->num_neighbors; j++) {
            printf("%d ", nodes[i]->neighbors[j]->value);
        }
        printf("\n");
    }
}

int main() {
    Node* nodes[MAX_SIZE];
    int num_nodes = 0;

    /* introspection: 
     * 1. create nodes
     * 2. add edges between nodes
     * 3. print graph
     */

    // 1. create nodes
    nodes[num_nodes++] = create_node(1);
    nodes[num_nodes++] = create_node(2);
    nodes[num_nodes++] = create_node(3);
    nodes[num_nodes++] = create_node(4);
    nodes[num_nodes++] = create_node(5);

    // 2. add edges between nodes
    add_edge(nodes[0], nodes[1]);
    add_edge(nodes[0], nodes[2]);
    add_edge(nodes[1], nodes[2]);
    add_edge(nodes[2], nodes[3]);
    add_edge(nodes[3], nodes[4]);

    // 3. print graph
    printf("Graph in adjacency list representation: \n");
    print_graph(nodes, num_nodes);

    return 0;
}