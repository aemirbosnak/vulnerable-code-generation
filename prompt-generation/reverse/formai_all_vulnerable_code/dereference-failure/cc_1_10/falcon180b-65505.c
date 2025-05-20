//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a graph
typedef struct graph {
    int numVertices;
    Node* vertices;
} Graph;

// Function to initialize the graph
void initGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    graph->vertices = (Node*) malloc(numVertices * sizeof(Node));
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i].data = i;
        graph->vertices[i].next = NULL;
    }
}

// Function to add an edge between two nodes
void addEdge(Graph* graph, int vertex1, int vertex2) {
    Node* node1 = &graph->vertices[vertex1];
    Node* node2 = &graph->vertices[vertex2];
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = vertex2;
    newNode->next = node1->next;
    node1->next = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* node = &graph->vertices[i];
        printf("Vertex %d: ", i);
        while (node->next!= NULL) {
            printf("%d ", node->next->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    initGraph(&graph, 5);
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    printGraph(&graph);
    return 0;
}