//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10

typedef struct Node {
    int index;
    struct Node* adjacencyList;
} Node;

void initializeGraph(Node* graph, int numVertices) {
    graph = (Node*)malloc(numVertices * sizeof(Node));
    for(int i = 0; i < numVertices; i++) {
        graph[i].index = i;
        graph[i].adjacencyList = NULL;
    }
}

void addEdge(Node* graph, int sourceVertex, int destinationVertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = destinationVertex;
    newNode->adjacencyList = NULL;

    graph[sourceVertex].adjacencyList = newNode;
}

void printGraph(Node* graph) {
    for(int i = 0; i < MAX_VERTS; i++) {
        printf("Vertex %d: ", graph[i].index);
        Node* current = graph[i].adjacencyList;
        while(current) {
            printf("-> Vertex %d ", current->index);
            current = current->adjacencyList;
        }
        printf("\n");
    }
}

int main() {
    Node* graph;
    initializeGraph(graph, MAX_VERTS);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}