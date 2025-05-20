//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the graph
struct Node {
    int label;  // Label of the node
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

// Function to add a node to the graph
void addNode(struct Node** graph, int label) {
    struct Node* node = newNode(label);
    if (!graph) {
        printf("Invalid graph\n");
        return;
    }
    if (*graph) {
        node->next = *graph;
        (*graph)->prev = node;
        *graph = node;
    } else {
        node->next = NULL;
        node->prev = NULL;
        *graph = node;
    }
}

// Function to traverse the graph
void traverse(struct Node* graph) {
    if (!graph) {
        printf("Invalid graph\n");
        return;
    }
    printf("%d ", graph->label);
    if (graph->next) {
        traverse(graph->next);
    }
    if (graph->prev) {
        traverse(graph->prev);
    }
}

int main() {
    struct Node* graph = NULL;
    addNode(&graph, 1);
    addNode(&graph, 2);
    addNode(&graph, 3);
    addNode(&graph, 4);
    addNode(&graph, 5);
    traverse(graph);
    return 0;
}