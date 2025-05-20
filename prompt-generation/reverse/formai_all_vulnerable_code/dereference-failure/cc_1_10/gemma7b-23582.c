//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    char name[MAX];
    struct Node* next;
} Node;

typedef struct Graph {
    Node** graph;
    int size;
} Graph;

Graph* createGraph(int size) {
    Graph* graph = malloc(sizeof(Graph));
    graph->graph = malloc(size * sizeof(Node*));
    graph->size = size;
    return graph;
}

void insertNode(Graph* graph, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (graph->size == 0) {
        graph->graph[0] = newNode;
    } else {
        graph->graph[graph->size - 1]->next = newNode;
    }
    graph->size++;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node* node = graph->graph[i];
        printf("%s ", node->name);
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph(5);
    insertNode(graph, "John");
    insertNode(graph, "Mary");
    insertNode(graph, "Bob");
    insertNode(graph, "Alice");
    insertNode(graph, "Tom");

    printGraph(graph);

    return 0;
}