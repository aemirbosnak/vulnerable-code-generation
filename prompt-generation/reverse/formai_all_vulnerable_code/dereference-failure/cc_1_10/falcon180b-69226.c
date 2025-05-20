//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define graph structure
typedef struct graph {
    int vertices;
    Node** adj_matrix;
} Graph;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph with given number of vertices
Graph* createGraph(int vertices) {
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    if (!newGraph) {
        printf("Memory error\n");
        exit(0);
    }
    newGraph->vertices = vertices;
    newGraph->adj_matrix = (Node**) malloc(vertices * sizeof(Node*));
    if (!newGraph->adj_matrix) {
        printf("Memory error\n");
        exit(0);
    }
    for (int i = 0; i < vertices; i++) {
        newGraph->adj_matrix[i] = NULL;
    }
    return newGraph;
}

// Function to add an edge between two vertices in the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adj_matrix[src];
    graph->adj_matrix[src] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adj_matrix[i];
        printf("Vertex %d is connected to: ", i);
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the graph implementation
int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    printGraph(graph);
    return 0;
}