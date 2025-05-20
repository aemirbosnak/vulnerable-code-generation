//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node** adjList, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void printAdjList(Node** adjList, int n) {
    printf("Adjacency list representation of graph:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
        Node* curr = adjList[i];
        while (curr) {
            printf("-> %d ", curr->vertex);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    int n = 6;
    Node* adjList[n+1];
    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
    }

    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 4, 5);
    addEdge(adjList, 6, 4);

    printAdjList(adjList, n);

    return 0;
}