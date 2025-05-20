//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure using linked lists
struct node {
    int data; // Data stored in the node
    struct node *next; // Next node in the list
};

// Function to create a new node
struct node* new_node(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a graph
struct node* create_graph(int num_vertices) {
    struct node* graph = NULL;
    for (int i = 0; i < num_vertices; i++) {
        graph = new_node(i);
        graph->next = NULL;
    }
    return graph;
}

// Function to traverse the graph
void traverse(struct node* graph) {
    while (graph != NULL) {
        printf("%d ", graph->data);
        graph = graph->next;
    }
    printf("\n");
}

int main() {
    struct node* graph = create_graph(10);

    // Add edges to the graph
    graph->next = new_node(2);
    graph->next->next = new_node(4);
    graph->next->next->next = new_node(6);
    graph->next->next->next->next = new_node(8);

    traverse(graph);

    return 0;
}