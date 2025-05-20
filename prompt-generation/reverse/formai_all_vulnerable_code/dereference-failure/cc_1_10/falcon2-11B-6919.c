//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a graph node
struct graph_node {
    int data;
    struct graph_node* next;
};

// Function to create a new graph node
struct graph_node* create_node(int data) {
    struct graph_node* new_node = (struct graph_node*) malloc(sizeof(struct graph_node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print a graph
void print_graph(struct graph_node* head) {
    struct graph_node* current = head;
    printf("Graph Representation: ");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new graph
    struct graph_node* head = NULL;

    // Add some nodes to the graph
    head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);

    // Print the graph
    print_graph(head);

    // Free the memory allocated for the nodes
    struct graph_node* current = head;
    while (current!= NULL) {
        struct graph_node* temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}