//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Graph {
    Node** graph;
    int numVertices;
    int numEdges;
    int isCyclic;
};

void insertVertex(struct Graph* graph) {
    graph->numVertices++;
    graph->graph = realloc(graph->graph, graph->numVertices * sizeof(Node*));
    graph->graph[graph->numVertices - 1] = malloc(sizeof(Node));
    graph->graph[graph->numVertices - 1]->data = 0;
    graph->graph[graph->numVertices - 1]->next = NULL;
}

void insertEdge(struct Graph* graph, int srcVertex, int destVertex) {
    graph->numEdges++;
    graph->graph[srcVertex]->next = malloc(sizeof(Node));
    graph->graph[srcVertex]->next->data = destVertex;
    graph->graph[srcVertex]->next->next = NULL;
}

void DFS(struct Graph* graph, int currentVertex, int* visitedVertices, int* currentPath) {
    visitedVertices[currentVertex] = 1;
    currentPath[currentVertex] = 1;

    for (Node* neighbor = graph->graph[currentVertex]->next; neighbor; neighbor) {
        if (!visitedVertices[neighbor->data] && currentPath[neighbor->data] == 0) {
            DFS(graph, neighbor->data, visitedVertices, currentPath);
        }
    }
}

int main() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->graph = NULL;
    graph->isCyclic = 0;

    insertVertex(graph);
    insertVertex(graph);
    insertVertex(graph);
    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);

    int visitedVertices[MAX_SIZE] = {0};
    int currentPath[MAX_SIZE] = {0};

    DFS(graph, 0, visitedVertices, currentPath);

    for (int i = 0; i < graph->numVertices; i++) {
        if (visitedVertices[i] == 0) {
            graph->isCyclic = 1;
            break;
        }
    }

    if (graph->isCyclic) {
        printf("The graph has cycles.\n");
    } else {
        printf("The graph has no cycles.\n");
    }

    return 0;
}