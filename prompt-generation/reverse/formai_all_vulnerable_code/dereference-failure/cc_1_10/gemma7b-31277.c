//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Graph {
    Node* head;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->head = NULL;
    graph->numVertices = numVertices;
    return graph;
}

void addVertex(Graph* graph, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (graph->head == NULL) {
        graph->head = newNode;
    } else {
        graph->head->next = newNode;
    }

    graph->numVertices++;
}

void traverseGraph(Graph* graph) {
    Node* current = graph->head;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph(5);
    addVertex(graph, "A");
    addVertex(graph, "B");
    addVertex(graph, "C");
    addVertex(graph, "D");
    addVertex(graph, "E");

    traverseGraph(graph);

    return 0;
}