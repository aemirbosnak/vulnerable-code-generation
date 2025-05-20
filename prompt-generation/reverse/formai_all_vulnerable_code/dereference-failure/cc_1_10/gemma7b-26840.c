//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define GRAPH_SIZE 10

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

Node** graph = NULL;

void createGraph() {
    graph = (Node**)malloc( GRAPH_SIZE * sizeof(Node*) );
    for (int i = 0; i < GRAPH_SIZE; i++) {
        graph[i] = NULL;
    }
}

void addVertex(char* name) {
    Node* newNode = (Node*)malloc( sizeof(Node) );
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (graph[0] == NULL) {
        createGraph();
    }

    graph[0]->next = newNode;
    graph[0] = newNode;
}

void traverseGraph() {
    Node* current = graph[0]->next;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    addVertex("A");
    addVertex("B");
    addVertex("C");
    traverseGraph();

    return 0;
}