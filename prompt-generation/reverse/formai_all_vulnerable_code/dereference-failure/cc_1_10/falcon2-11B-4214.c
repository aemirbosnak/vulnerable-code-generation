//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the graph structure
typedef struct graph_node {
    int value;
    struct graph_node* next;
} graph_node;

// Define the graph class
typedef struct graph {
    graph_node* head;
} graph;

// Function to create a new graph node
graph_node* create_graph_node(int value) {
    graph_node* new_node = (graph_node*)malloc(sizeof(graph_node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new graph
graph* create_graph() {
    graph* new_graph = (graph*)malloc(sizeof(graph));
    new_graph->head = NULL;
    return new_graph;
}

// Function to add a new node to the graph
void add_node(graph* graph, int value) {
    graph_node* new_node = create_graph_node(value);
    if (graph->head == NULL) {
        graph->head = new_node;
    } else {
        graph_node* current_node = graph->head;
        while (current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to print the graph
void print_graph(graph* graph) {
    if (graph->head == NULL) {
        printf("Graph is empty.\n");
        return;
    }
    graph_node* current_node = graph->head;
    while (current_node!= NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    graph* graph = create_graph();
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);
    add_node(graph, 5);
    print_graph(graph);
    return 0;
}