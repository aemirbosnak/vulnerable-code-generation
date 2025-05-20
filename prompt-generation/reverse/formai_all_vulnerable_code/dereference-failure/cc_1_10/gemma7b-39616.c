//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
// The Sign of Four - A Graph Representation Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10

typedef struct Node {
    int index;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** graph;
    int numVertices;
    int numEdges;
} Graph;

void insertVertex(Graph* graph) {
    graph->numVertices++;
    graph->graph = (Node**)realloc(graph->graph, graph->numVertices * sizeof(Node));
    graph->graph[graph->numVertices - 1] = (Node*)malloc(sizeof(Node));
    graph->graph[graph->numVertices - 1]->index = graph->numVertices - 1;
    graph->graph[graph->numVertices - 1]->next = NULL;
}

void insertEdge(Graph* graph, int src, int dest) {
    graph->numEdges++;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = dest;
    newNode->next = NULL;

    graph->graph[src]->next = newNode;
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->graph = NULL;

    insertVertex(graph);
    insertVertex(graph);
    insertVertex(graph);

    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", graph->graph[i]->index);
        Node* current = graph->graph[i]->next;
        while (current) {
            printf("-> Vertex %d", current->index);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}