//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct Node {
    int data;
    struct Node *next;
};

struct Graph {
    struct Node *head;
    int numVertices;
    int numEdges;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph() {
    struct Graph *newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->head = NULL;
    newGraph->numVertices = 0;
    newGraph->numEdges = 0;
    return newGraph;
}

void addVertex(struct Graph* graph, int vertex) {
    struct Node* newVertex = createNode(vertex);
    graph->head = newVertex;
    graph->numVertices++;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newEdge = createNode(dest);
    struct Node* temp = graph->head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newEdge;
    graph->numEdges++;
}

void printGraph(struct Graph* graph) {
    struct Node* temp = graph->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph();
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    return 0;
}