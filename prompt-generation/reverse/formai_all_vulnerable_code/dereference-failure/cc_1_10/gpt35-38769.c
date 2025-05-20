//FormAI DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 20

typedef struct Node {
    int vertexNumber;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertexNumber = v;
    newNode->next = NULL;
    return newNode;
}

typedef struct Graph {
    Node* vertices[MAX_VERTICES];
    int vertexCount;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = 0;
    int i;
    for(i=0;i<MAX_VERTICES;i++) {
        graph->vertices[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->vertices[src];
    graph->vertices[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->vertices[dest];
    graph->vertices[dest] = newNode;
}

void printGraph(Graph* graph) {
    int v;
    for(v=0;v<graph->vertexCount;v++) {
        Node* currentNode = graph->vertices[v];
        printf("Vertex %d: ", v);
        while(currentNode!=NULL) {
            printf("%d ", currentNode->vertexNumber);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph();
    graph->vertexCount = 5;
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