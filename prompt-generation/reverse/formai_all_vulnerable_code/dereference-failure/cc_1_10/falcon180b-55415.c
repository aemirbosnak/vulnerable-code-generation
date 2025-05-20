//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define the structure of a graph
typedef struct Graph {
    int numVertices;
    Node **adjList;
} Graph;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
Graph *createGraph(int numVertices) {
    Graph *newGraph = (Graph *) malloc(sizeof(Graph));
    newGraph->numVertices = numVertices;
    newGraph->adjList = (Node **) malloc(numVertices * sizeof(Node *));
    for (int i = 0; i < numVertices; i++) {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    Node *srcNode = graph->adjList[src];
    Node *destNode = graph->adjList[dest];
    if (srcNode == NULL) {
        srcNode = createNode(src);
        graph->adjList[src] = srcNode;
    }
    if (destNode == NULL) {
        destNode = createNode(dest);
        graph->adjList[dest] = destNode;
    }
    Node *newNode = createNode(src);
    newNode->next = destNode;
    srcNode->next = newNode;
}

// Function to print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        Node *currentNode = graph->adjList[i];
        while (currentNode!= NULL) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    printGraph(graph);
    return 0;
}