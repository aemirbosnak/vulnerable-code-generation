//FormAI DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

typedef struct Graph {
    Node* head[MAX_VERTICES];
}Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph->head[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int source, int destination) {
    Node* newNode = createNode(destination);
    newNode->next = graph->head[source];
    graph->head[source] = newNode;
}

void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        Node* temp = graph->head[i];
        printf("\nVertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Graph representation using adjacency list: \n");
    printGraph(graph);
    return 0;
}