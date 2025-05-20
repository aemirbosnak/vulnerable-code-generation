//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

void createGraph(Node** graph, int numVertices) {
    *graph = (Node*)malloc(numVertices * sizeof(Node));
    for (int i = 0; i < numVertices; i++) {
        (*graph)[i].name[0] = '\0';
        (*graph)[i].next = NULL;
    }
}

void addEdge(Node* node, char* destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name[0] = '\0';
    newNode->next = NULL;
    strcpy(newNode->name, destination);
    node->next = newNode;
}

void printGraph(Node* node) {
    while (node) {
        printf("%s -> ", node->name);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node** graph;
    createGraph(&graph, MAX_VERTICES);

    addEdge(graph[0], "B");
    addEdge(graph[0], "C");
    addEdge(graph[1], "D");
    addEdge(graph[2], "E");

    printGraph(graph[0]);
    printGraph(graph[1]);
    printGraph(graph[2]);

    return 0;
}