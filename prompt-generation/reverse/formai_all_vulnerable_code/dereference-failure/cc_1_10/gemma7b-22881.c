//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node** adjacencyList;
    int numVertices;
};

void insertVertex(struct Graph* graph, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->adjacencyList == NULL) {
        graph->adjacencyList = (struct Node**)malloc(sizeof(struct Node*) * graph->numVertices);
        graph->numVertices++;
    }

    graph->adjacencyList[data] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->adjacencyList = NULL;
    graph->numVertices = 0;

    insertVertex(graph, 0);
    insertVertex(graph, 1);
    insertVertex(graph, 2);
    insertVertex(graph, 3);

    printGraph(graph);

    return 0;
}