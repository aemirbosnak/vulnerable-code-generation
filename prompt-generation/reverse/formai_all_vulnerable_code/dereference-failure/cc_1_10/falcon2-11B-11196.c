//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct to represent a node in the graph
typedef struct node {
    int vertex;
    int weight;
    struct node *next;
} node;

// Define a struct to represent the graph
typedef struct graph {
    int numVertices;
    int numEdges;
    node **adjList;
} graph;

// Function to create a new node
node* createNode(int vertex, int weight) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
graph* createGraph(int numVertices, int numEdges) {
    graph *newGraph = (graph*)malloc(sizeof(graph));
    newGraph->numVertices = numVertices;
    newGraph->numEdges = numEdges;
    newGraph->adjList = (node**)malloc(numVertices * sizeof(node*));
    return newGraph;
}

// Function to add an edge to the graph
void addEdge(graph* graph, int v1, int v2, int weight) {
    node *newNode = createNode(v2, weight);
    newNode->next = graph->adjList[v1];
    graph->adjList[v1] = newNode;
    graph->numEdges++;
}

// Function to print the graph
void printGraph(graph* graph) {
    printf("Vertices:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        node* current = graph->adjList[i];
        while (current!= NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
    printf("Edges:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        node* current = graph->adjList[i];
        while (current!= NULL) {
            printf("%d -> %d: %d\n", i, current->vertex, current->weight);
            current = current->next;
        }
    }
}

int main() {
    int numVertices = 5;
    int numEdges = 10;
    graph* graph = createGraph(numVertices, numEdges);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 7);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 4, 9);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 2, 5, 2);
    addEdge(graph, 3, 5, 6);
    addEdge(graph, 4, 5, 8);
    printGraph(graph);
    free(graph->adjList);
    free(graph);
    return 0;
}