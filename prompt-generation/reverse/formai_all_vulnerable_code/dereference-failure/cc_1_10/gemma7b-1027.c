//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: shocked
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

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->adjacencyList = NULL;

    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->adjacencyList = (Node**)realloc(graph->adjacencyList, graph->numVertices * sizeof(Node));

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = graph->numVertices - 1;
    newNode->next = NULL;

    graph->adjacencyList[newNode->index] = newNode;
}

void addEdge(Graph* graph, int srcVertex, int destVertex) {
    graph->numEdges++;

    Node* srcNode = graph->adjacencyList[srcVertex];
    Node* destNode = graph->adjacencyList[destVertex];

    srcNode->next = destNode;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];

        while (current) {
            printf("(%d, %d) ", i, current->index);
            current = current->next;
        }

        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph();

    addVertex(graph);
    addVertex(graph);
    addVertex(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);

    traverseGraph(graph);

    return 0;
}