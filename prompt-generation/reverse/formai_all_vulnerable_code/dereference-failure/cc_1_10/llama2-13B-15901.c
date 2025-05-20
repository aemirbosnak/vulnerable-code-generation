//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 50

// Definition of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Definition of an edge
typedef struct edge {
    int from;
    int to;
} Edge;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new edge
Edge* newEdge(int from, int to) {
    Edge* edge = (Edge*) malloc(sizeof(Edge));
    edge->from = from;
    edge->to = to;
    return edge;
}

// Function to add an edge to a node
void addEdge(Node* node, Edge* edge) {
    if (node->next == NULL) {
        node->next = edge;
    } else {
        node->next->next = edge;
    }
}

// Function to print the nodes and edges in a graph
void printGraph(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("Graph:\n");

    Node* current = root;
    while (current != NULL) {
        printf("%d:", current->data);
        current = current->next;
        if (current != NULL) {
            printf(" -> %d\n", current->data);
        }
    }
}

int main() {
    // Create a new node
    Node* node1 = newNode(1);

    // Create two edges
    Edge* edge1 = newEdge(2, 3);
    Edge* edge2 = newEdge(4, 5);

    // Add edges to node1
    addEdge(node1, edge1);
    addEdge(node1, edge2);

    // Create a new node
    Node* node2 = newNode(6);

    // Add edges to node2
    addEdge(node2, newEdge(7, 8));
    addEdge(node2, newEdge(9, 10));

    // Print the graph
    printGraph(node1);

    return 0;
}