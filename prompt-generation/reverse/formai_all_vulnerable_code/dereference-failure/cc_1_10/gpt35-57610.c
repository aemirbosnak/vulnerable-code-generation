//FormAI DATASET v1.0 Category: Graph representation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

// This program represents a graph using adjacency list representation in C.

// To start with, we will define a structure to represent a node in the graph.
struct Node {
    int vertex;
    struct Node* next;
};

// Now, we will define a structure to represent the graph itself.
struct Graph {
    int numVertices;
    struct Node** adjList; // A double pointer to represent the adjacency list
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error creating a new node. Exiting program.\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with the given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    if (graph == NULL) {
        fprintf(stderr, "Error creating a new graph. Exiting program.\n");
        exit(1);
    }
    graph->numVertices = numVertices;

    graph->adjList = malloc(numVertices * sizeof(struct Node*));
    if (graph->adjList == NULL) {
        fprintf(stderr, "Error creating adjacency list. Exiting program.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Adding edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Adding edge from destination to source
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d -> ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}