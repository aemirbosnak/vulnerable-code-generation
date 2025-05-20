//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODES 100

typedef struct node {
    char* data;
    int weight;
    struct node* next;
} Node;

typedef struct graph {
    Node* head;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->head = NULL;
    return graph;
}

void addNode(Graph* graph, char* data, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->weight = weight;
    newNode->next = NULL;

    if (graph->head == NULL) {
        graph->head = newNode;
    } else {
        Node* current = graph->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printGraph(Graph* graph) {
    if (graph->head == NULL) {
        printf("Graph is empty.\n");
        return;
    }

    Node* current = graph->head;
    while (current!= NULL) {
        printf("Node %s with weight %d connected to: ", current->data, current->weight);
        current = current->next;
        while (current!= NULL) {
            printf("%s ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph();

    addNode(graph, "A", 10);
    addNode(graph, "B", 20);
    addNode(graph, "C", 30);

    addNode(graph, "D", 10);
    addNode(graph, "E", 20);
    addNode(graph, "F", 30);

    addNode(graph, "G", 10);
    addNode(graph, "H", 20);
    addNode(graph, "I", 30);

    printGraph(graph);

    return 0;
}