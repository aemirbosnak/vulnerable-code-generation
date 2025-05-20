//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define a function to create a new graph
Node* createGraph() {
    Node* root = NULL;
    return root;
}

// Define a function to insert a node into the graph
void insertNode(Node* graph, int data) {
    Node* newNode = createNode(data);
    if (graph == NULL) {
        graph = newNode;
    } else {
        Node* current = graph;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Define a function to print the graph
void printGraph(Node* graph) {
    Node* current = graph;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* graph = createGraph();
    insertNode(graph, 1);
    insertNode(graph, 2);
    insertNode(graph, 3);
    insertNode(graph, 4);
    insertNode(graph, 5);
    insertNode(graph, 6);
    insertNode(graph, 7);
    insertNode(graph, 8);
    insertNode(graph, 9);
    insertNode(graph, 10);
    printGraph(graph);
    return 0;
}