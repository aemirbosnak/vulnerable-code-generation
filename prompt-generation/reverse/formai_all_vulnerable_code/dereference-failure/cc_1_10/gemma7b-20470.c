//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Graph {
    Node** adjacencyList;
    int numVertices;
};

void insertVertex(struct Graph* graph, char vertex) {
    graph->numVertices++;
    graph->adjacencyList = realloc(graph->adjacencyList, graph->numVertices * MAX);
    graph->adjacencyList[graph->numVertices - 1] = malloc(sizeof(Node));
    graph->adjacencyList[graph->numVertices - 1]->data = vertex;
    graph->adjacencyList[graph->numVertices - 1]->next = NULL;
}

void insertEdge(struct Graph* graph, char source, char destination) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = destination;
    newNode->next = NULL;

    Node* temp = graph->adjacencyList[source - 'a'];
    if (temp) {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        insertVertex(graph, source);
        insertEdge(graph, source, destination);
    }
}

int main() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->adjacencyList = NULL;

    insertVertex(graph, 'a');
    insertVertex(graph, 'b');
    insertVertex(graph, 'c');

    insertEdge(graph, 'a', 'b');
    insertEdge(graph, 'b', 'c');

    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%c --> ", current->data);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}