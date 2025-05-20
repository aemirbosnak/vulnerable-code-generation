//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct for the graph nodes
struct graph_node {
    int value;
    struct graph_node* next;
};

// Function to initialize the graph
void init_graph(struct graph_node* graph) {
    graph->next = NULL;
}

// Function to insert a node at the end of the linked list
void insert_node(struct graph_node* graph, int value) {
    struct graph_node* new_node = (struct graph_node*)malloc(sizeof(struct graph_node));
    new_node->value = value;
    new_node->next = NULL;

    if (graph->next == NULL) {
        graph->next = new_node;
    } else {
        struct graph_node* current = graph->next;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the linked list
void print_graph(struct graph_node* graph) {
    struct graph_node* current = graph->next;

    printf("Graph representation: \n");
    while (current!= NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL \n");
}

// Main function
int main() {
    // Initialize the graph
    struct graph_node* graph = (struct graph_node*)malloc(sizeof(struct graph_node));
    init_graph(graph);

    // Insert nodes into the graph
    insert_node(graph, 1);
    insert_node(graph, 2);
    insert_node(graph, 3);
    insert_node(graph, 4);
    insert_node(graph, 5);

    // Print the graph representation
    print_graph(graph);

    return 0;
}