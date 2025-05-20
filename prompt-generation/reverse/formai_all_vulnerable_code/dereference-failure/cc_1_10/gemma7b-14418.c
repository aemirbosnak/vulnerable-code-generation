//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Graph {
    struct Node *nodes;
    int numNodes;
} Graph;

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Graph *createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->nodes = NULL;
    graph->numNodes = 0;
    return graph;
}

void addNode(Graph *graph, char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->nodes == NULL) {
        graph->nodes = newNode;
    } else {
        graph->nodes->next = newNode;
    }

    graph->numNodes++;
}

void traverseGraph(Graph *graph) {
    Node *current = graph->nodes;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Graph *graph = createGraph();
    addNode(graph, 'a');
    addNode(graph, 'b');
    addNode(graph, 'c');
    addNode(graph, 'd');
    traverseGraph(graph);

    return 0;
}