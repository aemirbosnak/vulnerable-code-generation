//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Custom data structure to represent a graph
typedef struct node {
    int label;   // label of the node
    struct node* next; // pointer to the next node in the graph
} Node;

// Function to create a new graph
Node* newGraph(void) {
    Node* graph = (Node*) malloc(sizeof(Node));
    graph->label = 0;
    graph->next = NULL;
    return graph;
}

// Function to add a node to the graph
void addNode(Node** graph, int label) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->label = label;
    newNode->next = *graph;
    *graph = newNode;
}

// Function to add an edge to the graph
void addEdge(Node** graph, int label1, int label2) {
    Node* node1 = *graph;
    while (node1->next != NULL && node1->next->label != label2) {
        node1 = node1->next;
    }
    if (node1->next == NULL || node1->next->label != label2) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->label = label2;
        newNode->next = NULL;
        node1->next = newNode;
    }
}

// Function to traverse the graph
void traverse(Node* graph) {
    if (graph == NULL) {
        return;
    }
    printf("%d ", graph->label);
    traverse(graph->next);
}

int main(void) {
    Node* graph = newGraph();

    addNode(&graph, 1);
    addNode(&graph, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 1, 4);

    traverse(graph);

    return 0;
}