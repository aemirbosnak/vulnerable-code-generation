//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the graph
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new edge to the graph
void add_edge(struct node* graph, int source, int destination) {
    struct node* new_edge = create_node(destination);
    new_edge->next = graph;
    graph = new_edge;
}

// Function to print the graph
void print_graph(struct node* graph) {
    struct node* current = graph;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create the graph
    struct node* graph = NULL;
    
    // Add edges to the graph
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    
    // Print the graph
    printf("Graph:\n");
    print_graph(graph);
    
    return 0;
}