//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in the graph
typedef struct node {
    int id;
    struct node* edges[10]; // Max 10 edges per node
} Node;

// Create a new node with the given ID
Node* create_node(int id) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->id = id;
    for (int i = 0; i < 10; i++) {
        new_node->edges[i] = NULL;
    }
    return new_node;
}

// Connect two nodes by their IDs
void connect_nodes(Node* node1, int id2) {
    Node* node2 = create_node(id2);
    node1->edges[node1->id % 10] = node2;
}

// Print the graph in a readable format
void print_graph(Node* start_node) {
    printf("Graph:\n");
    for (int i = 0; i < 10; i++) {
        Node* current_node = start_node->edges[i];
        while (current_node!= NULL) {
            printf("%d -> %d\n", start_node->id, current_node->id);
            current_node = current_node->edges[current_node->id % 10];
        }
    }
}

// Main function to test the graph implementation
int main() {
    Node* node1 = create_node(1);
    Node* node2 = create_node(2);
    Node* node3 = create_node(3);

    connect_nodes(node1, 2);
    connect_nodes(node1, 3);

    connect_nodes(node2, 1);
    connect_nodes(node2, 3);

    connect_nodes(node3, 1);
    connect_nodes(node3, 2);

    print_graph(node1);

    return 0;
}