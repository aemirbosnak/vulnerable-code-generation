//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// define a node structure for the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// define a graph structure
typedef struct graph {
    Node* nodes;
    int size;
} Graph;

// function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// function to create a new graph
Graph* newGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = NULL;
    graph->size = 0;
    return graph;
}

// function to add a node to the graph
void addNode(Graph* graph, int data) {
    Node* node = newNode(data);
    node->next = graph->nodes;
    graph->nodes = node;
    graph->size++;
}

// function to remove a node from the graph
void removeNode(Graph* graph, int data) {
    Node* curr = graph->nodes;
    Node* prev = NULL;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr!= NULL) {
        if (prev == NULL) {
            graph->nodes = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
        graph->size--;
    }
}

// function to print the graph
void printGraph(Graph* graph) {
    Node* curr = graph->nodes;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

// main function to test the graph implementation
int main() {
    Graph* graph = newGraph();
    addNode(graph, 1);
    addNode(graph, 2);
    addNode(graph, 3);
    printGraph(graph);
    removeNode(graph, 2);
    printGraph(graph);
    return 0;
}