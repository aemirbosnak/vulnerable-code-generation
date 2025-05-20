//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// A Node structure
typedef struct {
    int data;
    struct Node* next;
} Node;

// A Graph structure
typedef struct {
    Node* head;
} Graph;

// Function to add a new node
void addNode(Node** head_ref, int data) {
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    Node* temp = graph->head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a new graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->head = NULL;

    // Add nodes to the graph
    addNode(&(graph->head), 1);
    addNode(&(graph->head), 2);
    addNode(&(graph->head), 3);
    addNode(&(graph->head), 4);

    // Print the graph
    printf("Graph:\n");
    printGraph(graph);

    return 0;
}