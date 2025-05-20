//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjacencyList;
    int size;
} Graph;

Graph* createGraph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjacencyList = (Node**)malloc(sizeof(Node*) * size);
    graph->size = size;
    return graph;
}

void addNode(Graph* graph, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (graph->adjacencyList[graph->size - 1] != NULL) {
        graph->adjacencyList[graph->size - 1]->next = newNode;
    } else {
        graph->adjacencyList[graph->size - 1] = newNode;
    }

    graph->size++;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%s ", current->name);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addNode(graph, "A");
    addNode(graph, "B");
    addNode(graph, "C");
    addNode(graph, "D");
    addNode(graph, "E");

    traverseGraph(graph);

    return 0;
}