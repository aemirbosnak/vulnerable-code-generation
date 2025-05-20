//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    char* name;
    int weight;
    struct Node* next;
} Edge;

typedef struct {
    char* name;
    int weight;
    Edge* edges;
} Node;

Node* createNode(char* name, int weight) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("malloc");
        exit(1);
    }
    newNode->name = strdup(name);
    newNode->weight = weight;
    newNode->edges = NULL;
    return newNode;
}

Edge* createEdge(char* name, int weight, Node* node) {
    Edge* newEdge = malloc(sizeof(Edge));
    if (newEdge == NULL) {
        perror("malloc");
        exit(1);
    }
    newEdge->name = strdup(name);
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(Node* node, Edge* edge) {
    if (node->edges == NULL) {
        node->edges = edge;
    } else {
        Edge* current = node->edges;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = edge;
    }
}

void addNode(Node* node) {
    if (node == NULL) {
        return;
    }
    addEdge(node, createEdge("A", 1, node));
    addEdge(node, createEdge("B", 2, node));
    addEdge(node, createEdge("C", 3, node));
}

void printGraph(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%s: %d\n", node->name, node->weight);
    Edge* current = node->edges;
    while (current!= NULL) {
        Edge* next = current->next;
        printf("-> %s: %d\n", current->name, current->weight);
        current = next;
    }
}

int main() {
    Node* root = createNode("Root", 0);
    addNode(root);
    printGraph(root);
    return 0;
}