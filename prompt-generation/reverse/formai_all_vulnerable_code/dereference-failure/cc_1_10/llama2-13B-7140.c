//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct node {
    int data; // data stored in each node
    struct node* next; // pointer to next node in the graph
} Node;

// Function to create a new graph
Node* new_graph(void) {
    Node* graph = (Node*) malloc(sizeof(Node));
    graph->data = 0;
    graph->next = NULL;
    return graph;
}

// Function to add a node to the graph
void add_node(Node** graph_ptr, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *graph_ptr;
    *graph_ptr = new_node;
}

// Function to traverse the graph
void traverse(Node* graph) {
    while (graph != NULL) {
        printf("%d ", graph->data);
        graph = graph->next;
    }
    printf("\n");
}

int main(void) {
    Node* graph = new_graph();

    // Add nodes to the graph
    add_node(&graph, 1);
    add_node(&graph, 2);
    add_node(&graph, 3);
    add_node(&graph, 4);
    add_node(&graph, 5);

    // Traverse the graph
    traverse(graph);

    return 0;
}