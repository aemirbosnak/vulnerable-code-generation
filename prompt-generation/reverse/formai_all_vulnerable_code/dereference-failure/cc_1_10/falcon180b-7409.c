//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Structure for a node in the graph
typedef struct {
    int data;
    struct Node* next;
} Node;

//Structure for the graph
typedef struct {
    Node* nodes;
    int size;
} Graph;

//Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to create a new graph
Graph* createGraph(int size) {
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->nodes = NULL;
    newGraph->size = size;
    return newGraph;
}

//Function to add an edge between two nodes
void addEdge(Graph* graph, int node1, int node2) {
    Node* temp1 = graph->nodes;
    Node* temp2 = temp1->next;
    while(temp2!= NULL) {
        if(temp2->data == node2) {
            temp2->next = createNode(node1);
            return;
        }
        temp2 = temp2->next;
    }
    temp1->next = createNode(node2);
}

//Function to print the graph
void printGraph(Graph* graph) {
    Node* temp = graph->nodes;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main function
int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    printGraph(graph);
    return 0;
}