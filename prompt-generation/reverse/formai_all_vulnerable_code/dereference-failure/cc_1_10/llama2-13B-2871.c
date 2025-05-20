//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph node
typedef struct node {
    int label; // Node label
    struct node *next; // Next node in the graph
} Node;

// Function to create a new node
Node *new_node(int label) {
    Node *node = malloc(sizeof(Node));
    node->label = label;
    node->next = NULL;
    return node;
}

// Function to add a node to the graph
void add_node(Node **graph, int label) {
    Node *node = new_node(label);
    if (*graph == NULL) {
        *graph = node;
    } else {
        (*graph)->next = node;
    }
}

// Function to traverse the graph
void traverse(Node *graph) {
    if (graph != NULL) {
        printf("%d -> ", graph->label);
        traverse(graph->next);
    }
}

// Main function
int main() {
    Node *graph = NULL;

    // Create a graph with nodes 1 to 5
    add_node(&graph, 1);
    add_node(&graph, 2);
    add_node(&graph, 3);
    add_node(&graph, 4);
    add_node(&graph, 5);

    // Traverse the graph
    traverse(graph);

    return 0;
}