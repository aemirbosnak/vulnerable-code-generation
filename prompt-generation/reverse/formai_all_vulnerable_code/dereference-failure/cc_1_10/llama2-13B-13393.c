//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000

// Structure to represent a node in the graph
typedef struct node {
    int label;  // Label of the node
    int degree; // Degree of the node
    struct node* next; // Pointer to the next node in the list
} Node;

// Function to create a new node
Node* new_node(int label) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->label = label;
    node->degree = 0;
    node->next = NULL;
    return node;
}

// Function to add an edge to the graph
void add_edge(Node** graph, int label1, int label2) {
    Node* node1 = graph[label1];
    Node* node2 = graph[label2];
    node1->degree++;
    node2->degree++;
    node1->next = node2;
}

// Function to traverse the graph
void traverse(Node** graph) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[i] != NULL) {
            printf("%d -> ", i);
            traverse(graph[i]->next);
        }
    }
}

int main() {
    // Create a graph with 10 nodes and 50 edges
    Node** graph = (Node**) malloc(MAX_NODES * sizeof(Node*));
    for (int i = 0; i < MAX_NODES; i++) {
        graph[i] = new_node(i);
    }
    for (int i = 0; i < 50; i++) {
        int label1 = i / 2;
        int label2 = i % 2;
        add_edge(graph, label1, label2);
    }
    traverse(graph);
    return 0;
}