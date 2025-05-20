//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** graph;
    int numVertices;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->graph = (Node**)malloc(MAX_Vertices * sizeof(Node));
    graph->numVertices = 0;
    return graph;
}

void addVertex(Graph* graph, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->numVertices == 0) {
        graph->graph[0] = newNode;
    } else {
        graph->graph[graph->numVertices] = newNode;
    }
    graph->numVertices++;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->graph[i];
        printf("Vertex %d: ", current->data);
        while (current->next) {
            current = current->next;
            printf("-> ");
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    addVertex(graph, 4);
    addVertex(graph, 5);

    traverseGraph(graph);

    return 0;
}