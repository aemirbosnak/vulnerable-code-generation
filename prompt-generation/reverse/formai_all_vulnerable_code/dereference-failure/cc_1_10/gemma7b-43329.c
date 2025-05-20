//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: futuristic
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
    Node** adjacencyList;
} Graph;

Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->adjacencyList = NULL;

    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->adjacencyList = realloc(graph->adjacencyList, graph->numVertices * sizeof(Node*));

    graph->adjacencyList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->index = dest;
    newNode->next = graph->adjacencyList[src];

    graph->adjacencyList[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];

        printf("Vertex %d: ", i);
        while (current) {
            printf("-> Vertex %d ", current->index);
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

    printGraph(graph);

    return 0;
}