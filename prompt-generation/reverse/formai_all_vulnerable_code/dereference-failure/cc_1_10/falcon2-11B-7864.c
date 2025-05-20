//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in the graph
struct node {
    int data;
    int size;
    struct node *next;
};

// Define a structure to represent a graph
struct graph {
    int num_vertices;
    struct node *head;
};

// Function to create a new node with given data and size
struct node* create_node(int data, int size) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->size = size;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the graph
struct node* add_node(struct graph* graph, int data, int size) {
    struct node* new_node = create_node(data, size);
    if (graph->head == NULL) {
        graph->head = new_node;
        return new_node;
    } else {
        struct node* current = graph->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
        return graph->head;
    }
}

// Function to print the graph
void print_graph(struct graph* graph) {
    if (graph->head == NULL) {
        printf("Graph is empty\n");
        return;
    }

    struct node* current = graph->head;
    while (current!= NULL) {
        printf("%d (%d) --> ", current->data, current->size);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a new graph with 3 vertices
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->num_vertices = 3;
    graph->head = NULL;

    // Add three nodes to the graph
    add_node(graph, 1, 3);
    add_node(graph, 2, 4);
    add_node(graph, 3, 5);

    // Print the graph
    print_graph(graph);

    return 0;
}