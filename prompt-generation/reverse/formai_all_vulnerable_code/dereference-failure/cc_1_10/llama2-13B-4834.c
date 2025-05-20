//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define GRAPH_MAX_NODES 1000
#define GRAPH_MAX_EDGES 10000

// Structure to represent a node in the graph
struct Node {
    int label; // label of the node
    int degree; // degree of the node
    struct Node *adjacent[GRAPH_MAX_EDGES]; // array of adjacent nodes
};

// Function to create a new node
struct Node* newNode(int label) {
    struct Node* node = malloc(sizeof(struct Node));
    node->label = label;
    node->degree = 0;
    return node;
}

// Function to add an edge to the graph
void addEdge(struct Node** graph, int u, int v) {
    struct Node* u_node = graph[u];
    struct Node* v_node = graph[v];
    u_node->degree++;
    v_node->degree++;
    u_node->adjacent[u_node->degree] = v_node;
    v_node->adjacent[v_node->degree] = u_node;
}

// Function to print the graph
void printGraph(struct Node** graph) {
    for (int i = 0; i < GRAPH_MAX_NODES; i++) {
        struct Node* node = graph[i];
        printf("%d (%d) ", node->label, node->degree);
        for (int j = 0; j < node->degree; j++) {
            struct Node* adjacent = node->adjacent[j];
            printf("%d ", adjacent->label);
        }
        printf("\n");
    }
}

int main() {
    int n = 10; // number of nodes in the graph
    struct Node** graph = malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        graph[i] = newNode(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            addEdge(graph, i, j);
        }
    }
    printGraph(graph);
    return 0;
}