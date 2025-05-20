//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct graph {
    Node *head;
    int numNodes;
} Graph;

// Function to add a node to the graph
void addNode(Graph *graph, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (graph->head == NULL) {
        graph->head = newNode;
    } else {
        Node *current = graph->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    graph->numNodes++;
}

// Function to print the graph
void printGraph(Graph *graph) {
    Node *current = graph->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Graph myGraph;
    myGraph.head = NULL;
    myGraph.numNodes = 0;
    
    addNode(&myGraph, 1);
    addNode(&myGraph, 2);
    addNode(&myGraph, 3);
    addNode(&myGraph, 4);
    addNode(&myGraph, 5);
    addNode(&myGraph, 6);
    
    printGraph(&myGraph);
    
    return 0;
}