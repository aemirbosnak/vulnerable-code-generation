//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure for the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the graph structure
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

// Function to create a new graph
Graph* create_graph(int num_nodes) {
    Graph* new_graph = (Graph*) malloc(sizeof(Graph));
    new_graph->nodes = NULL;
    new_graph->num_nodes = num_nodes;
    return new_graph;
}

// Function to add a node to the graph
void add_node(Graph* graph, int data) {
    Node* new_node = create_node(data);
    if (graph->nodes == NULL) {
        graph->nodes = new_node;
    } else {
        Node* temp = graph->nodes;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    graph->num_nodes++;
}

// Function to print the graph
void print_graph(Graph* graph) {
    Node* temp = graph->nodes;
    printf("Graph: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the graph is a tree
bool is_tree(Graph* graph) {
    int count = 0;
    Node* temp = graph->nodes;
    while (temp!= NULL) {
        if (temp->next == NULL) {
            count++;
        }
        temp = temp->next;
    }
    if (count == graph->num_nodes - 1) {
        return true;
    } else {
        return false;
    }
}

// Main function
int main() {
    Graph* graph = create_graph(5);
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);
    add_node(graph, 5);
    print_graph(graph);
    if (is_tree(graph)) {
        printf("The graph is a tree.\n");
    } else {
        printf("The graph is not a tree.\n");
    }
    return 0;
}