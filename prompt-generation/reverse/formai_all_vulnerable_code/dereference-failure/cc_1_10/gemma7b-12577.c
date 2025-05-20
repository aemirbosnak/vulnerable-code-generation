//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node** adjList;
    int numVertices;
};

void insertNode(struct Graph* graph, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->adjList[data] == NULL) {
        graph->adjList[data] = newNode;
    } else {
        graph->adjList[data]->next = newNode;
    }
}

void traverseGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->adjList[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = MAX;
    graph->adjList = (struct Node**)malloc(sizeof(struct Node*) * MAX);

    insertNode(graph, 0);
    insertNode(graph, 1);
    insertNode(graph, 2);
    insertNode(graph, 3);
    insertNode(graph, 4);

    traverseGraph(graph);

    return 0;
}