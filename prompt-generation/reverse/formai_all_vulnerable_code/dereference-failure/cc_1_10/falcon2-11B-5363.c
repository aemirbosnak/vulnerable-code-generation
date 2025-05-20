//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the graph structure
struct Graph {
    struct Node* head;
};

// Function to add a new node to the graph
struct Node* addNode(struct Graph* graph, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (graph->head == NULL) {
        graph->head = newNode;
    } else {
        struct Node* current = graph->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    return newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    struct Node* current = graph->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new graph
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Add nodes to the graph
    addNode(graph, 1);
    addNode(graph, 2);
    addNode(graph, 3);
    addNode(graph, 4);
    
    // Print the graph
    printf("Graph representation:\n");
    printGraph(graph);
    
    return 0;
}