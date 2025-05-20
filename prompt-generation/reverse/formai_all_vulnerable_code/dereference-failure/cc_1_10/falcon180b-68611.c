//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node to the graph
void add_node(Node** graph, int data) {
    Node* new_node = create_node(data);
    if (*graph == NULL) {
        *graph = new_node;
        return;
    }
    Node* current_node = *graph;
    while (current_node->next!= NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Function to search for a node in the graph
Node* search_node(Node* graph, int data) {
    Node* current_node = graph;
    while (current_node!= NULL) {
        if (current_node->data == data) {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// Function to delete a node from the graph
void delete_node(Node** graph, int data) {
    Node* current_node = *graph;
    Node* prev_node = NULL;
    while (current_node!= NULL && current_node->data!= data) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return;
    }
    if (prev_node == NULL) {
        *graph = current_node->next;
    } else {
        prev_node->next = current_node->next;
    }
    free(current_node);
}

// Function to traverse the graph in depth-first order
void depth_first_search(Node* graph) {
    Node* current_node = graph;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to traverse the graph in breadth-first order
void breadth_first_search(Node* graph) {
    Node* current_node = graph;
    Node* next_node = NULL;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        next_node = current_node->next;
        current_node = next_node;
    }
    printf("\n");
}

int main() {
    // Create a new graph
    Node* graph = NULL;

    // Add nodes to the graph
    add_node(&graph, 1);
    add_node(&graph, 2);
    add_node(&graph, 3);
    add_node(&graph, 4);
    add_node(&graph, 5);

    // Search for a node in the graph
    Node* node = search_node(graph, 3);
    if (node!= NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the graph
    delete_node(&graph, 3);

    // Traverse the graph in depth-first order
    printf("Depth-first search:\n");
    depth_first_search(graph);

    // Traverse the graph in breadth-first order
    printf("Breadth-first search:\n");
    breadth_first_search(graph);

    return 0;
}