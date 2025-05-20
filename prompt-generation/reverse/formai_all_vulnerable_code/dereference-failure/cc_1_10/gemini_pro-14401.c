//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Graph {
    int numVertices;
    int numEdges;
    struct Node **adjLists;
};

struct Graph* createGraph(int numVertices) {
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = NULL;

    if (graph->adjLists[src] == NULL) {
        graph->adjLists[src] = newNode;
    } else {
        struct Node *temp = graph->adjLists[src];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    graph->numEdges++;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node *temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}