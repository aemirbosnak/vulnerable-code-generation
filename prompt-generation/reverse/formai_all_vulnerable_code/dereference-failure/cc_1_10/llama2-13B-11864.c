//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Graph representation as a linked list
typedef struct Graph {
    Node* head;
} Graph;

// Function to create a new graph
Graph* newGraph() {
    Graph* g = (Graph*) malloc(sizeof(struct Graph));
    g->head = NULL;
    return g;
}

// Function to add a node to the graph
void addNode(Graph* g, int data) {
    Node* newNode = (Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = g->head;
    g->head = newNode;
}

// Function to traverse the graph
void traverse(Graph* g) {
    Node* current = g->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Graph* g = newGraph();

    // Add some nodes to the graph
    addNode(g, 1);
    addNode(g, 2);
    addNode(g, 3);
    addNode(g, 4);
    addNode(g, 5);

    // Traverse the graph
    traverse(g);

    return 0;
}