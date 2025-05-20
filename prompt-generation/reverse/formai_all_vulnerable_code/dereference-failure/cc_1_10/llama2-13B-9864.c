//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a graph node
typedef struct node {
    int data; // data stored in the node
    struct node* next; // pointer to the next node in the list
} Node;

// Definition of a graph
typedef struct graph {
    Node* head; // pointer to the head of the graph
    int num_nodes; // number of nodes in the graph
} Graph;

// Function to create a new graph
Graph* new_graph(void) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->head = NULL;
    g->num_nodes = 0;
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (g->head == NULL) {
        g->head = new_node;
    } else {
        g->head->next = new_node;
    }
    g->num_nodes++;
}

// Function to traverse the graph
void traverse(Graph* g) {
    Node* current = g->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
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
    add_node(g, 5);
    traverse(g);
    return 0;
}