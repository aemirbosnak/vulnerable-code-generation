//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for our graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a graph structure
typedef struct graph {
    Node* nodes;
    int size;
} Graph;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph with the given size
Graph* createGraph(int size) {
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    if (newGraph == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newGraph->nodes = NULL;
    newGraph->size = size;
    return newGraph;
}

// Function to add a node to the end of the graph
void addNode(Graph* graph, int data) {
    Node* newNode = createNode(data);
    Node* temp = graph->nodes;
    if (temp == NULL) {
        graph->nodes = newNode;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the graph in a medieval style
void printGraph(Graph* graph) {
    printf("Behold, the graph of size %d:\n", graph->size);
    Node* temp = graph->nodes;
    while (temp!= NULL) {
        printf("Node %d hath been added to the graph.\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int size;
    printf("Enter the size of the graph: ");
    scanf("%d", &size);
    Graph* graph = createGraph(size);
    int choice, data;
    while (true) {
        printf("\nWhat dost thou wish to do?\n");
        printf("1. Add a node\n2. Print the graph\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                addNode(graph, data);
                break;
            case 2:
                printGraph(graph);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}