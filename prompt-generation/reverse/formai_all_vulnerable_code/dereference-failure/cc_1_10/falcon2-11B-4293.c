//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in the graph
typedef struct node {
    int value;
    int num_edges;
    struct node* edges[10];
} Node;

// Define a function to create a new node
Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->num_edges = 0;
    node->edges[0] = NULL;
    node->edges[1] = NULL;
    node->edges[2] = NULL;
    node->edges[3] = NULL;
    node->edges[4] = NULL;
    node->edges[5] = NULL;
    node->edges[6] = NULL;
    node->edges[7] = NULL;
    node->edges[8] = NULL;
    node->edges[9] = NULL;
    return node;
}

// Define a function to add an edge to a node
void addEdge(Node* node, Node* edge) {
    node->num_edges++;
    node->edges[node->num_edges] = edge;
}

// Define a function to print a node's edges
void printEdges(Node* node) {
    for (int i = 0; i < node->num_edges; i++) {
        printf("Edge %d: %d\n", i, node->edges[i]->value);
    }
}

// Define a function to print the graph
void printGraph(Node* root) {
    printf("Graph:\n");
    printEdges(root);
}

int main() {
    // Create the root node
    Node* root = newNode(1);

    // Create a node for the first edge
    Node* node1 = newNode(2);
    addEdge(root, node1);

    // Create a node for the second edge
    Node* node2 = newNode(3);
    addEdge(root, node2);

    // Create a node for the third edge
    Node* node3 = newNode(4);
    addEdge(node2, node3);

    // Create a node for the fourth edge
    Node* node4 = newNode(5);
    addEdge(node3, node4);

    // Print the graph
    printGraph(root);

    return 0;
}