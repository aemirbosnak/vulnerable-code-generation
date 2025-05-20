//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to represent a node in the graph
typedef struct node {
    int data; // data stored in the node
    struct node* next; // pointer to the next node in the list
} node_t;

// Define a function to create a new node with a given data value
node_t* new_node(int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Define a function to add a node to the graph
void add_node(node_t** graph, int data) {
    // Check if the graph is empty
    if (*graph == NULL) {
        *graph = new_node(data);
    } else {
        // Find the last node in the graph and add the new node after it
        node_t* last_node = (*graph)->next;
        (*graph)->next = new_node(data);
        last_node->next = (*graph)->next;
    }
}

// Define a function to traverse the graph and print the data values
void print_graph(node_t* graph) {
    // Traverse the graph and print the data values
    while (graph != NULL) {
        printf("%d ", graph->data);
        graph = graph->next;
    }
    printf("\n");
}

int main() {
    // Create an empty graph
    node_t* graph = NULL;

    // Add some nodes to the graph
    add_node(&graph, 1);
    add_node(&graph, 2);
    add_node(&graph, 3);
    add_node(&graph, 4);
    add_node(&graph, 5);

    // Traverse the graph and print the data values
    print_graph(graph);

    // Free the memory allocated for the graph
    free(graph);

    return 0;
}