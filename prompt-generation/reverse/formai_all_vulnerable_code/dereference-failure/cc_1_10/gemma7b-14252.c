//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Node {
    int index;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    int numEdges;
    Node** adjacencyList;
} Graph;

void createGraph(Graph* graph) {
    graph->numVertices = MAX_Vertices;
    graph->numEdges = MAX_Edges;
    graph->adjacencyList = (Node**)malloc(graph->numVertices * sizeof(Node*));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];
        while (current) {
            printf("Vertex %d is connected to Vertex %d\n", i, current->index);
            current = current->next;
        }
    }
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    createGraph(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    traverseGraph(graph);

    return 0;
}