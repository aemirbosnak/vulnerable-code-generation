//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->head = NULL;
    graph->size = 0;
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;

    if (graph->head == NULL) {
        graph->head = newNode;
    } else {
        Node* temp = graph->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    graph->size++;
}

void printGraph(Graph* graph) {
    Node* temp = graph->head;
    printf("Graph representation:\n");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph();
    int numVertices, numEdges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Enter the edge (%d %d): ", i + 1, i + 2);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Graph representation:\n");
    printGraph(graph);

    return 0;
}