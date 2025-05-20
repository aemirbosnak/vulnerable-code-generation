//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Graph structure using adjacency list representation
typedef struct node {
    int label;   // Node label
    struct node* next; // Next node in the list
} Node;

// Function to create a new node
Node* newNode(int label) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->label = label;
    node->next = NULL;
    return node;
}

// Function to add a edge to the graph
void addEdge(Node** graph, int u, int v) {
    Node* nodeU = *(graph + u);
    Node* nodeV = *(graph + v);
    nodeU->next = nodeV;
    nodeV->next = nodeU;
}

// Function to traverse the graph
void traverse(Node* graph) {
    if (graph == NULL) return;
    printf("%d ", graph->label);
    traverse(graph->next);
}

int main() {
    // Create a new graph with 4 nodes
    Node* graph = (Node*) malloc(sizeof(Node) * 4);
    graph[0].label = 1;
    graph[1].label = 2;
    graph[2].label = 3;
    graph[3].label = 4;

    // Add edges to the graph
    addEdge(&graph[0], 1, 2);
    addEdge(&graph[1], 2, 3);
    addEdge(&graph[2], 3, 4);

    // Traverse the graph
    traverse(graph);

    return 0;
}