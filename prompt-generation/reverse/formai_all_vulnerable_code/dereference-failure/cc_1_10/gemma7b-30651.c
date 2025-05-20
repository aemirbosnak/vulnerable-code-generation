//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

struct Graph {
    Node** adjacencyList;
    int numVertices;
    int numEdges;
    char** map;
};

void createGraph(struct Graph* graph) {
    graph->adjacencyList = (Node**)malloc(graph->numVertices * sizeof(Node*));
    graph->map = (char**)malloc(graph->numVertices * sizeof(char*));
    graph->numEdges = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->map[i] = NULL;
    }
}

void addEdge(struct Graph* graph, char source, char destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = destination;
    newNode->next = NULL;
    newNode->prev = NULL;

    graph->adjacencyList[source] = newNode;
    graph->map[source] = destination;
    graph->numEdges++;
}

void traverseGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%c ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = MAX;

    createGraph(graph);
    addEdge(graph, 'a', 'b');
    addEdge(graph, 'a', 'c');
    addEdge(graph, 'b', 'd');
    addEdge(graph, 'c', 'e');

    traverseGraph(graph);

    free(graph);

    return 0;
}