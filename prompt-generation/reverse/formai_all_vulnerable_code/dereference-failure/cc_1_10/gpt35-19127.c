//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define a struct for the graph
typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

// Declare functions
Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);

// Main function
int main() {
    Graph* graph = createGraph(5); // Create a graph with 5 vertices
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph representation:\n");
    printGraph(graph);

    return 0;
}

// Function to create a graph with specified number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**) calloc(numVertices, sizeof(Node*));
    int i;
    for (i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src (comment out if directed graph)
    newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjList[i];
        printf("%d -> ", i);
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}