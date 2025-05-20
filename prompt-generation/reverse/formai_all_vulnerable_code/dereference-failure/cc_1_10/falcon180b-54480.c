//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void addEdge(Node* node1, Node* node2);
void printGraph(Node* graph);

int main() {
    // Create the nodes
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);

    // Add edges between the nodes
    addEdge(node1, node2);
    addEdge(node2, node3);
    addEdge(node3, node4);

    // Print the graph
    printGraph(node1);

    return 0;
}

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge between two nodes
void addEdge(Node* node1, Node* node2) {
    node1->next = node2;
}

// Function to print the graph
void printGraph(Node* graph) {
    while (graph!= NULL) {
        printf("%d -> ", graph->data);
        graph = graph->next;
    }
    printf("NULL\n");
}