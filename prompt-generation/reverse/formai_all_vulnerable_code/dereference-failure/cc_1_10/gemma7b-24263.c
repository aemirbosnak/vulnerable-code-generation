//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->adjList = (Node**)malloc(MAX_VERTS * sizeof(Node*));
    for (int i = 0; i < MAX_VERTS; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addVertex(Graph* graph, int data) {
    graph->numVertices++;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    graph->adjList[data] = newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = NULL;
    graph->adjList[src]->next = newNode;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjList[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph, 0);
    addVertex(graph, 1);
    addVertex(graph, 2);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    traverseGraph(graph);

    return 0;
}