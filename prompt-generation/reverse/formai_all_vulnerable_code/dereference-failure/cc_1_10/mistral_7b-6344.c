//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node** createGraph(int numVertices) {
    Node** graph = (Node**) calloc(numVertices, sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = NULL;
    }
    return graph;
}

void addEdge(Node** graph, int src, int dest) {
    Node* newEdge = createNode('E');
    newEdge->next = graph[src];
    graph[src] = newEdge;

    newEdge = createNode('E');
    newEdge->next = graph[dest];
    graph[dest] = newEdge;
}

void printGraph(Node** graph, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: ", i);
        Node* current = graph[i];
        while (current != NULL) {
            if (current->data == 'E') {
                printf("-->%d ", current->next->data);
            }
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;

    Node** graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph, numVertices);

    for (int i = 0; i < numVertices; i++) {
        Node* current = graph[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        free(graph[i]);
    }
    free(graph);

    return 0;
}