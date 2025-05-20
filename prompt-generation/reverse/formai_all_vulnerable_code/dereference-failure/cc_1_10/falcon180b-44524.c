//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for the graph
typedef struct graph {
    int numVertices;
    Node** adjList;
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->numVertices = numVertices;
    newGraph->adjList = (Node**)malloc(sizeof(Node*) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int vertex1, int vertex2) {
    Node* newNode = createNode(vertex2);
    newNode->next = graph->adjList[vertex1];
    graph->adjList[vertex1] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        Node* currNode = graph->adjList[i];
        while (currNode!= NULL) {
            printf("%d ", currNode->data);
            currNode = currNode->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}