//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the graph structure
typedef struct graph {
    int numVertices;
    Node** adjacencyList;
} Graph;

// Function to add a vertex to the graph
void addVertex(Graph* graph, int data) {
    graph->numVertices++;
    graph->adjacencyList = (Node**)realloc(graph->adjacencyList, graph->numVertices * sizeof(Node*));
    graph->adjacencyList[graph->numVertices - 1] = NULL;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int vertex1, int vertex2) {
    Node* node1 = graph->adjacencyList[vertex1];
    Node* node2 = graph->adjacencyList[vertex2];

    if (node1 == NULL) {
        node1 = (Node*)malloc(sizeof(Node));
        node1->data = vertex1;
        node1->next = NULL;
        graph->adjacencyList[vertex1] = node1;
    }

    if (node2 == NULL) {
        node2 = (Node*)malloc(sizeof(Node));
        node2->data = vertex2;
        node2->next = NULL;
        graph->adjacencyList[vertex2] = node2;
    }

    node1->next = node2;
}

// Function to print the graph
void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        Node* node = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    graph.numVertices = 0;
    graph.adjacencyList = NULL;

    addVertex(&graph, 0);
    addVertex(&graph, 1);
    addVertex(&graph, 2);
    addVertex(&graph, 3);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 0);

    printGraph(&graph);

    return 0;
}