//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_CONN 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** graph;
    int size;
} Graph;

Graph* createGraph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = size;
    graph->graph = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        graph->graph[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, char source, char destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = destination;
    newNode->next = NULL;

    Node* prevNode = NULL;
    for (Node* node = graph->graph[source]; node; node = node->next) {
        if (prevNode) {
            prevNode = node;
        }
    }

    if (prevNode) {
        prevNode->next = newNode;
    } else {
        graph->graph[source] = newNode;
    }
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        for (Node* node = graph->graph[i]; node; node = node->next) {
            printf("%c ", node->data);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 'a', 'b');
    addEdge(graph, 'a', 'c');
    addEdge(graph, 'b', 'd');
    addEdge(graph, 'c', 'e');

    traverseGraph(graph);

    return 0;
}