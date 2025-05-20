//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
/*
* This program is an Ada Lovelace style implementation of a data structure visualization
* example in C. It utilizes a linked list to create a visualization of a graph.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for a graph
typedef struct graph {
    Node* nodes;
    int num_nodes;
} Graph;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_node(Graph* graph, int data) {
    Node* new_node = create_node(data);
    if (graph->nodes == NULL) {
        graph->nodes = new_node;
    } else {
        Node* curr_node = graph->nodes;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
    graph->num_nodes++;
}

// Function to print the graph
void print_graph(Graph* graph) {
    Node* curr_node = graph->nodes;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

// Function to free the memory used by the graph
void free_graph(Graph* graph) {
    Node* curr_node = graph->nodes;
    while (curr_node!= NULL) {
        Node* temp_node = curr_node->next;
        free(curr_node);
        curr_node = temp_node;
    }
    graph->nodes = NULL;
    graph->num_nodes = 0;
}

// Main function to demonstrate the usage of the graph data structure
int main() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->nodes = NULL;
    graph->num_nodes = 0;

    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);

    print_graph(graph);

    free_graph(graph);

    return 0;
}