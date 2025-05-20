//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct node {
    int data;  // Node data
    struct node* next;  // Next node in the list
} Node;

// Graph type
typedef struct graph {
    Node* nodes;  // List of nodes
    int num_nodes;  // Number of nodes
} Graph;

// Function to create a new graph
Graph* new_graph(void) {
    Graph* g = malloc(sizeof(struct graph));
    g->nodes = NULL;
    g->num_nodes = 0;
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int data) {
    Node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (g->num_nodes == 0) {
        g->nodes = new_node;
    } else {
        g->nodes->next = new_node;
    }
    g->num_nodes++;
}

// Function to remove a node from the graph
void remove_node(Graph* g, int data) {
    Node* current = g->nodes;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                g->nodes = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            g->num_nodes--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to traverse the graph
void traverse(Graph* g) {
    Node* current = g->nodes;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    Graph* g = new_graph();

    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);

    traverse(g);

    remove_node(g, 3);

    traverse(g);

    return 0;
}