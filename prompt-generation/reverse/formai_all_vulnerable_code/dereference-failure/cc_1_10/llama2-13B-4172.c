//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int label;    // Label of the node
    struct Node* next; // Next node in the graph
    struct Node* prev; // Previous node in the graph
};

// Function to create a new node
struct Node* newNode(int label) {
    struct Node* node = malloc(sizeof(struct Node));
    node->label = label;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Function to add an edge to the graph
void addEdge(struct Node** graph, int label1, int label2) {
    // Create new nodes for the edge
    struct Node* node1 = newNode(label1);
    struct Node* node2 = newNode(label2);

    // Add the edge to the graph
    node1->next = node2;
    node2->prev = node1;

    // Add the nodes to the graph
    *graph = node1;
}

// Function to print the graph
void printGraph(struct Node* graph) {
    // Print the nodes in the graph
    while (graph != NULL) {
        printf("%d ", graph->label);
        graph = graph->next;
    }
    printf("\n");
}

int main() {
    // Create a new graph
    struct Node* graph = NULL;

    // Add some edges to the graph
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 1);

    // Print the graph
    printGraph(graph);

    return 0;
}