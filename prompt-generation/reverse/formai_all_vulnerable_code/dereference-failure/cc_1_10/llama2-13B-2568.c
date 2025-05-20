//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Graph structure definition
typedef struct node {
    int label; // Node label
    struct node* next; // Next node in the graph
    struct node* prev; // Previous node in the graph
} Node;

// Graph definition
typedef struct graph {
    Node* head; // Head node of the graph
    Node* tail; // Tail node of the graph
    int size; // Number of nodes in the graph
} Graph;

// Function to create a new graph
Graph* new_graph(void) {
    Graph* g = malloc(sizeof(struct graph));
    g->head = NULL;
    g->tail = NULL;
    g->size = 0;
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int label) {
    Node* new_node = malloc(sizeof(struct node));
    new_node->label = label;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (g->head == NULL) {
        g->head = new_node;
        g->tail = new_node;
    } else {
        g->tail->next = new_node;
        new_node->prev = g->tail;
        g->tail = new_node;
    }

    g->size++;
}

// Function to traverse the graph
void traverse(Graph* g) {
    Node* current = g->head;

    while (current != NULL) {
        printf("%d ", current->label);
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