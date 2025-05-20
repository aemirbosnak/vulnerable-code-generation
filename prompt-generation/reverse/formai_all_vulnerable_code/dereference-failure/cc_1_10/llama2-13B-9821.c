//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a graph
Node* createGraph(int numNodes) {
    Node* graph = malloc(numNodes * sizeof(Node));
    for (int i = 0; i < numNodes; i++) {
        graph[i].data = i;
        graph[i].next = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Node** graph, int node1, int node2) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = node1 * node2;
    newNode->next = NULL;

    if (node1 == 0) {
        graph[0]->next = newNode;
    } else {
        graph[node1 - 1]->next = newNode;
    }

    if (node2 == 0) {
        graph[0]->next = newNode;
    } else {
        graph[node2 - 1]->next = newNode;
    }
}

// Function to traverse the graph
void traverse(Node* graph) {
    if (graph != NULL) {
        printf("%d ", graph->data);
        traverse(graph->next);
    }
}

int main() {
    Node* graph = createGraph(5);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);

    traverse(graph);

    return 0;
}