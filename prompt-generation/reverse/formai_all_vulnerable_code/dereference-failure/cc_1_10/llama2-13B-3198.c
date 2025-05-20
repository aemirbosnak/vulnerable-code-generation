//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph node
struct Node {
    int data; // data stored in each node
    struct Node* next; // next node in the list
};

// Function to create a new graph
struct Node* createGraph(int numNodes) {
    struct Node* graph = malloc(numNodes * sizeof(struct Node));
    int i;

    for (i = 0; i < numNodes; i++) {
        graph[i].data = i;
        graph[i].next = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Node** graph, int u, int v) {
    struct Node* nodeU = graph[u];
    struct Node* nodeV = graph[v];

    // If the edge already exists, do nothing
    if (nodeU->next == NULL || nodeV->next == NULL) {
        nodeU->next = nodeV;
        nodeV->next = NULL;
    }
}

// Function to traverse the graph
void traverse(struct Node* graph) {
    struct Node* current = graph;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int numNodes = 6;
    struct Node* graph = createGraph(numNodes);

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 5);

    // Traverse the graph
    traverse(graph);

    return 0;
}