//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in the graph
typedef struct Node {
    int id;
    struct Node* next;
} Node;

// Define a function to create a new node with a given ID
Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

// Define a function to add an edge to the graph
void addEdge(Node* start, Node* end) {
    Node* newEdge = createNode(start->id);
    start->next = newEdge;
    newEdge->next = end;
}

// Define a function to print the graph in adjacency list format
void printGraph(Node* root) {
    while (root!= NULL) {
        printf("%d -> ", root->id);
        Node* curr = root->next;
        while (curr!= NULL) {
            printf("%d ", curr->id);
            curr = curr->next;
        }
        printf("\n");
        root = root->next;
    }
}

int main() {
    // Create a new graph
    Node* root = createNode(0);

    // Add edges to the graph
    addEdge(root, createNode(1));
    addEdge(root, createNode(2));
    addEdge(root, createNode(3));
    addEdge(root, createNode(4));
    addEdge(root, createNode(5));
    addEdge(root, createNode(6));
    addEdge(root, createNode(7));
    addEdge(root, createNode(8));
    addEdge(root, createNode(9));
    addEdge(root, createNode(10));

    // Print the graph
    printf("Graph:\n");
    printGraph(root);

    return 0;
}