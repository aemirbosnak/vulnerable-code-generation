//FormAI DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VERTICES 10

typedef struct _node {
    int destIndex;
    struct _node* next;
} Node;

typedef struct _graph {
    int numVertices;
    Node** adjList;
} Graph;

Node* createNode(int destIndex) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->destIndex = destIndex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    newGraph->numVertices = numVertices;

    newGraph->adjList = (Node**) malloc(numVertices * sizeof(Node*));
    for(int i = 0; i < numVertices; i++) {
        newGraph->adjList[i] = NULL;
    }

    return newGraph;
}

void addEdge(Graph* graph, int srcIndex, int destIndex) {
    Node* newNode = createNode(destIndex);
    newNode->next = graph->adjList[srcIndex];
    graph->adjList[srcIndex] = newNode;
}

void printGraph(Graph* graph) {
    printf("Graph:\n");
    for(int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node* tmp = graph->adjList[i];
        while(tmp) {
            printf("%d -> ", tmp->destIndex);
            tmp = tmp->next;
        }
        printf("NULL\n");
    }
}

void destroyGraph(Graph* graph) {
    for(int i = 0; i < graph->numVertices; i++) {
        Node* tmp = graph->adjList[i];
        while(tmp) {
            Node* delNode = tmp;
            tmp = tmp->next;
            free(delNode);
        }
    }
    free(graph->adjList);
    free(graph);
}

int main() {
    srand(time(NULL));

    Graph* myGraph = createGraph(MAX_VERTICES);

    for(int i = 0; i < MAX_VERTICES; i++) {
        for(int j = 0; j < MAX_VERTICES / 2; j++) {
            int r = rand() % MAX_VERTICES;
            addEdge(myGraph, i, r);
        }
    }

    printGraph(myGraph);

    destroyGraph(myGraph);

    return 0;
}