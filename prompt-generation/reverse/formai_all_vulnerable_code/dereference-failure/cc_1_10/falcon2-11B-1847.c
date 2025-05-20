//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a graph node
typedef struct node {
    int vertex;
    int weight;
    struct node *next;
} node;

// Function to create a new graph node
node *new_node(int vertex, int weight) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->vertex = vertex;
    new_node->weight = weight;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new edge to the graph
void add_edge(node **head, int vertex1, int vertex2, int weight) {
    node *new_edge = new_node(vertex2, weight);
    node *current = *head;
    node *prev = NULL;

    // Find the vertex1 node and add the new edge before it
    while (current!= NULL && current->vertex!= vertex1) {
        prev = current;
        current = current->next;
    }

    new_edge->next = current;
    prev->next = new_edge;
}

// Function to print the graph in protected style
void print_graph(node *head) {
    printf("Protected style graph:\n");

    node *current = head;
    while (current!= NULL) {
        printf("%d (%d) --> ", current->vertex, current->weight);
        current = current->next;
    }

    printf("null\n");
}

int main() {
    // Create the head node for the graph
    node *head = new_node(0, 0);

    // Add edges to the graph
    add_edge(&head, 0, 1, 5);
    add_edge(&head, 0, 2, 3);
    add_edge(&head, 0, 3, 2);
    add_edge(&head, 1, 2, 1);
    add_edge(&head, 1, 3, 2);
    add_edge(&head, 2, 3, 3);

    // Print the graph in protected style
    print_graph(head);

    return 0;
}