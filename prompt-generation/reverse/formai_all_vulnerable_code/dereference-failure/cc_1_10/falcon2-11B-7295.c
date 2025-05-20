//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

typedef struct node {
    int color;
    int degree;
    struct node* next;
} Node;

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->color = INT_MAX;
    node->degree = 0;
    node->next = NULL;
    return node;
}

void addEdge(Node* src, Node* dest) {
    Node* newNode = createNode();
    newNode->next = src->next;
    src->next = newNode;
    newNode->next = dest;
    newNode->next->next = newNode;
    newNode->next->next->next = src;
    src->degree++;
    dest->degree++;
}

void graphColoring() {
    Node* nodes[MAX_NODES];
    int numNodes = 0;
    int numEdges = 0;
    int maxDegree = 0;

    // Create nodes and add edges
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = createNode();
        numNodes++;
    }
    for (int i = 0; i < MAX_NODES - 1; i++) {
        int src = rand() % MAX_NODES;
        int dest = rand() % MAX_NODES;
        addEdge(nodes[src], nodes[dest]);
        numEdges++;
    }
    for (int i = 0; i < MAX_NODES; i++) {
        maxDegree = (nodes[i]->degree > maxDegree)? nodes[i]->degree : maxDegree;
    }

    // Check if graph is 2-colorable
    int minDegree = (numNodes - numEdges) / 2;
    for (int i = 0; i < numNodes; i++) {
        if (nodes[i]->degree < minDegree) {
            printf("Graph is not 2-colorable\n");
            return;
        }
    }

    // Find coloring
    int color = 1;
    for (int i = 0; i < numNodes; i++) {
        if (nodes[i]->color == INT_MAX) {
            nodes[i]->color = color;
            color++;
        }
    }

    // Print coloring
    for (int i = 0; i < numNodes; i++) {
        printf("%d ", nodes[i]->color);
    }
}

int main() {
    graphColoring();
    return 0;
}